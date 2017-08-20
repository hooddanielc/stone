#pragma once

#include <vector>
#include "ast-node.h"

#include "exclusive-or-expression.h"
#include "inclusive-or-expression.h"

class exclusive_or_expression_t;
class inclusive_or_expression_t;

namespace gliss {

class inclusive_or_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  inclusive_or_expression_t(
    const exclusive_or_expression_t &
  ) {}

  inclusive_or_expression_t(
    const inclusive_or_expression_t &,
    const token_t &,
    const exclusive_or_expression_t &
  ) {}

};  // inclusive_or_expression_t

const std::vector<std::vector<any_pattern_item_t>> inclusive_or_expression_t::patterns = {
  {
    pattern_item_t<exclusive_or_expression_t>::get()
  }, {
    pattern_item_t<inclusive_or_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<exclusive_or_expression_t>::get()
  }
};

}   // gliss
