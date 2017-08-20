#pragma once

#include <vector>
#include "ast-node.h"

#include "expression.h"
#include "selection-rest-statement.h"

class expression_t;
class selection_rest_statement_t;

namespace gliss {

class selection_statement_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  selection_statement_t(
    const token_t &,
    const token_t &,
    const expression_t &,
    const token_t &,
    const selection_rest_statement_t &
  ) {}

};  // selection_statement_t

const std::vector<std::vector<any_pattern_item_t>> selection_statement_t::patterns = {
  {
    pattern_item_t<token_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<selection_rest_statement_t>::get()
  }
};

}   // gliss
