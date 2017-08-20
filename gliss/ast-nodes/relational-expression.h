#pragma once

#include <vector>
#include "ast-node.h"

#include "shift-expression.h"
#include "relational-expression.h"

class shift_expression_t;
class relational_expression_t;

namespace gliss {

class relational_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  relational_expression_t(
    const shift_expression_t &
  ) {}

  relational_expression_t(
    const relational_expression_t &,
    const token_t &,
    const shift_expression_t &
  ) {}

};  // relational_expression_t

const std::vector<std::vector<any_pattern_item_t>> relational_expression_t::patterns = {
  {
    pattern_item_t<shift_expression_t>::get()
  }, {
    pattern_item_t<relational_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<shift_expression_t>::get()
  }, {
    pattern_item_t<relational_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<shift_expression_t>::get()
  }, {
    pattern_item_t<relational_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<shift_expression_t>::get()
  }, {
    pattern_item_t<relational_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<shift_expression_t>::get()
  }
};

}   // gliss
