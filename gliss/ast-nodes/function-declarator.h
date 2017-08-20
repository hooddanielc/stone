#pragma once

#include <vector>
#include "ast-node.h"

#include "function-header.h"
#include "function-header-with-parameters.h"

class function_header_t;
class function_header_with_parameters_t;

namespace gliss {

class function_declarator_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  function_declarator_t(
    const function_header_t &
  ) {}

  function_declarator_t(
    const function_header_with_parameters_t &
  ) {}

};  // function_declarator_t

const std::vector<std::vector<any_pattern_item_t>> function_declarator_t::patterns = {
  {
    pattern_item_t<function_header_t>::get()
  }, {
    pattern_item_t<function_header_with_parameters_t>::get()
  }
};

}   // gliss
