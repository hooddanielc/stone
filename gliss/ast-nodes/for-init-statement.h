#pragma once

#include <vector>
#include "ast-node.h"

#include "expression-statement.h"
#include "declaration-statement.h"

class expression_statement_t;
class declaration_statement_t;

namespace gliss {

class for_init_statement_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  for_init_statement_t(
    const expression_statement_t &
  ) {}

  for_init_statement_t(
    const declaration_statement_t &
  ) {}

};  // for_init_statement_t

const std::vector<std::vector<any_pattern_item_t>> for_init_statement_t::patterns = {
  {
    pattern_item_t<expression_statement_t>::get()
  }, {
    pattern_item_t<declaration_statement_t>::get()
  }
};

}   // gliss
