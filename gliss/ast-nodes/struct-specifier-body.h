#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "struct-declaration-list.h"

namespace gliss {

namespace ast {

class struct_specifier_body_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  struct_specifier_body_t(
    const token_t &,
    const struct_declaration_list_t &,
    const token_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // struct_specifier_body_t

const std::vector<std::vector<any_pattern_item_t>> struct_specifier_body_t::patterns = {
  {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("LEFT_BRACE")),
    pattern_item_t<struct_declaration_list_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("RIGHT_BRACE"))
  }
};

}   // ast

}   // gliss
