#pragma once

#include <vector>
#include "ast-node.h"

#include "conditionopt.h"
#include "expression.h"

class conditionopt_t;
class expression_t;

namespace gliss {

class for_rest_statement_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  for_rest_statement_expression_t(
    const conditionopt_t &,
    const token_t &,
    const expression_t &
  ) {}

};  // for_rest_statement_expression_t

const std::vector<std::vector<any_pattern_item_t>> for_rest_statement_expression_t::patterns = {
  {
    pattern_item_t<conditionopt_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<expression_t>::get()
  }
};

}   // gliss
