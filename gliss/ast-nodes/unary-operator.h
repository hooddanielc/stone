#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"


namespace gliss {

namespace ast {

class unary_operator_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  unary_operator_t(
    const token_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // unary_operator_t

const std::vector<std::vector<any_pattern_item_t>> unary_operator_t::patterns = {
  {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("PLUS"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("DASH"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("BANG"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("TILDE"))
  }
};

}   // ast

}   // gliss
