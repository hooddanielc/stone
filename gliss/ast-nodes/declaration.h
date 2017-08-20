#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "function-prototype.h"
#include "init-declarator-list.h"
#include "precision-qualifier.h"
#include "type-specifier.h"
#include "type-qualifier-struct-declaration-list.h"
#include "type-qualifier-struct-declaration-list-identifier.h"
#include "type-qualifier-struct-declaration-list-identifier-array.h"
#include "type-qualifier-terminated.h"
#include "type-qualifier-identifier.h"
#include "type-qualifier.h"
#include "identifier-list.h"

namespace gliss {

namespace ast {

class declaration_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  declaration_t(
    const function_prototype_t &,
    const token_t &
  );

  declaration_t(
    const init_declarator_list_t &,
    const token_t &
  );

  declaration_t(
    const token_t &,
    const precision_qualifier_t &,
    const type_specifier_t &,
    const token_t &
  );

  declaration_t(
    const type_qualifier_struct_declaration_list_t &
  );

  declaration_t(
    const type_qualifier_struct_declaration_list_identifier_t &
  );

  declaration_t(
    const type_qualifier_struct_declaration_list_identifier_array_t &
  );

  declaration_t(
    const type_qualifier_terminated_t &
  );

  declaration_t(
    const type_qualifier_identifier_t &
  );

  declaration_t(
    const type_qualifier_t &,
    const token_t &,
    const identifier_list_t &,
    const token_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // declaration_t

const std::vector<std::vector<any_pattern_item_t>> declaration_t::patterns = {
  {
    pattern_item_t<function_prototype_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("SEMICOLON"))
  }, {
    pattern_item_t<init_declarator_list_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("SEMICOLON"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("PRECISION")),
    pattern_item_t<precision_qualifier_t>::get(),
    pattern_item_t<type_specifier_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("SEMICOLON"))
  }, {
    pattern_item_t<type_qualifier_struct_declaration_list_t>::get()
  }, {
    pattern_item_t<type_qualifier_struct_declaration_list_identifier_t>::get()
  }, {
    pattern_item_t<type_qualifier_struct_declaration_list_identifier_array_t>::get()
  }, {
    pattern_item_t<type_qualifier_terminated_t>::get()
  }, {
    pattern_item_t<type_qualifier_identifier_t>::get()
  }, {
    pattern_item_t<type_qualifier_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("IDENTIFIER")),
    pattern_item_t<identifier_list_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("SEMICOLON"))
  }
};

}   // ast

}   // gliss
