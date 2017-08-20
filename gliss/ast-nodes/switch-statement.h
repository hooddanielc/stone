#pragma once

#include <vector>
#include "ast-node.h"

#include "expression.h"
#include "switch-statement-list.h"

class expression_t;
class switch_statement_list_t;

namespace gliss {

class switch_statement_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  switch_statement_t(
    const token_t &,
    const token_t &,
    const expression_t &,
    const token_t &,
    const token_t &,
    const switch_statement_list_t &,
    const token_t &
  ) {}

};  // switch_statement_t

const std::vector<std::vector<any_pattern_item_t>> switch_statement_t::patterns = {
  {
    pattern_item_t<token_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<switch_statement_list_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
