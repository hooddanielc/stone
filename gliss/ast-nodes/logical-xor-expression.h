#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "logical-and-expression.h"


namespace gliss {

namespace ast {

class logical_xor_expression_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  logical_xor_expression_t(
    const logical_and_expression_t &
  );

  logical_xor_expression_t(
    const logical_xor_expression_t &,
    const token_t &,
    const logical_and_expression_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // logical_xor_expression_t

const std::vector<std::vector<any_pattern_item_t>> logical_xor_expression_t::patterns = {
  {
    pattern_item_t<logical_and_expression_t>::get()
  }, {
    pattern_item_t<logical_xor_expression_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("XOR_OP")),
    pattern_item_t<logical_and_expression_t>::get()
  }
};

}   // ast

}   // gliss
