#pragma once

#include <vector>
#include "ast-node.h"

#include "type-specifier.h"

class type_specifier_t;

namespace gliss {

class parameter_type_specifier_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  parameter_type_specifier_t(
    const type_specifier_t &
  ) {}

};  // parameter_type_specifier_t

const std::vector<std::vector<any_pattern_item_t>> parameter_type_specifier_t::patterns = {
  {
    pattern_item_t<type_specifier_t>::get()
  }
};

}   // gliss
