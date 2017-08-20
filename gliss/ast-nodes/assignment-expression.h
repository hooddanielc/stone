#pragma once

#include <vector>
#include "ast-node.h"

#include "conditional-expression.h"
#include "unary-expression.h"
#include "assignment-operator.h"
#include "assignment-expression.h"

class conditional_expression_t;
class unary_expression_t;
class assignment_operator_t;
class assignment_expression_t;

namespace gliss {

class assignment_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  assignment_expression_t(
    const conditional_expression_t &
  ) {}

  assignment_expression_t(
    const unary_expression_t &,
    const assignment_operator_t &,
    const assignment_expression_t &
  ) {}

};  // assignment_expression_t

const std::vector<std::vector<any_pattern_item_t>> assignment_expression_t::patterns = {
  {
    pattern_item_t<conditional_expression_t>::get()
  }, {
    pattern_item_t<unary_expression_t>::get(),
    pattern_item_t<assignment_operator_t>::get(),
    pattern_item_t<assignment_expression_t>::get()
  }
};

}   // gliss
