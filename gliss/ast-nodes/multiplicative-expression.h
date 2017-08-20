#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "unary-expression.h"


namespace gliss {

namespace ast {

class multiplicative_expression_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  multiplicative_expression_t(
    const unary_expression_t &
  );

  multiplicative_expression_t(
    const multiplicative_expression_t &,
    const token_t &,
    const unary_expression_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // multiplicative_expression_t

const std::vector<std::vector<any_pattern_item_t>> multiplicative_expression_t::patterns = {
  {
    pattern_item_t<unary_expression_t>::get()
  }, {
    pattern_item_t<multiplicative_expression_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("STAR")),
    pattern_item_t<unary_expression_t>::get()
  }, {
    pattern_item_t<multiplicative_expression_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("SLASH")),
    pattern_item_t<unary_expression_t>::get()
  }, {
    pattern_item_t<multiplicative_expression_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("PERCENT")),
    pattern_item_t<unary_expression_t>::get()
  }
};

}   // ast

}   // gliss
