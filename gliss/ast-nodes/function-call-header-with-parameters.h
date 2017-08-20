#pragma once

#include <vector>
#include "ast-node.h"

#include "function-call-header.h"
#include "assignment-expression.h"
#include "function-call-header-with-parameters.h"

class function_call_header_t;
class assignment_expression_t;
class function_call_header_with_parameters_t;

namespace gliss {

class function_call_header_with_parameters_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  function_call_header_with_parameters_t(
    const function_call_header_t &,
    const assignment_expression_t &
  ) {}

  function_call_header_with_parameters_t(
    const function_call_header_with_parameters_t &,
    const token_t &,
    const assignment_expression_t &
  ) {}

};  // function_call_header_with_parameters_t

const std::vector<std::vector<any_pattern_item_t>> function_call_header_with_parameters_t::patterns = {
  {
    pattern_item_t<function_call_header_t>::get(),
    pattern_item_t<assignment_expression_t>::get()
  }, {
    pattern_item_t<function_call_header_with_parameters_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<assignment_expression_t>::get()
  }
};

}   // gliss
