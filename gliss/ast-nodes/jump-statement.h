#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "jump-statement-continue.h"
#include "jump-statement-break.h"
#include "jump-statement-return.h"
#include "expression.h"

namespace gliss {

namespace ast {

class jump_statement_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  jump_statement_t(
    const jump_statement_continue_t &
  );

  jump_statement_t(
    const jump_statement_break_t &
  );

  jump_statement_t(
    const jump_statement_return_t &
  );

  jump_statement_t(
    const token_t &,
    const expression_t &,
    const token_t &
  );

  jump_statement_t(
    const token_t &,
    const token_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // jump_statement_t

const std::vector<std::vector<any_pattern_item_t>> jump_statement_t::patterns = {
  {
    pattern_item_t<jump_statement_continue_t>::get()
  }, {
    pattern_item_t<jump_statement_break_t>::get()
  }, {
    pattern_item_t<jump_statement_return_t>::get()
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("RETURN")),
    pattern_item_t<expression_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("SEMICOLON"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("DISCARD")),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("SEMICOLON"))
  }
};

}   // ast

}   // gliss
