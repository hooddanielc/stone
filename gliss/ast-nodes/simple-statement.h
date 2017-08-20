#pragma once

#include <vector>
#include "ast-node.h"

#include "declaration-statement.h"
#include "expression-statement.h"
#include "selection-statement.h"
#include "switch-statement.h"
#include "case-label.h"
#include "iteration-statement.h"
#include "jump-statement.h"

class declaration_statement_t;
class expression_statement_t;
class selection_statement_t;
class switch_statement_t;
class case_label_t;
class iteration_statement_t;
class jump_statement_t;

namespace gliss {

class simple_statement_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  simple_statement_t(
    const declaration_statement_t &
  ) {}

  simple_statement_t(
    const expression_statement_t &
  ) {}

  simple_statement_t(
    const selection_statement_t &
  ) {}

  simple_statement_t(
    const switch_statement_t &
  ) {}

  simple_statement_t(
    const case_label_t &
  ) {}

  simple_statement_t(
    const iteration_statement_t &
  ) {}

  simple_statement_t(
    const jump_statement_t &
  ) {}

};  // simple_statement_t

const std::vector<std::vector<any_pattern_item_t>> simple_statement_t::patterns = {
  {
    pattern_item_t<declaration_statement_t>::get()
  }, {
    pattern_item_t<expression_statement_t>::get()
  }, {
    pattern_item_t<selection_statement_t>::get()
  }, {
    pattern_item_t<switch_statement_t>::get()
  }, {
    pattern_item_t<case_label_t>::get()
  }, {
    pattern_item_t<iteration_statement_t>::get()
  }, {
    pattern_item_t<jump_statement_t>::get()
  }
};

}   // gliss
