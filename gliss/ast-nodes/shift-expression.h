#pragma once

#include <vector>
#include "ast-node.h"

#include "additive-expression.h"
#include "shift-expression.h"

class additive_expression_t;
class shift_expression_t;

namespace gliss {

class shift_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  shift_expression_t(
    const additive_expression_t &
  ) {}

  shift_expression_t(
    const shift_expression_t &,
    const token_t &,
    const additive_expression_t &
  ) {}

};  // shift_expression_t

const std::vector<std::vector<any_pattern_item_t>> shift_expression_t::patterns = {
  {
    pattern_item_t<additive_expression_t>::get()
  }, {
    pattern_item_t<shift_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<additive_expression_t>::get()
  }, {
    pattern_item_t<shift_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<additive_expression_t>::get()
  }
};

}   // gliss
