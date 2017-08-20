#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "type-specifier.h"
#include "struct-declarator-list.h"
#include "type-qualifier.h"

namespace gliss {

namespace ast {

class struct_declaration_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  struct_declaration_t(
    const type_specifier_t &,
    const struct_declarator_list_t &,
    const token_t &
  );

  struct_declaration_t(
    const type_qualifier_t &,
    const type_specifier_t &,
    const struct_declarator_list_t &,
    const token_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // struct_declaration_t

const std::vector<std::vector<any_pattern_item_t>> struct_declaration_t::patterns = {
  {
    pattern_item_t<type_specifier_t>::get(),
    pattern_item_t<struct_declarator_list_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("SEMICOLON"))
  }, {
    pattern_item_t<type_qualifier_t>::get(),
    pattern_item_t<type_specifier_t>::get(),
    pattern_item_t<struct_declarator_list_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("SEMICOLON"))
  }
};

}   // ast

}   // gliss
