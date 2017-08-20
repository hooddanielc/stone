#pragma once

#include <vector>
#include "ast-node.h"

#include "expression.h"

class expression_t;

namespace gliss {

class integer_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  integer_expression_t(
    const expression_t &
  ) {}

};  // integer_expression_t

const std::vector<std::vector<any_pattern_item_t>> integer_expression_t::patterns = {
  {
    pattern_item_t<expression_t>::get()
  }
};

}   // gliss
