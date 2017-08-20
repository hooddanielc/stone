#pragma once

#include <vector>
#include "ast-node.h"

#include "multiplicative-expression.h"
#include "additive-expression.h"

class multiplicative_expression_t;
class additive_expression_t;

namespace gliss {

class additive_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  additive_expression_t(
    const multiplicative_expression_t &
  ) {}

  additive_expression_t(
    const additive_expression_t &,
    const token_t &,
    const multiplicative_expression_t &
  ) {}

};  // additive_expression_t

const std::vector<std::vector<any_pattern_item_t>> additive_expression_t::patterns = {
  {
    pattern_item_t<multiplicative_expression_t>::get()
  }, {
    pattern_item_t<additive_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<multiplicative_expression_t>::get()
  }, {
    pattern_item_t<additive_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<multiplicative_expression_t>::get()
  }
};

}   // gliss
