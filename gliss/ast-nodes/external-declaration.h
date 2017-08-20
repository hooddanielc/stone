#pragma once

#include <vector>
#include "ast-node.h"

#include "function-definition.h"
#include "declaration.h"

class function_definition_t;
class declaration_t;

namespace gliss {

class external_declaration_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  external_declaration_t(
    const function_definition_t &
  ) {}

  external_declaration_t(
    const declaration_t &
  ) {}

  external_declaration_t(
    const token_t &
  ) {}

};  // external_declaration_t

const std::vector<std::vector<any_pattern_item_t>> external_declaration_t::patterns = {
  {
    pattern_item_t<function_definition_t>::get()
  }, {
    pattern_item_t<declaration_t>::get()
  }, {
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
