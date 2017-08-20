#pragma once

#include <vector>
#include "ast-node.h"

#include "and-expression.h"
#include "exclusive-or-expression.h"

class and_expression_t;
class exclusive_or_expression_t;

namespace gliss {

class exclusive_or_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  exclusive_or_expression_t(
    const and_expression_t &
  ) {}

  exclusive_or_expression_t(
    const exclusive_or_expression_t &,
    const token_t &,
    const and_expression_t &
  ) {}

};  // exclusive_or_expression_t

const std::vector<std::vector<any_pattern_item_t>> exclusive_or_expression_t::patterns = {
  {
    pattern_item_t<and_expression_t>::get()
  }, {
    pattern_item_t<exclusive_or_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<and_expression_t>::get()
  }
};

}   // gliss
