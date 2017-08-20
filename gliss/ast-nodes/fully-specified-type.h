#pragma once

#include <vector>
#include "ast-node.h"

#include "type-specifier.h"
#include "type-qualifier.h"

class type_specifier_t;
class type_qualifier_t;

namespace gliss {

class fully_specified_type_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  fully_specified_type_t(
    const type_specifier_t &
  ) {}

  fully_specified_type_t(
    const type_qualifier_t &,
    const type_specifier_t &
  ) {}

};  // fully_specified_type_t

const std::vector<std::vector<any_pattern_item_t>> fully_specified_type_t::patterns = {
  {
    pattern_item_t<type_specifier_t>::get()
  }, {
    pattern_item_t<type_qualifier_t>::get(),
    pattern_item_t<type_specifier_t>::get()
  }
};

}   // gliss
