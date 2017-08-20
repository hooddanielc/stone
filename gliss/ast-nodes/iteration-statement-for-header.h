#pragma once

#include <vector>
#include "ast-node.h"





namespace gliss {

class iteration_statement_for_header_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  iteration_statement_for_header_t(
    const token_t &,
    const token_t &
  ) {}

};  // iteration_statement_for_header_t

const std::vector<std::vector<any_pattern_item_t>> iteration_statement_for_header_t::patterns = {
  {
    pattern_item_t<token_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
