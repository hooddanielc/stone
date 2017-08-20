#pragma once

#include <vector>
#include "ast-node.h"

#include "function-declarator.h"

class function_declarator_t;

namespace gliss {

class function_prototype_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  function_prototype_t(
    const function_declarator_t &,
    const token_t &
  ) {}

};  // function_prototype_t

const std::vector<std::vector<any_pattern_item_t>> function_prototype_t::patterns = {
  {
    pattern_item_t<function_declarator_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
