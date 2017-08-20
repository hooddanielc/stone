#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "initializer-list.h"

namespace gliss {

namespace ast {

class initializer_list_body_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  initializer_list_body_t(
    const token_t &,
    const initializer_list_t &,
    const token_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // initializer_list_body_t

const std::vector<std::vector<any_pattern_item_t>> initializer_list_body_t::patterns = {
  {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("LEFT_BRACE")),
    pattern_item_t<initializer_list_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("RIGHT_BRACE"))
  }
};

}   // ast

}   // gliss
