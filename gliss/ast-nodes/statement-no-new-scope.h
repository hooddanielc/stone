#pragma once

#include <vector>
#include "ast-node.h"

#include "compound-statement-no-new-scope.h"
#include "simple-statement.h"

class compound_statement_no_new_scope_t;
class simple_statement_t;

namespace gliss {

class statement_no_new_scope_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  statement_no_new_scope_t(
    const compound_statement_no_new_scope_t &
  ) {}

  statement_no_new_scope_t(
    const simple_statement_t &
  ) {}

};  // statement_no_new_scope_t

const std::vector<std::vector<any_pattern_item_t>> statement_no_new_scope_t::patterns = {
  {
    pattern_item_t<compound_statement_no_new_scope_t>::get()
  }, {
    pattern_item_t<simple_statement_t>::get()
  }
};

}   // gliss
