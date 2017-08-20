#pragma once

#include <vector>
#include "ast-node.h"

#include "array-specifier.h"
#include "conditional-expression.h"

class array_specifier_t;
class conditional_expression_t;

namespace gliss {

class array_specifier_conditional_nested_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  array_specifier_conditional_nested_t(
    const array_specifier_t &,
    const token_t &,
    const conditional_expression_t &,
    const token_t &
  ) {}

};  // array_specifier_conditional_nested_t

const std::vector<std::vector<any_pattern_item_t>> array_specifier_conditional_nested_t::patterns = {
  {
    pattern_item_t<array_specifier_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<conditional_expression_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
