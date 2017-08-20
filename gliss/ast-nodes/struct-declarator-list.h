#pragma once

#include <vector>
#include "ast-node.h"

#include "struct-declarator.h"
#include "struct-declarator-list.h"

class struct_declarator_t;
class struct_declarator_list_t;

namespace gliss {

class struct_declarator_list_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  struct_declarator_list_t(
    const struct_declarator_t &
  ) {}

  struct_declarator_list_t(
    const struct_declarator_list_t &,
    const token_t &,
    const struct_declarator_t &
  ) {}

};  // struct_declarator_list_t

const std::vector<std::vector<any_pattern_item_t>> struct_declarator_list_t::patterns = {
  {
    pattern_item_t<struct_declarator_t>::get()
  }, {
    pattern_item_t<struct_declarator_list_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<struct_declarator_t>::get()
  }
};

}   // gliss
