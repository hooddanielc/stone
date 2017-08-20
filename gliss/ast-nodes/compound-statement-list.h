#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "statement-list.h"

namespace gliss {

namespace ast {

class compound_statement_list_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  compound_statement_list_t(
    const token_t &,
    const statement_list_t &,
    const token_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // compound_statement_list_t

const std::vector<std::vector<any_pattern_item_t>> compound_statement_list_t::patterns = {
  {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("LEFT_BRACE")),
    pattern_item_t<statement_list_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("RIGHT_BRACE"))
  }
};

}   // ast

}   // gliss