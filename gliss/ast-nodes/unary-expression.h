#pragma once

#include <vector>
#include "ast-node.h"

#include "postfix-expression.h"
#include "unary-expression.h"
#include "unary-operator.h"

class postfix_expression_t;
class unary_expression_t;
class unary_operator_t;

namespace gliss {

class unary_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  unary_expression_t(
    const postfix_expression_t &
  ) {}

  unary_expression_t(
    const token_t &,
    const unary_expression_t &
  ) {}

  unary_expression_t(
    const unary_operator_t &,
    const unary_expression_t &
  ) {}

};  // unary_expression_t

const std::vector<std::vector<any_pattern_item_t>> unary_expression_t::patterns = {
  {
    pattern_item_t<postfix_expression_t>::get()
  }, {
    pattern_item_t<token_t>::get(),
    pattern_item_t<unary_expression_t>::get()
  }, {
    pattern_item_t<token_t>::get(),
    pattern_item_t<unary_expression_t>::get()
  }, {
    pattern_item_t<unary_operator_t>::get(),
    pattern_item_t<unary_expression_t>::get()
  }
};

}   // gliss
