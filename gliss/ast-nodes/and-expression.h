#pragma once

#include <vector>
#include "ast-node.h"

#include "equality-expression.h"
#include "and-expression.h"

class equality_expression_t;
class and_expression_t;

namespace gliss {

class and_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  and_expression_t(
    const equality_expression_t &
  ) {}

  and_expression_t(
    const and_expression_t &,
    const token_t &,
    const equality_expression_t &
  ) {}

};  // and_expression_t

const std::vector<std::vector<any_pattern_item_t>> and_expression_t::patterns = {
  {
    pattern_item_t<equality_expression_t>::get()
  }, {
    pattern_item_t<and_expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<equality_expression_t>::get()
  }
};

}   // gliss
