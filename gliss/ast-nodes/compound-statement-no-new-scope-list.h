#pragma once

#include <vector>
#include "ast-node.h"

#include "statement-list.h"

class statement_list_t;

namespace gliss {

class compound_statement_no_new_scope_list_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  compound_statement_no_new_scope_list_t(
    const token_t &,
    const statement_list_t &,
    const token_t &
  ) {}

};  // compound_statement_no_new_scope_list_t

const std::vector<std::vector<any_pattern_item_t>> compound_statement_no_new_scope_list_t::patterns = {
  {
    pattern_item_t<token_t>::get(),
    pattern_item_t<statement_list_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
