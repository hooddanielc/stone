#pragma once

#include <vector>
#include "ast-node.h"





namespace gliss {

class nothing_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  

};  // nothing_t

const std::vector<std::vector<any_pattern_item_t>> nothing_t::patterns = {
  
};

}   // gliss
