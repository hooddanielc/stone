#pragma once

#include <vector>
#include "ast-node.h"

#include "fully-specified-type.h"

class fully_specified_type_t;

namespace gliss {

class function_header_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  function_header_t(
    const fully_specified_type_t &,
    const token_t &,
    const token_t &
  ) {}

};  // function_header_t

const std::vector<std::vector<any_pattern_item_t>> function_header_t::patterns = {
  {
    pattern_item_t<fully_specified_type_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
