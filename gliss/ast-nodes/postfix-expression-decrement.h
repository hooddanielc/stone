#pragma once

#include <vector>
#include "ast-node.h"

#include "postfix-expression.h"

class postfix_expression_t;

namespace gliss {

class postfix_expression_decrement_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  postfix_expression_decrement_t(
    const postfix_expression_t &,
    const token_t &
  ) {}

};  // postfix_expression_decrement_t

const std::vector<std::vector<any_pattern_item_t>> postfix_expression_decrement_t::patterns = {
  {
    pattern_item_t<postfix_expression_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
