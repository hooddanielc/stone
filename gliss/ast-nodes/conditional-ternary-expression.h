#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "logical-or-expression.h"
#include "expression.h"
#include "assignment-expression.h"

namespace gliss {

namespace ast {

class conditional_ternary_expression_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  conditional_ternary_expression_t(
    const logical_or_expression_t &,
    const token_t &,
    const expression_t &,
    const token_t &,
    const assignment_expression_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // conditional_ternary_expression_t

const std::vector<std::vector<any_pattern_item_t>> conditional_ternary_expression_t::patterns = {
  {
    pattern_item_t<logical_or_expression_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("QUESTION")),
    pattern_item_t<expression_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("COLON")),
    pattern_item_t<assignment_expression_t>::get()
  }
};

}   // ast

}   // gliss
