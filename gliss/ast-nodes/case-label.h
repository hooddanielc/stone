#pragma once

#include <vector>
#include "ast-node.h"

#include "expression.h"

class expression_t;

namespace gliss {

class case_label_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  case_label_t(
    const token_t &,
    const expression_t &,
    const token_t &
  ) {}

  case_label_t(
    const token_t &,
    const token_t &
  ) {}

};  // case_label_t

const std::vector<std::vector<any_pattern_item_t>> case_label_t::patterns = {
  {
    pattern_item_t<token_t>::get(),
    pattern_item_t<expression_t>::get(),
    pattern_item_t<token_t>::get()
  }, {
    pattern_item_t<token_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
