#pragma once

#include <vector>
#include "ast-node.h"

#include "single-type-qualifier.h"
#include "type-qualifier.h"

class single_type_qualifier_t;
class type_qualifier_t;

namespace gliss {

class type_qualifier_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  type_qualifier_t(
    const single_type_qualifier_t &
  ) {}

  type_qualifier_t(
    const type_qualifier_t &,
    const single_type_qualifier_t &
  ) {}

};  // type_qualifier_t

const std::vector<std::vector<any_pattern_item_t>> type_qualifier_t::patterns = {
  {
    pattern_item_t<single_type_qualifier_t>::get()
  }, {
    pattern_item_t<type_qualifier_t>::get(),
    pattern_item_t<single_type_qualifier_t>::get()
  }
};

}   // gliss
