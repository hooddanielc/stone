#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "init-declarator-list.h"
#include "initializer.h"

namespace gliss {

namespace ast {

class init_declarator_list_initializer_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  init_declarator_list_initializer_t(
    const init_declarator_list_t &,
    const token_t &,
    const token_t &,
    const token_t &,
    const initializer_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // init_declarator_list_initializer_t

const std::vector<std::vector<any_pattern_item_t>> init_declarator_list_initializer_t::patterns = {
  {
    pattern_item_t<init_declarator_list_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("COMMA")),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("IDENTIFIER")),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("EQUAL")),
    pattern_item_t<initializer_t>::get()
  }
};

}   // ast

}   // gliss
