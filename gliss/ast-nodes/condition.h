#pragma once

#include <vector>
#include "ast-node.h"

#include "expression.h"
#include "fully-specified-type.h"
#include "initializer.h"

class expression_t;
class fully_specified_type_t;
class initializer_t;

namespace gliss {

class condition_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  condition_t(
    const expression_t &
  ) {}

  condition_t(
    const fully_specified_type_t &,
    const token_t &,
    const token_t &,
    const initializer_t &
  ) {}

};  // condition_t

const std::vector<std::vector<any_pattern_item_t>> condition_t::patterns = {
  {
    pattern_item_t<expression_t>::get()
  }, {
    pattern_item_t<fully_specified_type_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<initializer_t>::get()
  }
};

}   // gliss
