#pragma once

#include <iostream>
#include <algorithm>
#include <utility>
#include "util.h"
#include "rule.h"
#include "symbol.h"
#include "lexer.h"

namespace biglr {

class grammar_t {

public:

  static std::shared_ptr<grammar_t> make(const char *grammar_src) {
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

  void print() {
    for (auto token: tokens) {
      std::cout << token << std::endl;
    }

    for (auto reduction: reductions) {
      std::cout << reduction << std::endl;
    }

    for (auto rule: rules) {
      std::cout << *rule << std::endl;
    }
  }

  first_set_t get_first_set(std::shared_ptr<symbol_t> symbol) {
    if (first_sets.find(symbol) == first_sets.end()) {
      if (symbol == break_) {
        first_sets[symbol] = {};
      } else if (symbol->is_token()) {
        first_sets[symbol] = { symbol };
      } else if (symbol->is_reduction()) {
        first_set_t result;
        for (auto rule: by_lhs[symbol]) {
          for (auto rhs_symbol: rule->get_rhs()) {
            auto first = get_first_set(rhs_symbol);

            for (auto first_symbol: first) {
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
    }
    return first_sets[symbol];
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

  /* A map where values are lists of rules that share
   * the same left-hand side */
  std::unordered_map<symbol_key_t, rule_list_t> by_lhs;

  /* A map where values are lists of pairs (rule, dot)
   * showing all occurences of a symbol found on the right-hand side
   * of a rule. */
  std::unordered_map<symbol_key_t, symbol_occurence_t> by_rhs;

  std::vector<std::shared_ptr<reduction_t>> filter_empties() {
    std::vector<std::shared_ptr<reduction_t>> result;
    std::unordered_map<std::string, std::shared_ptr<reduction_t>> taboo;
    for (auto rule: rules) {
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
    for (auto rule: rules) {
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
    for (auto rule: rules) {
      result[rule->get_lhs()].push_back(rule);
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
        by_lhs(populate_by_lhs()) {
    std::sort(tokens.begin(), tokens.end(), [](auto a, auto b) { return *a < *b;});
    std::sort(reductions.begin(), reductions.end(), [](auto a, auto b) { return *a < *b;});
    std::sort(rules.begin(), rules.end(), [](auto a, auto b) { return *a < *b;});
  }

};  // grammar_t

}   // biglr
