#pragma once

#include <vector>
#include "ast-node.h"

#include "iteration-statement-while-header.h"
#include "condition.h"
#include "statement-no-new-scope.h"
#include "statement.h"
#include "expression.h"
#include "iteration-statement-for-header.h"
#include "for-init-statement.h"
#include "for-rest-statement.h"

class iteration_statement_while_header_t;
class condition_t;
class statement_no_new_scope_t;
class statement_t;
class expression_t;
class iteration_statement_for_header_t;
class for_init_statement_t;
class for_rest_statement_t;

namespace gliss {

class iteration_statement_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  iteration_statement_t(
    const iteration_statement_while_header_t &,
    const condition_t &,
    const token_t &,
    const statement_no_new_scope_t &
  ) {}

  iteration_statement_t(
    const token_t &,
    const statement_t &,
    const token_t &,
    const token_t &,
    const expression_t &,
    const token_t &,
    const token_t &
  ) {}

  iteration_statement_t(
    const iteration_statement_for_header_t &,
    const for_init_statement_t &,
    const for_rest_statement_t &,
    const token_t &,
    const statement_no_new_scope_t &
  ) {}

};  // iteration_statement_t

const std::vector<std::vector<any_pattern_item_t>> iteration_statement_t::patterns = {
  {
    pattern_item_t<iteration_statement_while_header_t>::get(),
    pattern_item_t<condition_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<statement_no_new_scope_t>::get()
  }, {
    pattern_item_t<token_t>::get(),
    pattern_item_t<statement_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<expression_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<token_t>::get()
  }, {
    pattern_item_t<iteration_statement_for_header_t>::get(),
    pattern_item_t<for_init_statement_t>::get(),
    pattern_item_t<for_rest_statement_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<statement_no_new_scope_t>::get()
  }
};

}   // gliss
