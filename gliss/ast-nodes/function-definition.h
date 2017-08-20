#pragma once

#include <vector>
#include "ast-node.h"

#include "function-prototype.h"
#include "compound-statement-no-new-scope.h"

class function_prototype_t;
class compound_statement_no_new_scope_t;

namespace gliss {

class function_definition_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  function_definition_t(
    const function_prototype_t &,
    const compound_statement_no_new_scope_t &
  ) {}

};  // function_definition_t

const std::vector<std::vector<any_pattern_item_t>> function_definition_t::patterns = {
  {
    pattern_item_t<function_prototype_t>::get(),
    pattern_item_t<compound_statement_no_new_scope_t>::get()
  }
};

}   // gliss
