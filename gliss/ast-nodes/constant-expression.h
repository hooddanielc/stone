#pragma once

#include <vector>
#include "ast-node.h"

#include "conditional-expression.h"

class conditional_expression_t;

namespace gliss {

class constant_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  constant_expression_t(
    const conditional_expression_t &
  ) {}

};  // constant_expression_t

const std::vector<std::vector<any_pattern_item_t>> constant_expression_t::patterns = {
  {
    pattern_item_t<conditional_expression_t>::get()
  }
};

}   // gliss
