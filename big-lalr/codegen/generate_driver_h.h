#pragma once

#include <sstream>
#include <memory>
#include <map>
#include "../symbol.h"
#include "../action.h"

namespace biglr {

inline std::string generate_driver_h(std::vector<std::shared_ptr<rule_t>> rules) {
  std::stringstream ss;

  ss << R"(

std::vector<std::shared_ptr<ast_t>> pop_children(int len, std::vector<std::shared_ptr<ast_t>> &stack) {
  assert(stack.size() >= len);
  std::vector<std::shared_ptr<ast_t>> children;
  for (int i = 0; i < len; ++i) {
    children.push_back(stack.back());
    stack.pop_back();
  }
  return children;
}

std::shared_ptr<ast_t> reduce_by_id(int id, std::vector<std::shared_ptr<ast_t>> &stack) {
  std::vector<symbol_t> symbol_pattern;
  switch (id) {
)";

  for (auto rule: rules) {
    size_t size = rule->get_rhs().size();
    auto id = rule->get_cpp_identifier();
    ss << "  case " << rule->get_id() << ":" << std::endl;
    ss << "    return " << id << "_t::make(pop_children(" << size << ", stack));" << std::endl;
  }

ss << R"(
  } // switch
  throw std::runtime_error("no id unknown");
}
)";

ss << R"(
class parser_t {

public:

  using action_t = std::pair<action_kind_t, int>;

  using output_stack_t = std::vector<std::shared_ptr<ast_t>>;

  using input_queue_t = std::vector<std::shared_ptr<token_t>>;

  std::vector<std::shared_ptr<ast_t>> parse(input_queue_t tokens) {
    input = tokens;
    go = true;

    while(input.size() || go) {
      switch (states.back().first) {
        case restart:
          // leaving this here in case we want to create
          // timeout/restart functionality for cases where
          // message could get lost, ex. network failure, iot
          on_restart_action();
          break;
        case reduce:
          // get the rule associated with this action,
          // identify size of rule, pop n tokens
          // from output stack, create reduction, push
          // output. Push transition state on to state stack
          on_reduce_action();
          break;
        case shift:
          // shift the token and goto next state
          on_shift_action();
          break;
        case transition:
          // push the state identified in goto table
          on_transition_action();
          break;
      }
    }

    return output;
  }

  static std::shared_ptr<parser_t> make() {
    auto ptr = new parser_t();
    std::shared_ptr<parser_t> result(ptr);
    return result;
  }

protected:

  virtual void on_restart_action() {
    go = false;
  }

  virtual void on_reduce_action() {
    // lookup the reduction by rule id
    assert(states.back().first == reduce);
    assert(states.back().second);
    int rule_id = states.back().second;
    auto reduction = reduce_by_id(rule_id, output);
    output.push_back(reduction);

    // lookup the goto
    states.push_back({action_kind_t::transition, transitions[reduction->get_symbol_id()]});
  }

  virtual void on_shift_action() {
    if (input.empty()) {
      throw std::runtime_error("cannot shift input is empty");
    }

    assert(states.back().first == shift);
    assert(states.back().second);

    if (input.empty()) {
      throw std::runtime_error("unexpected end of program");
    }

    auto shifted_token = ast_token_t::make(input.front());
    input.erase(input.begin());
    output.push_back(shifted_token);
    int next_state = states.back().second;

    if (input.empty()) {
      int token_id = static_cast<int>(symbol_t::__break__);
      states.push_back(get_action(token_id, next_state));
    } else {
      int token_id = static_cast<int>(input.front()->get_kind());
      states.push_back(get_action(token_id, next_state));
    }
  }

  virtual void on_transition_action() {
    assert(states.back().first == transition);
    assert(states.back().second);

    if (input.empty()) {
      int token_id = static_cast<int>(symbol_t::__break__);
      int transition_to = states.back().second;
      states.push_back(get_action(token_id, transition_to));
    } else {
      int token_id = static_cast<int>(input.front()->get_kind());
      int transition_to = states.back().second;
      states.push_back(get_action(token_id, transition_to));
    }
  }

  /* get action from table */
  action_t get_action(int token_id, int state_id) {
    auto actions_by_token_id = actions.find(token_id);

    if (actions_by_token_id == actions.end()) {
      throw std::runtime_error("no actions listed for token " + input.front()->get_name());
    }

    auto action_by_state = actions_by_token_id->second.find(state_id);

    if (action_by_state == actions_by_token_id->second.end()) {
      throw std::runtime_error("no action in state " + std::to_string(state_id) + " for token " + input.front()->get_name());
    }

    return actions[token_id][state_id];
  }

  /* temporary input queue */
  input_queue_t input;

  /* state stack */
  std::vector<action_t> states;

  /* output stack */
  output_stack_t output;

  bool go;

  parser_t(): states({ {action_kind_t::transition, 1} }), go(false) {}

};  // parser_t

)";

  return ss.str();
}

}   // biglr