#pragma once

#include <vector>
#include "ast-node.h"

#include "initializer-list.h"

class initializer_list_t;

namespace gliss {

class initializer_list_body_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  initializer_list_body_t(
    const token_t &,
    const initializer_list_t &,
    const token_t &
  ) {}

};  // initializer_list_body_t

const std::vector<std::vector<any_pattern_item_t>> initializer_list_body_t::patterns = {
  {
    pattern_item_t<token_t>::get(),
    pattern_item_t<initializer_list_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
