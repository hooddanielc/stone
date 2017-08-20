#pragma once

#include <vector>
#include "ast-node.h"

#include "jump-statement-continue.h"
#include "jump-statement-break.h"
#include "jump-statement-return.h"
#include "expression.h"

class jump_statement_continue_t;
class jump_statement_break_t;
class jump_statement_return_t;
class expression_t;

namespace gliss {

class jump_statement_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  jump_statement_t(
    const jump_statement_continue_t &
  ) {}

  jump_statement_t(
    const jump_statement_break_t &
  ) {}

  jump_statement_t(
    const jump_statement_return_t &
  ) {}

  jump_statement_t(
    const token_t &,
    const expression_t &,
    const token_t &
  ) {}

  jump_statement_t(
    const token_t &,
    const token_t &
  ) {}

};  // jump_statement_t

const std::vector<std::vector<any_pattern_item_t>> jump_statement_t::patterns = {
  {
    pattern_item_t<jump_statement_continue_t>::get()
  }, {
    pattern_item_t<jump_statement_break_t>::get()
  }, {
    pattern_item_t<jump_statement_return_t>::get()
  }, {
    pattern_item_t<token_t>::get(),
    pattern_item_t<expression_t>::get(),
    pattern_item_t<token_t>::get()
  }, {
    pattern_item_t<token_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
