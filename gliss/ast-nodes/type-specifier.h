#pragma once

#include <vector>
#include "ast-node.h"

#include "type-specifier-nonarray.h"
#include "type-specifier-array.h"

class type_specifier_nonarray_t;
class type_specifier_array_t;

namespace gliss {

class type_specifier_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  type_specifier_t(
    const type_specifier_nonarray_t &
  ) {}

  type_specifier_t(
    const type_specifier_array_t &
  ) {}

};  // type_specifier_t

const std::vector<std::vector<any_pattern_item_t>> type_specifier_t::patterns = {
  {
    pattern_item_t<type_specifier_nonarray_t>::get()
  }, {
    pattern_item_t<type_specifier_array_t>::get()
  }
};

}   // gliss
