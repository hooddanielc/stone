#pragma once

#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include "util.h"
#include "rule.h"
#include "item.h"
#include "symbol.h"
#include "lexer.h"
#include "state.h"
#include "parser.h"

namespace biglr {

class grammar_t {

public:

  static std::shared_ptr<grammar_t> make(const char *grammar_src) {
    // clear stores
    auto lexer = lexer_t::make(grammar_src);
    auto grammar = new grammar_t(
      lexer->get_tokens(),
      lexer->get_reductions(),
      lexer->get_rules()
    );
    std::shared_ptr<grammar_t> ptr(grammar);
    return ptr;
  }

  static std::shared_ptr<grammar_t> from_file(const std::string &path) {
    // clear stores
    token_t::clear_store();
    reduction_t::clear_store();
    item_t::clear_store();
    state_t::clear_store();
    symbol_t::clear();
    break_t::clear_store();
    epsilon_t::clear_store();
    top_t::clear_store();
    rule_t::clear_store();

    auto str = get_file_contents(path);
    return make(str.c_str());
  }

  std::vector<std::shared_ptr<token_t>> get_tokens() { return tokens; }

  std::vector<std::shared_ptr<reduction_t>> get_reductions() { return reductions; }

  std::vector<std::shared_ptr<rule_t>> get_rules() { return rules; }

  std::vector<std::shared_ptr<reduction_t>> get_empties() { return empties; }

  using rule_list_t = std::vector<std::shared_ptr<rule_t>>;

  using symbol_key_t = std::shared_ptr<symbol_t>;

  using first_set_t = std::vector<std::shared_ptr<symbol_t>>;

  using symbol_occurence_t = std::pair<std::shared_ptr<rule_t>, int>;

  using by_rhs_list_t = std::vector<symbol_occurence_t>;

  using by_rhs_t = std::unordered_map<symbol_key_t, by_rhs_list_t>;

  using goto_map_t = std::unordered_map<std::shared_ptr<symbol_t>, std::shared_ptr<state_t>>;

  void print() {
    for (const auto &token: tokens) {
      std::cout << token << std::endl;
    }

    for (const auto &reduction: reductions) {
      std::cout << reduction << std::endl;
    }

    for (const auto &rule: rules) {
      std::cout << *rule << std::endl;
    }
  }

  first_set_t get_first_sequence(const first_set_t &set) {
    if (first_sequences.find(set) == first_sequences.end()) {
      first_set_t result;
      for (const auto &symbol: set) {
        auto first_set = get_first_set(symbol);
        bool found_epsilon = false;
        for (const auto &first_symbol: first_set) {
          if (first_symbol == epsilon) {
            found_epsilon = true;
          } else if (std::find(result.begin(), result.end(), first_symbol) == result.end()) {
            result.push_back(first_symbol);
          }
        }
        if (!found_epsilon) {
          break;
        }
      }
      first_sequences[set] = result;
    }
    return first_sequences[set];
  }

  first_set_t get_first_set(const std::shared_ptr<symbol_t> &symbol) {
    if (first_sets.find(symbol) == first_sets.end()) {
      std::vector<std::shared_ptr<symbol_t>> taboo;
      return get_first_set(symbol, taboo);
    }
    return first_sets[symbol];
  }

  first_set_t get_first_set(const std::shared_ptr<symbol_t> &symbol, std::vector<std::shared_ptr<symbol_t>> &taboo) {
    if (std::find(taboo.begin(), taboo.end(), symbol) != taboo.end()) {
      return {};
    }
    taboo.push_back(symbol);
    if (symbol == break_) {
      first_sets[symbol] = {};
    } else if (symbol->is_token()) {
      first_sets[symbol] = { symbol };
    } else if (symbol->is_reduction()) {
      first_set_t result;
      for (const auto &rule: by_lhs[symbol]) {
        for (const auto &rhs_symbol: rule->get_rhs()) {
          auto first = get_first_set(rhs_symbol, taboo);

          for (const auto &first_symbol: first) {
            if (std::find(result.begin(), result.end(), first_symbol) == result.end()) {
              result.push_back(first_symbol);
            }
          }
          if (std::find(empties.begin(), empties.end(), rhs_symbol) == empties.end()) {
            break;
          }
        }
        if (!rule->get_rhs().size()) {
          // this rule produces the symbol for free. It's first-set will
          // therefore contain epsilon
          result.push_back(epsilon);
        }
      }
      first_sets[symbol] = result;
    } else {
      throw std::runtime_error("don't know how to get first set");
    }
    return first_sets[symbol];
  }

  first_set_t get_follow_set(const std::shared_ptr<symbol_t> &symbol) {
    if (follow_sets.find(symbol) == follow_sets.end()) {
      std::vector<std::shared_ptr<symbol_t>> taboo;
      return get_follow_set(symbol, taboo);
    }
    return follow_sets[symbol];
  }

  first_set_t get_follow_set(const std::shared_ptr<symbol_t> &symbol, std::vector<std::shared_ptr<symbol_t>> &taboo) {
    if (std::find(taboo.begin(), taboo.end(), symbol) != taboo.end()) {
      return {};
    }
    taboo.push_back(symbol);
    first_set_t result;
    if (symbol == omega) {
      result.push_back(break_);
      return result;
    } else {
      for (const auto &occurence: by_rhs[symbol]) {
        bool chain = false;
        auto beta = std::get<0>(occurence)->get_beta(std::get<1>(occurence));
        if (beta.size()) {
          auto first_set = get_first_sequence(beta);
          for (const auto &first_symbol: first_set) {
            if (first_symbol == epsilon) {
              chain = true;
            } else {
              if (std::find(result.begin(), result.end(), first_symbol) == result.end()) {
                result.push_back(first_symbol);
              }
            }
          }
        } else {
          chain = true;
        }
        if (chain) {
          auto follow_set = get_follow_set(std::get<0>(occurence)->get_lhs(), taboo);
          for (const auto &follow_symbol: follow_set) {
            if (std::find(result.begin(), result.end(), follow_symbol) == result.end()) {
              result.push_back(follow_symbol);
            }
          }
        }
      }
      follow_sets[symbol] = result;
      return result;
    }
  }

  std::vector<std::shared_ptr<item_t>> get_start_items() {
    std::vector<std::shared_ptr<item_t>> result;
    auto follow_set = get_follow_set(omega);
    auto r0 = by_lhs[omega][0];

    for (const auto &symbol: follow_set) {
      result.push_back(item_t::make(r0, 0, symbol));
    }

    return result;
  }

  std::shared_ptr<state_t> get_closure(std::vector<std::shared_ptr<item_t>> items) {
    std::vector<std::shared_ptr<item_t>> done;

    while(items.size()) {
      auto item = items.back();
      items.pop_back();
      if (std::find(done.begin(), done.end(), item) != done.end()) {
        continue;
      }
      done.push_back(item);
      if (item->is_complete()) {
        continue;
      }
      auto first_sequence = item->get_beta();
      first_sequence.push_back(item->get_peek());
      auto peeks = get_first_sequence(first_sequence);
      peeks.push_back(break_);
      for (const auto &peek: peeks) {
        for (const auto &rule: by_lhs[item->get_corner()]) {
          items.push_back(item_t::make(rule, 0, peek));
        }
      }
    }

    return state_t::make(done);
  }

  std::shared_ptr<state_t> get_goto(const std::shared_ptr<state_t> &state, const std::shared_ptr<symbol_t> &symbol) {
    if (action_table.find(state) != action_table.end()) {
      if (action_table[state].find(symbol) != action_table[state].end()) {
        return action_table[state][symbol];
      }
    }

    std::vector<std::shared_ptr<item_t>> items;

    for (const auto &item: state->get_items()) {
      if (item->get_corner() == symbol) {
        if (auto next_item = item->get_next()) {
          items.push_back(next_item);
        }
      }
    }

    if (items.size()) {
      action_table[state][symbol] = get_closure(items);
      return action_table[state][symbol];
    }

    std::shared_ptr<state_t> empty;
    action_table[state][symbol] = empty;
    return empty;
  }

  using state_list_t = std::vector<std::shared_ptr<state_t>>;

  using progress_cb_t = std::function<void(size_t, size_t)>;

  void reset_symbol_ids() {
    // tokens and reductions should be numbered from 0 - n
    int next_id = 0;
    break_t::make()->set_id(next_id++);
    for (std::shared_ptr<symbol_t> token: tokens) {
      if (token != break_t::make() && token != top_t::make() && token != epsilon_t::make()) {
        token->set_id(next_id++);
      }
    }
    for (auto reduction: reductions) {
      reduction->set_id(next_id++);
    }
    top_t::make()->set_id(next_id++);
    epsilon_t::make()->set_id(next_id++);
  }

  void reset_state_ids(state_list_t &states) {
    // states should be numbered from 0 - n
    std::sort(states.begin(), states.end(), [](auto a, auto b) {
      return a->get_id() < b->get_id();
    });

    int next_id = 0;
    for (auto state: states) {
      state->set_id(next_id++);
    }
  }

  std::shared_ptr<parser_t> get_full_parse_table(const progress_cb_t &cb = [](size_t, size_t){}) {
    std::vector<std::shared_ptr<symbol_t>> action_symbols;
    action_symbols.insert(action_symbols.end(), tokens.begin(), tokens.end());
    action_symbols.insert(action_symbols.end(), reductions.begin(), reductions.end());

    auto start_items = get_start_items();
    auto first_todo = get_closure(start_items);
    state_list_t todo = { first_todo };
    state_list_t done;

    while(todo.size()) {
      cb(todo.size(), done.size());
      auto state = todo.back();
      todo.pop_back();
      if (std::find(done.begin(), done.end(), state) != done.end()) {
        continue;
      }
      done.push_back(state);
      for (const auto &symbol: action_symbols) {
        if (auto goto_for_symbol = get_goto(state, symbol)) {
          todo.push_back(goto_for_symbol);
        }
      }
    }
    reset_symbol_ids();
    reset_state_ids(done);

    // sort rules
    std::sort(rules.begin(), rules.end(), [](auto a, auto b) {
      return a->get_id() < b->get_id();
    });

    return parser_t::make(done, action_table, tokens, reductions, rules, by_lhs);
  }

private:

  std::vector<std::shared_ptr<token_t>> tokens;

  std::vector<std::shared_ptr<reduction_t>> reductions;

  std::vector<std::shared_ptr<rule_t>> rules;

  std::vector<std::shared_ptr<reduction_t>> empties;

  std::shared_ptr<top_t> omega;

  std::shared_ptr<symbol_t> break_;

  std::shared_ptr<symbol_t> epsilon;

  std::unordered_map<symbol_key_t, first_set_t> first_sets;

  std::unordered_map<std::shared_ptr<state_t>, goto_map_t> action_table;

  struct first_set_key_t : public std::unary_function<first_set_t, std::size_t> {
    std::size_t operator()(const first_set_t &k) const {
      std::hash<std::shared_ptr<symbol_t>> hash_symbol;
      size_t result = 0;
      for (const auto &symbol: k) {
        result ^= hash_symbol(symbol);
      }
      return result;
    }
  };

  std::unordered_map<first_set_t, first_set_t, first_set_key_t> first_sequences;

  std::unordered_map<symbol_key_t, first_set_t> follow_sets;

  /* A map where values are lists of rules that share
   * the same left-hand side */
  std::unordered_map<symbol_key_t, rule_list_t> by_lhs;

  /* A map where values are lists of pairs (rule, dot)
   * showing all occurences of a symbol found on the right-hand side
   * of a rule. */
  by_rhs_t by_rhs;

  std::vector<std::shared_ptr<reduction_t>> filter_empties() {
    std::vector<std::shared_ptr<reduction_t>> result;
    std::unordered_map<std::string, std::shared_ptr<reduction_t>> taboo;
    for (const auto &rule: rules) {
      if (!rule->get_rhs().size() && !taboo.count(rule->get_lhs()->get_name())) {
        auto lhs = rule->get_lhs();
        result.push_back(lhs);
        taboo[lhs->get_name()] = lhs;
      }
    }
    return result;
  }

  std::shared_ptr<top_t> get_omega() {
    std::shared_ptr<reduction_t> top;
    std::shared_ptr<top_t> cached = top_t::make();
    for (const auto &rule: rules) {
      if (top && rule->get_lhs() == cached) {
        throw std::runtime_error("Only one rule can use /top reduction");
      }
      if (rule->get_lhs() == cached) {
        top = rule->get_lhs();
      }
    }
    if (!top) {
      throw std::runtime_error("Omega /top rule is required");
    }
    return cached;
  }

  std::unordered_map<symbol_key_t, rule_list_t> populate_by_lhs() {
    std::unordered_map<symbol_key_t, rule_list_t> result;
    for (const auto &rule: rules) {
      result[rule->get_lhs()].push_back(rule);
    }
    return result;
  }

  by_rhs_t populate_by_rhs() {
    by_rhs_t result;
    for (const auto &rule: rules) {
      int i = 0;
      for (const auto &rhs_symbol: rule->get_rhs()) {
        result[rhs_symbol].emplace_back(rule, i++);
      }
    }
    return result;
  }

  grammar_t(
    std::vector<std::shared_ptr<token_t>> tokens_,
    std::vector<std::shared_ptr<reduction_t>> reductions_,
    std::vector<std::shared_ptr<rule_t>> rules_
  ):    tokens(tokens_),
        reductions(reductions_),
        rules(rules_),
        empties(filter_empties()),
        omega(get_omega()),
        break_(break_t::make()),
        epsilon(epsilon_t::make()),
        by_lhs(populate_by_lhs()),
        by_rhs(populate_by_rhs()) {
  }

};  // grammar_t

}   // biglr
