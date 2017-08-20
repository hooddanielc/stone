#pragma once

#include <vector>
#include "ast-node.h"

#include "declaration.h"

class declaration_t;

namespace gliss {

class declaration_statement_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  declaration_statement_t(
    const declaration_t &
  ) {}

};  // declaration_statement_t

const std::vector<std::vector<any_pattern_item_t>> declaration_statement_t::patterns = {
  {
    pattern_item_t<declaration_t>::get()
  }
};

}   // gliss
