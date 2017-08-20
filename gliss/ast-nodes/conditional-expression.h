#pragma once

#include <vector>
#include "ast-node.h"

#include "logical-or-expression.h"
#include "conditional-ternary-expression.h"

class logical_or_expression_t;
class conditional_ternary_expression_t;

namespace gliss {

class conditional_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  conditional_expression_t(
    const logical_or_expression_t &
  ) {}

  conditional_expression_t(
    const conditional_ternary_expression_t &
  ) {}

};  // conditional_expression_t

const std::vector<std::vector<any_pattern_item_t>> conditional_expression_t::patterns = {
  {
    pattern_item_t<logical_or_expression_t>::get()
  }, {
    pattern_item_t<conditional_ternary_expression_t>::get()
  }
};

}   // gliss
