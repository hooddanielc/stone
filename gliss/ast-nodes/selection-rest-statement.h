#pragma once

#include <vector>
#include "ast-node.h"

#include "selection-rest-statement-else.h"
#include "statement.h"

class selection_rest_statement_else_t;
class statement_t;

namespace gliss {

class selection_rest_statement_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  selection_rest_statement_t(
    const selection_rest_statement_else_t &
  ) {}

  selection_rest_statement_t(
    const statement_t &
  ) {}

};  // selection_rest_statement_t

const std::vector<std::vector<any_pattern_item_t>> selection_rest_statement_t::patterns = {
  {
    pattern_item_t<selection_rest_statement_else_t>::get()
  }, {
    pattern_item_t<statement_t>::get()
  }
};

}   // gliss
