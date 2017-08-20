#pragma once

#include <vector>
#include "ast-node.h"

#include "condition.h"

class condition_t;

namespace gliss {

class conditionopt_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  conditionopt_t(
    const condition_t &
  ) {}

};  // conditionopt_t

const std::vector<std::vector<any_pattern_item_t>> conditionopt_t::patterns = {
  {
    pattern_item_t<condition_t>::get()
  }
};

}   // gliss
