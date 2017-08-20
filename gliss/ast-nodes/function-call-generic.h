#pragma once

#include <vector>
#include "ast-node.h"

#include "function-call-header-with-parameters.h"
#include "function-call-header-no-parameters.h"

class function_call_header_with_parameters_t;
class function_call_header_no_parameters_t;

namespace gliss {

class function_call_generic_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  function_call_generic_t(
    const function_call_header_with_parameters_t &,
    const token_t &
  ) {}

  function_call_generic_t(
    const function_call_header_no_parameters_t &,
    const token_t &
  ) {}

};  // function_call_generic_t

const std::vector<std::vector<any_pattern_item_t>> function_call_generic_t::patterns = {
  {
    pattern_item_t<function_call_header_with_parameters_t>::get(),
    pattern_item_t<token_t>::get()
  }, {
    pattern_item_t<function_call_header_no_parameters_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
