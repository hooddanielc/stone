#pragma once

#include <vector>
#include "ast-node.h"





namespace gliss {

class variable_identifier_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  variable_identifier_t(
    const token_t &
  ) {}

};  // variable_identifier_t

const std::vector<std::vector<any_pattern_item_t>> variable_identifier_t::patterns = {
  {
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
