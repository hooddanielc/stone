#pragma once

#include <sstream>
#include <memory>
#include <map>
#include "../symbol.h"
#include "../action.h"

namespace biglr {

inline std::string generate_driver_h(std::shared_ptr<state_t> start) {
  ss << R"(

class parser_t {

public:

  using state_t = std::pair<action_kind_t, int>;

  std::shared_ptr<ast_t> parse() {
    std::shared_ptr<ast_t> ast;

    auto action_type = states.back().first;

    switch (action_type) {
      case restart:
        // leaving this here in case we want to create
        // timeout/restart functionality for cases where
        // message could get lost, ex. network failure, iot
        break;
      case reduce:
        // get the rule associated with this action,
        // identify size of rule, pop n tokens
        // from output stack, create reduction, push
        // output. Push transition state on to state stack
        break;
      case shift:
        // shift the token and goto next state
        break;
      case transition:
        // push the state identified in goto table
        break;
    }

    return ast;
  }

protected:

  /* state stack */
  std::vector<state_t> states;

  static std::shared_ptr<parser_t> make() {
    auto ptr = new parser_t();
    std::shared_ptr<parser_t> result(ptr);
    return result;
  }

  parser_t(): states({ {action_kind_t::transition, )" << start->get_id() << R"(} })

};

};  // transition
)";

  return ss.str();
}

}   // biglr