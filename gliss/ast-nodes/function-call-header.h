#pragma once

#include <vector>
#include "ast-node.h"

#include "function-identifier.h"

class function_identifier_t;

namespace gliss {

class function_call_header_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  function_call_header_t(
    const function_identifier_t &,
    const token_t &
  ) {}

};  // function_call_header_t

const std::vector<std::vector<any_pattern_item_t>> function_call_header_t::patterns = {
  {
    pattern_item_t<function_identifier_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
