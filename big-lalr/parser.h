#pragma once

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include "symbol.h"
#include "state.h"

namespace biglr {

struct action_t {

  std::shared_ptr<symbol_t> symbol;

  action_t(std::shared_ptr<symbol_t> symbol_): symbol(symbol_) {}

  action_t() = default;

  virtual bool is_blank() const { return true; }

  virtual std::string get_label() const {
    return "";
  }

  virtual nlohmann::json to_json() const {
    nlohmann::json j;
    j["label"] = get_label();
    j["type"] = "blank";
    return j;
  }

};

struct restart_action_t: public action_t {

  restart_action_t(std::shared_ptr<symbol_t> symbol_): action_t(symbol_) {}

  virtual bool is_blank() const override { return false; }

  virtual std::string get_label() const override {
    return "\u21BA";
  }

  virtual nlohmann::json to_json() const override {
    nlohmann::json j;
    j["label"] = get_label();
    j["type"] = "restart";
    return j;
  }

};

struct shift_action_t: public action_t {

  std::shared_ptr<state_t> state;

  shift_action_t(
    std::shared_ptr<symbol_t> symbol_,
    std::shared_ptr<state_t> state_
  ): action_t(symbol_), state(state_) {}

  virtual bool is_blank() const override { return false; }

  virtual std::string get_label() const override {
    std::stringstream ss;
    ss << "s" << state->get_id();
    return ss.str();
  }

  virtual nlohmann::json to_json() const override {
    nlohmann::json j;
    j["label"] = get_label();
    j["type"] = "shift";
    j["state"] = state->get_id();
    return j;
  }

};

struct reduce_action_t: public action_t {

  std::shared_ptr<rule_t> rule;

  reduce_action_t(
    std::shared_ptr<symbol_t> symbol_,
    std::shared_ptr<rule_t> rule_
  ): action_t(symbol_), rule(rule_) {}

  virtual bool is_blank() const override { return false; }

  virtual std::string get_label() const override {
    std::stringstream ss;
    ss << "r" << rule->get_id();
    return ss.str();
  }

  virtual nlohmann::json to_json() const override {
    nlohmann::json j;
    j["label"] = get_label();
    j["type"] = "reduce";
    j["rule"] = rule->get_id();
    return j;
  }

};

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

  static std::shared_ptr<parser_t> make(
    state_list_t states,
    goto_table_t goto_table,
    tokens_list_t tokens,
    reductions_list_t reductions,
    rules_list_t rules
  ) {
    auto parser = new parser_t(states, goto_table, tokens, reductions, rules);
    std::shared_ptr<parser_t> ptr(parser);
    return ptr;
  }

  state_list_t get_states() const {
    return states;
  }

  tokens_list_t get_tokens() const {
    return tokens;
  }

  reductions_list_t get_reductions() const {
    return reductions;
  }

  rules_list_t get_rules() const {
    return rules;
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
    std::sort(rules.begin(), rules.end(), [](auto a, auto b) { return a->get_id() < b->get_id(); });
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
    std::sort(states.begin(), states.end(), [](auto a, auto b) {
      return a->get_id() < b->get_id();
    });

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

  nlohmann::json to_json() {
    nlohmann::json j;
    j["tokens"] = get_tokens_json();
    j["reductions"] = get_reductions_json();
    j["rules"] = get_rules_json();
    j["actions"] = get_actions_json();
    return j;
  }

  void write_html(const std::string &path) {
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
            <script src="react-report.js" type="text/javascript"></script>
          </body>
        </html>
      )";
    file.close();
  }

  void write_json(const std::string &path) {
    std::ofstream file;
    file.open(path);
    file << to_json();
    file.close();
  }

protected:

  state_list_t states;

  goto_table_t goto_table;

  std::vector<std::shared_ptr<token_t>> tokens;

  std::vector<std::shared_ptr<reduction_t>> reductions;

  std::vector<std::shared_ptr<rule_t>> rules;

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
    rules_list_t rules_
  ): states(states_),
     goto_table(goto_table_),
     tokens(tokens_),
     reductions(reductions_),
     rules(rules_),
     actions(construct_actions()) {};

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