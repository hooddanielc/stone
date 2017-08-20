#pragma once

#include <vector>
#include "ast-node.h"

#include "postfix-expression.h"
#include "integer-expression.h"

class postfix_expression_t;
class integer_expression_t;

namespace gliss {

class postfix_expression_integer_array_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  postfix_expression_integer_array_t(
    const postfix_expression_t &,
    const token_t &,
    const integer_expression_t &,
    const token_t &
  ) {}

};  // postfix_expression_integer_array_t

const std::vector<std::vector<any_pattern_item_t>> postfix_expression_integer_array_t::patterns = {
  {
    pattern_item_t<postfix_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<integer_expression_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
