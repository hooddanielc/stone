#pragma once

#include <vector>
#include "ast-node.h"

#include "struct-declaration-list.h"

class struct_declaration_list_t;

namespace gliss {

class struct_specifier_identifier_body_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  struct_specifier_identifier_body_t(
    const token_t &,
    const token_t &,
    const struct_declaration_list_t &,
    const token_t &
  ) {}

};  // struct_specifier_identifier_body_t

const std::vector<std::vector<any_pattern_item_t>> struct_specifier_identifier_body_t::patterns = {
  {
    pattern_item_t<token_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<struct_declaration_list_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
