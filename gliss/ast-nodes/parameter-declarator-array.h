#pragma once

#include <vector>
#include "ast-node.h"

#include "type-specifier.h"
#include "array-specifier.h"

class type_specifier_t;
class array_specifier_t;

namespace gliss {

class parameter_declarator_array_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  parameter_declarator_array_t(
    const type_specifier_t &,
    const token_t &,
    const array_specifier_t &
  ) {}

};  // parameter_declarator_array_t

const std::vector<std::vector<any_pattern_item_t>> parameter_declarator_array_t::patterns = {
  {
    pattern_item_t<type_specifier_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<array_specifier_t>::get()
  }
};

}   // gliss
