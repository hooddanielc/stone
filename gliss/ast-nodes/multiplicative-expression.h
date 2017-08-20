#pragma once

#include <vector>
#include "ast-node.h"

#include "unary-expression.h"
#include "multiplicative-expression.h"

class unary_expression_t;
class multiplicative_expression_t;

namespace gliss {

class multiplicative_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  multiplicative_expression_t(
    const unary_expression_t &
  ) {}

  multiplicative_expression_t(
    const multiplicative_expression_t &,
    const token_t &,
    const unary_expression_t &
  ) {}

};  // multiplicative_expression_t

const std::vector<std::vector<any_pattern_item_t>> multiplicative_expression_t::patterns = {
  {
    pattern_item_t<unary_expression_t>::get()
  }, {
    pattern_item_t<multiplicative_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<unary_expression_t>::get()
  }, {
    pattern_item_t<multiplicative_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<unary_expression_t>::get()
  }, {
    pattern_item_t<multiplicative_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<unary_expression_t>::get()
  }
};

}   // gliss
