#pragma once

#include <vector>
#include "ast-node.h"

#include "constant-expression.h"

class constant_expression_t;

namespace gliss {

class layout_qualifier_id_equal_constant_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  layout_qualifier_id_equal_constant_expression_t(
    const token_t &,
    const token_t &,
    const constant_expression_t &
  ) {}

};  // layout_qualifier_id_equal_constant_expression_t

const std::vector<std::vector<any_pattern_item_t>> layout_qualifier_id_equal_constant_expression_t::patterns = {
  {
    pattern_item_t<token_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<constant_expression_t>::get()
  }
};

}   // gliss
