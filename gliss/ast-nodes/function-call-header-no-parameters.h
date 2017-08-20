#pragma once

#include <vector>
#include "ast-node.h"

#include "function-call-header-void-parameter.h"
#include "function-call-header.h"

class function_call_header_void_parameter_t;
class function_call_header_t;

namespace gliss {

class function_call_header_no_parameters_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  function_call_header_no_parameters_t(
    const function_call_header_void_parameter_t &
  ) {}

  function_call_header_no_parameters_t(
    const function_call_header_t &
  ) {}

};  // function_call_header_no_parameters_t

const std::vector<std::vector<any_pattern_item_t>> function_call_header_no_parameters_t::patterns = {
  {
    pattern_item_t<function_call_header_void_parameter_t>::get()
  }, {
    pattern_item_t<function_call_header_t>::get()
  }
};

}   // gliss
