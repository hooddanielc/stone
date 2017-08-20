#pragma once

#include <vector>
#include "ast-node.h"

#include "fully-specified-type.h"
#include "array-specifier.h"
#include "initializer.h"

class fully_specified_type_t;
class array_specifier_t;
class initializer_t;

namespace gliss {

class fully_specified_type_identifier_array_initializer_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  fully_specified_type_identifier_array_initializer_t(
    const fully_specified_type_t &,
    const token_t &,
    const array_specifier_t &,
    const token_t &,
    const initializer_t &
  ) {}

};  // fully_specified_type_identifier_array_initializer_t

const std::vector<std::vector<any_pattern_item_t>> fully_specified_type_identifier_array_initializer_t::patterns = {
  {
    pattern_item_t<fully_specified_type_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<array_specifier_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<initializer_t>::get()
  }
};

}   // gliss
