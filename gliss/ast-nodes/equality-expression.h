#pragma once

#include <vector>
#include "ast-node.h"

#include "relational-expression.h"
#include "equality-expression.h"

class relational_expression_t;
class equality_expression_t;

namespace gliss {

class equality_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  equality_expression_t(
    const relational_expression_t &
  ) {}

  equality_expression_t(
    const equality_expression_t &,
    const token_t &,
    const relational_expression_t &
  ) {}

};  // equality_expression_t

const std::vector<std::vector<any_pattern_item_t>> equality_expression_t::patterns = {
  {
    pattern_item_t<relational_expression_t>::get()
  }, {
    pattern_item_t<equality_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<relational_expression_t>::get()
  }, {
    pattern_item_t<equality_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<relational_expression_t>::get()
  }
};

}   // gliss
