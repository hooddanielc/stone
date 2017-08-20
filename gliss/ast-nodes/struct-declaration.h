#pragma once

#include <vector>
#include "ast-node.h"

#include "type-specifier.h"
#include "struct-declarator-list.h"
#include "type-qualifier.h"

class type_specifier_t;
class struct_declarator_list_t;
class type_qualifier_t;

namespace gliss {

class struct_declaration_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  struct_declaration_t(
    const type_specifier_t &,
    const struct_declarator_list_t &,
    const token_t &
  ) {}

  struct_declaration_t(
    const type_qualifier_t &,
    const type_specifier_t &,
    const struct_declarator_list_t &,
    const token_t &
  ) {}

};  // struct_declaration_t

const std::vector<std::vector<any_pattern_item_t>> struct_declaration_t::patterns = {
  {
    pattern_item_t<type_specifier_t>::get(),
    pattern_item_t<struct_declarator_list_t>::get(),
    pattern_item_t<token_t>::get()
  }, {
    pattern_item_t<type_qualifier_t>::get(),
    pattern_item_t<type_specifier_t>::get(),
    pattern_item_t<struct_declarator_list_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
