#pragma once

#include <vector>
#include "ast-node.h"





namespace gliss {

class jump_statement_return_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  jump_statement_return_t(
    const token_t &,
    const token_t &
  ) {}

};  // jump_statement_return_t

const std::vector<std::vector<any_pattern_item_t>> jump_statement_return_t::patterns = {
  {
    pattern_item_t<token_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
