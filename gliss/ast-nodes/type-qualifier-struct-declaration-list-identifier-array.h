#pragma once

#include <vector>
#include "ast-node.h"

#include "type-qualifier.h"
#include "struct-declaration-list.h"
#include "array-specifier.h"

class type_qualifier_t;
class struct_declaration_list_t;
class array_specifier_t;

namespace gliss {

class type_qualifier_struct_declaration_list_identifier_array_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  type_qualifier_struct_declaration_list_identifier_array_t(
    const type_qualifier_t &,
    const token_t &,
    const token_t &,
    const struct_declaration_list_t &,
    const token_t &,
    const token_t &,
    const array_specifier_t &,
    const token_t &
  ) {}

};  // type_qualifier_struct_declaration_list_identifier_array_t

const std::vector<std::vector<any_pattern_item_t>> type_qualifier_struct_declaration_list_identifier_array_t::patterns = {
  {
    pattern_item_t<type_qualifier_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<struct_declaration_list_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<array_specifier_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
