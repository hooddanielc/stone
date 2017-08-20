#pragma once

#include <vector>
#include "ast-node.h"

#include "struct-declaration.h"
#include "struct-declaration-list.h"

class struct_declaration_t;
class struct_declaration_list_t;

namespace gliss {

class struct_declaration_list_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  struct_declaration_list_t(
    const struct_declaration_t &
  ) {}

  struct_declaration_list_t(
    const struct_declaration_list_t &,
    const struct_declaration_t &
  ) {}

};  // struct_declaration_list_t

const std::vector<std::vector<any_pattern_item_t>> struct_declaration_list_t::patterns = {
  {
    pattern_item_t<struct_declaration_t>::get()
  }, {
    pattern_item_t<struct_declaration_list_t>::get(),
    pattern_item_t<struct_declaration_t>::get()
  }
};

}   // gliss
