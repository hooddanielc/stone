#pragma once

#include <vector>
#include "ast-node.h"

#include "logical-xor-expression.h"
#include "logical-or-expression.h"

class logical_xor_expression_t;
class logical_or_expression_t;

namespace gliss {

class logical_or_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  logical_or_expression_t(
    const logical_xor_expression_t &
  ) {}

  logical_or_expression_t(
    const logical_or_expression_t &,
    const token_t &,
    const logical_xor_expression_t &
  ) {}

};  // logical_or_expression_t

const std::vector<std::vector<any_pattern_item_t>> logical_or_expression_t::patterns = {
  {
    pattern_item_t<logical_xor_expression_t>::get()
  }, {
    pattern_item_t<logical_or_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<logical_xor_expression_t>::get()
  }
};

}   // gliss
