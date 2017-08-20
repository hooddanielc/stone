#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "additive-expression.h"


namespace gliss {

namespace ast {

class shift_expression_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  shift_expression_t(
    const additive_expression_t &
  );

  shift_expression_t(
    const shift_expression_t &,
    const token_t &,
    const additive_expression_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // shift_expression_t

const std::vector<std::vector<any_pattern_item_t>> shift_expression_t::patterns = {
  {
    pattern_item_t<additive_expression_t>::get()
  }, {
    pattern_item_t<shift_expression_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("LEFT_OP")),
    pattern_item_t<additive_expression_t>::get()
  }, {
    pattern_item_t<shift_expression_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("RIGHT_OP")),
    pattern_item_t<additive_expression_t>::get()
  }
};

}   // ast

}   // gliss
