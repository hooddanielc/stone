#pragma once

#include <vector>
#include "ast-node.h"

#include "type-name-list.h"

class type_name_list_t;

namespace gliss {

class type_name_list_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  type_name_list_t(
    const token_t &
  ) {}

  type_name_list_t(
    const type_name_list_t &,
    const token_t &,
    const token_t &
  ) {}

};  // type_name_list_t

const std::vector<std::vector<any_pattern_item_t>> type_name_list_t::patterns = {
  {
    pattern_item_t<token_t>::get()
  }, {
    pattern_item_t<type_name_list_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
