#pragma once

#include <vector>
#include "ast-node.h"

#include "initializer.h"
#include "initializer-list.h"

class initializer_t;
class initializer_list_t;

namespace gliss {

class initializer_list_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  initializer_list_t(
    const initializer_t &
  ) {}

  initializer_list_t(
    const initializer_list_t &,
    const token_t &,
    const initializer_t &
  ) {}

};  // initializer_list_t

const std::vector<std::vector<any_pattern_item_t>> initializer_list_t::patterns = {
  {
    pattern_item_t<initializer_t>::get()
  }, {
    pattern_item_t<initializer_list_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<initializer_t>::get()
  }
};

}   // gliss
