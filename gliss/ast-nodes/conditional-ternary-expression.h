#pragma once

#include <vector>
#include "ast-node.h"

#include "logical-or-expression.h"
#include "expression.h"
#include "assignment-expression.h"

class logical_or_expression_t;
class expression_t;
class assignment_expression_t;

namespace gliss {

class conditional_ternary_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  conditional_ternary_expression_t(
    const logical_or_expression_t &,
    const token_t &,
    const expression_t &,
    const token_t &,
    const assignment_expression_t &
  ) {}

};  // conditional_ternary_expression_t

const std::vector<std::vector<any_pattern_item_t>> conditional_ternary_expression_t::patterns = {
  {
    pattern_item_t<logical_or_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<assignment_expression_t>::get()
  }
};

}   // gliss
