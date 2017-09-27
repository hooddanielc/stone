#pragma once

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <fstream>
#include "symbol.h"
#include "state.h"
#include "action.h"
#include "codegen/generate_tokens_h.h"
#include "codegen/generate_ast_base_h.h"
#include "codegen/generate_reduction_h.h"
#include "codegen/generate_symbols_h.h"
#include "codegen/generate_actions_h.h"
#include "codegen/generate_driver_h.h"

namespace biglr {

class parser_t {

public:

  using goto_map_t = std::unordered_map<std::shared_ptr<symbol_t>, std::shared_ptr<state_t>>;

  using goto_table_t = std::unordered_map<std::shared_ptr<state_t>, goto_map_t>;

  using action_map_t = std::unordered_map<std::shared_ptr<symbol_t>, std::shared_ptr<action_t>>;

  using action_table_t = std::unordered_map<std::shared_ptr<state_t>, action_map_t>;

  using state_list_t = std::vector<std::shared_ptr<state_t>>;

  using tokens_list_t = std::vector<std::shared_ptr<token_t>>;

  using reductions_list_t = std::vector<std::shared_ptr<reduction_t>>;

  using rules_list_t = std::vector<std::shared_ptr<rule_t>>;

  using symbol_key_t = std::shared_ptr<symbol_t>;

  static std::shared_ptr<parser_t> make(
    state_list_t states,
    goto_table_t goto_table,
    tokens_list_t tokens,
    reductions_list_t reductions,
    rules_list_t rules,
    std::unordered_map<symbol_key_t, rules_list_t> by_lhs
  ) {
    auto parser = new parser_t(states, goto_table, tokens, reductions, rules, by_lhs);
    std::shared_ptr<parser_t> ptr(parser);
    return ptr;
  }

  state_list_t get_states() const {
    return states;
  }

  tokens_list_t get_tokens() const {
    auto omega = static_cast<std::shared_ptr<symbol_t>>(top_t::make());
    auto break_ = static_cast<std::shared_ptr<symbol_t>>(break_t::make());
    auto epsilon = static_cast<std::shared_ptr<symbol_t>>(epsilon_t::make());
    std::vector<std::shared_ptr<token_t>> result;
    for (auto token: tokens) {
      auto casted = static_cast<std::shared_ptr<symbol_t>>(token);
      if (token != omega && token != break_ && token != epsilon) {
        result.push_back(token);
      }
    }
    return result;
  }

  reductions_list_t get_reductions() const {
    return reductions;
  }

  rules_list_t get_rules() const {
    return rules;
  }

  std::unordered_map<symbol_key_t, rules_list_t> get_rules_by_lhs() const {
    std::unordered_map<symbol_key_t, rules_list_t> sorted_map;
    auto reductions = get_reductions();
    auto rules = get_rules();
    for (auto rule: rules) {
      sorted_map[rule->get_lhs()].push_back(rule);
    }
    return sorted_map;
  }

  nlohmann::json get_tokens_json() {
    nlohmann::json j;
    for (auto t: tokens) {
      j[t->get_name()]["id"] = t->get_id();
      j[t->get_name()]["terminal"] = true;
    }
    return j;
  }

  nlohmann::json get_reductions_json() {
    nlohmann::json j;
    for (auto t: reductions) {
      j[t->get_name()]["id"] = t->get_id();
      j[t->get_name()]["terminal"] = false;
    }
    return j;
  }

  nlohmann::json get_rules_json() {
    nlohmann::json j;
    for (auto r: rules) {
      nlohmann::json rule_item;
      rule_item["id"] = r->get_id();
      rule_item["lhs"] = r->get_lhs()->get_name();
      for (auto rhs: r->get_rhs()) {
        rule_item["rhs"].push_back(rhs->get_name());
      }
      j.push_back(rule_item);
    }
    return j;
  }

  nlohmann::json get_actions_json() {
    nlohmann::json result;

    for (auto state: states) {
      nlohmann::json row;
      row["state"] = state->get_id();
      for (auto t: tokens) {
        if (actions[state][t]->is_blank()) continue;
        row["actions"][t->get_name()] = actions[state][t]->to_json();
      }
      for (auto r: reductions) {
        if (actions[state][r]->is_blank()) continue;
        row["transition"][r->get_name()] = actions[state][r]->to_json();
      }
      result.push_back(row);
    }

    return result;
  }

  nlohmann::json get_code_gen_json() {
    nlohmann::json json;
    json["ast.h"] = get_ast_base_h();
    json["driver.h"] = get_driver_h();
    json["parser_table.h"] = get_actions_h();
    json["symbol.h"] = get_symbols_h();
    json["token.h"] = get_tokens_h();

    for (const auto &r: get_reductions()) {
      json["reductions/" + r->get_name() + ".h"] = get_reduction_h(r);
    }

    json["reductions/" + top_t::make()->get_name() + ".h"] = get_reduction_h(top_t::make());

    return json;
  }

  nlohmann::json to_json() {
    nlohmann::json j;
    j["tokens"] = get_tokens_json();
    j["reductions"] = get_reductions_json();
    j["rules"] = get_rules_json();
    j["actions"] = get_actions_json();
    j["dot"] = to_dot();
    j["cpp"] = get_code_gen_json();
    return j;
  }

  std::shared_ptr<rule_t> get_omega_rule() {
    auto omega = top_t::make();
    for (auto rule: rules) {
      if (rule->get_lhs() == omega) {
        return rule;
      }
    }
    throw std::runtime_error("/top rule not found");
  }

  std::string to_dot() {
    auto omega_rule = get_omega_rule();
    std::stringstream ss;
    ss << "digraph {" << std::endl;
    ss << "  label=<<i>Diagram of State Machine</i>>" << std::endl;
    for (auto rule: rules) {
      // for each rule, create a diamond shape
      auto id = rule->get_id();
      auto name = rule->get_lhs()->get_name();
      auto rhs_size = rule->get_rhs().size();
      if (name == "TOP") {
        name = "&Omega;";
      }
      ss << "  r" << id << " [shape=diamond, label=<r" << id << " (" << name << ", "<< rhs_size << ")>];" << std::endl;
    }
    for (auto state: states) {
      // for each state create a cirlce
      auto id = state->get_id();
      ss << "  s" << id << " [shape=circle, label=<s" << id << ">];" << std::endl;
    }
    for (auto state: states) {
      auto id = state->get_id();
      for (auto token: tokens) {
        auto action = actions[state][token];
        switch (action->get_kind()) {
          case action_t::kind_t::blank:
            break;
          case action_t::kind_t::shift:
            ss << "  s" << id << " -> " << action->get_ref() << " "
               << "[label=<&laquo;" << token->get_name() << "&raquo;>];" << std::endl;
            break;
          case action_t::kind_t::restart:
            ss << "  r" << omega_rule->get_id() << " -> s" << id << " "
               << "[label=<&laquo;" << token->get_name() << "&raquo;>, arrowhead=inv];" << std::endl;
            break;
          case action_t::kind_t::reduce:
            ss << "  " << action->get_ref() << " -> s" << id  << " "
               << "[label=<&laquo;" << token->get_name() << "&raquo;>, arrowhead=inv];" << std::endl;
            break;
        }
      }
      for (auto reduction: reductions) {
        if (auto next_state = goto_table[state][reduction]) {
          ss << "  s" << id << " -> s" << next_state->get_id() << " "
             << "[label=<" << reduction->get_name() << ">, style=dotted];" << std::endl;
        }
      }
    }
    ss << "}" << std::endl;
    return ss.str();
  }

  std::string get_actions_h() {
    auto tokens = get_tokens();
    tokens.push_back(break_t::make());
    return generate_actions_h(states, tokens, get_reductions(), actions);
  }

  std::string get_tokens_h() {
    return generate_tokens_h(tokens);
  }

  std::string get_ast_base_h() {
    return generate_ast_base_h(get_reductions(), get_rules_by_lhs());
  }

  std::string get_symbols_h() {
    std::vector<std::shared_ptr<symbol_t>> symbols;
    symbols.push_back(top_t::make());
    symbols.push_back(break_t::make());
    for (auto s: tokens) {
      if (s != break_t::make()) {
        symbols.push_back(s);
      }
    }
    for (auto s: reductions) {
      symbols.push_back(s);
    }
    return generate_symbols_h(symbols);
  }

  std::string get_driver_h() {
    return generate_driver_h(get_rules());
  }

  std::string get_reduction_h(std::shared_ptr<reduction_t> reduction) {
    std::vector<std::shared_ptr<rule_t>> rule_group;
    for (auto rule: by_lhs[reduction]) {
      rule_group.push_back(rule);
    }

    return generate_reduction_h(rule_group);
  }

  std::string get_all_reductions_h() {
    std::stringstream ss;

    std::sort(reductions.begin(), reductions.end(), [](auto a, auto b) {
      return a->get_id() < b->get_id();
    });

    for (auto reduction: reductions) {
      ss << get_reduction_h(reduction) << std::endl;
    }
    ss << get_reduction_h(top_t::make()) << std::endl;
    return ss.str();
  }

  void write_html(const std::string &path, const std::string &js_path = "react-report.js") {
    std::ofstream file;
    file.open(path);
    file <<
      R"(
        <!doctype html>
        <html>
          <head>
            <title>Grammar</title>
          </head>
          <body>
            <script id="json" type="application/json">
              )" << to_json() << R"(
            </script>
            <script src=")" << js_path<< R"(" type="text/javascript"></script>
          </body>
        </html>
      )";
    file.close();
  }

  void write_dot(const std::string &path) {
    std::ofstream file;
    file.open(path);
    file << to_dot();
    file.close();
  }

  void write_json(const std::string &path) {
    std::ofstream file;
    file.open(path);
    file << to_json();
    file.close();
  }

  void write_cpp(const std::string &path, const std::string &namespace_name = "biglr") {
    std::ofstream fs;
    fs.open(path);
    fs << "#pragma once" << std::endl;
    fs << std::endl;
    fs << "#include <string>" << std::endl;
    fs << "#include <vector>" << std::endl;
    fs << "#include <memory>" << std::endl;
    fs << "#include <iostream>" << std::endl;
    fs << "#include <cassert>" << std::endl;
    fs << "#include <utility>" << std::endl;
    fs << "#include <unordered_map>" << std::endl;
    fs << "#include <functional>" << std::endl;
    fs << std::endl;
    fs << "namespace " << namespace_name << " {" << std::endl;
    fs << std::endl;
    fs << get_symbols_h();
    fs << get_tokens_h();
    fs << get_ast_base_h();
    fs << get_all_reductions_h();
    fs << get_actions_h();
    fs << get_driver_h();
    fs << std::endl;
    fs << "}   // " << namespace_name << std::endl;
    fs.close();
  }

protected:

  state_list_t states;

  goto_table_t goto_table;

  std::vector<std::shared_ptr<token_t>> tokens;

  std::vector<std::shared_ptr<reduction_t>> reductions;

  std::vector<std::shared_ptr<rule_t>> rules;

  std::unordered_map<symbol_key_t, rules_list_t> by_lhs;

  action_table_t actions;

  action_table_t construct_actions() {
    auto omega = top_t::make();
    action_table_t tmp;

    for (auto state: states) {
      auto row = tmp[state];
      // Compute actions for tokens
      for (auto item: state->get_items()) {
        auto rule = item->get_rule();

        if (item->is_complete()) {
          auto symbol = item->get_peek();
          if (rule->get_lhs() == omega) {
            row[symbol] = std::make_shared<restart_action_t>(symbol);
          } else {
            row[symbol] = std::make_shared<reduce_action_t>(symbol, item->get_rule());
          }
        } else {
          auto symbol = item->get_corner();
          if (symbol->is_token()) {
            if (auto next_state = goto_table[state][symbol]) {
              row[symbol] = std::make_shared<shift_action_t>(symbol, next_state);
            }
          }
        }
      }
      // Compute actions for reductions
      for (auto reduction: reductions) {
        if (auto next_state = goto_table[state][reduction]) {
          row[reduction] = std::make_shared<shift_action_t>(reduction, next_state);
        } else {
          row[reduction] = std::make_shared<action_t>(reduction);
        }
      }
      // Fill in blanks
      for (auto symbol: tokens) {
        if (!row[symbol]) {
          row[symbol] = std::make_shared<action_t>(symbol);
        }
      }
      tmp[state] = row;
    }
    return tmp;
  }

  parser_t(
    state_list_t states_,
    goto_table_t goto_table_,
    tokens_list_t tokens_,
    reductions_list_t reductions_,
    rules_list_t rules_,
    std::unordered_map<symbol_key_t, rules_list_t> by_lhs_
  ): states(states_),
     goto_table(goto_table_),
     tokens(tokens_),
     reductions(reductions_),
     rules(rules_),
     by_lhs(by_lhs_),
     actions(construct_actions()) {}
};  // parser_t

std::ostream &operator<<(std::ostream &strm, const parser_t &parser) {
  strm << "Parser(" << std::endl <<
    "  Tokens: " << parser.get_tokens().size() << std::endl <<
    "  Reductions: " << parser.get_reductions().size() << std::endl <<
    "  Rules: " << parser.get_rules().size() << std::endl <<
    "  States: " << parser.get_states().size() << std::endl <<
    ")";
  return strm;
}

std::ostream &operator<<(std::ostream &strm, const parser_t *parser) {
  strm << *parser;
  return strm;
}

}   // biglr