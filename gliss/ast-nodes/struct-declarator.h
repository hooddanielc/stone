#pragma once

#include <vector>
#include "ast-node.h"

#include "struct-declarator-array.h"

class struct_declarator_array_t;

namespace gliss {

class struct_declarator_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  struct_declarator_t(
    const token_t &
  ) {}

  struct_declarator_t(
    const struct_declarator_array_t &
  ) {}

};  // struct_declarator_t

const std::vector<std::vector<any_pattern_item_t>> struct_declarator_t::patterns = {
  {
    pattern_item_t<token_t>::get()
  }, {
    pattern_item_t<struct_declarator_array_t>::get()
  }
};

}   // gliss
