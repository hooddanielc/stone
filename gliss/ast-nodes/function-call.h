#pragma once

#include <vector>
#include "ast-node.h"

#include "function-call-or-method.h"

class function_call_or_method_t;

namespace gliss {

class function_call_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  function_call_t(
    const function_call_or_method_t &
  ) {}

};  // function_call_t

const std::vector<std::vector<any_pattern_item_t>> function_call_t::patterns = {
  {
    pattern_item_t<function_call_or_method_t>::get()
  }
};

}   // gliss
