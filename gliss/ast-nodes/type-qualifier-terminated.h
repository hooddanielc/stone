#pragma once

#include <vector>
#include "ast-node.h"

#include "type-qualifier.h"

class type_qualifier_t;

namespace gliss {

class type_qualifier_terminated_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  type_qualifier_terminated_t(
    const type_qualifier_t &,
    const token_t &
  ) {}

};  // type_qualifier_terminated_t

const std::vector<std::vector<any_pattern_item_t>> type_qualifier_terminated_t::patterns = {
  {
    pattern_item_t<type_qualifier_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
