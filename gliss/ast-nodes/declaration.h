#pragma once

#include <vector>
#include "ast-node.h"

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

class function_prototype_t;
class init_declarator_list_t;
class precision_qualifier_t;
class type_specifier_t;
class type_qualifier_struct_declaration_list_t;
class type_qualifier_struct_declaration_list_identifier_t;
class type_qualifier_struct_declaration_list_identifier_array_t;
class type_qualifier_terminated_t;
class type_qualifier_identifier_t;
class type_qualifier_t;
class identifier_list_t;

namespace gliss {

class declaration_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  declaration_t(
    const function_prototype_t &,
    const token_t &
  ) {}

  declaration_t(
    const init_declarator_list_t &,
    const token_t &
  ) {}

  declaration_t(
    const token_t &,
    const precision_qualifier_t &,
    const type_specifier_t &,
    const token_t &
  ) {}

  declaration_t(
    const type_qualifier_struct_declaration_list_t &
  ) {}

  declaration_t(
    const type_qualifier_struct_declaration_list_identifier_t &
  ) {}

  declaration_t(
    const type_qualifier_struct_declaration_list_identifier_array_t &
  ) {}

  declaration_t(
    const type_qualifier_terminated_t &
  ) {}

  declaration_t(
    const type_qualifier_identifier_t &
  ) {}

  declaration_t(
    const type_qualifier_t &,
    const token_t &,
    const identifier_list_t &,
    const token_t &
  ) {}

};  // declaration_t

const std::vector<std::vector<any_pattern_item_t>> declaration_t::patterns = {
  {
    pattern_item_t<function_prototype_t>::get(),
    pattern_item_t<token_t>::get()
  }, {
    pattern_item_t<init_declarator_list_t>::get(),
    pattern_item_t<token_t>::get()
  }, {
    pattern_item_t<token_t>::get(),
    pattern_item_t<precision_qualifier_t>::get(),
    pattern_item_t<type_specifier_t>::get(),
    pattern_item_t<token_t>::get()
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
    pattern_item_t<token_t>::get(),
    pattern_item_t<identifier_list_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
