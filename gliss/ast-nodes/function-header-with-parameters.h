#pragma once

#include <vector>
#include "ast-node.h"

#include "function-header.h"
#include "parameter-declaration.h"
#include "function-header-with-parameters.h"

class function_header_t;
class parameter_declaration_t;
class function_header_with_parameters_t;

namespace gliss {

class function_header_with_parameters_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  function_header_with_parameters_t(
    const function_header_t &,
    const parameter_declaration_t &
  ) {}

  function_header_with_parameters_t(
    const function_header_with_parameters_t &,
    const token_t &,
    const parameter_declaration_t &
  ) {}

};  // function_header_with_parameters_t

const std::vector<std::vector<any_pattern_item_t>> function_header_with_parameters_t::patterns = {
  {
    pattern_item_t<function_header_t>::get(),
    pattern_item_t<parameter_declaration_t>::get()
  }, {
    pattern_item_t<function_header_with_parameters_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<parameter_declaration_t>::get()
  }
};

}   // gliss
