#pragma once

#include "../token.h"

namespace gliss {

class ast_node_t {

public:

};  // ast_node_t

class any_pattern_item_t {

};

template <typename node_t>
class pattern_item_t: public any_pattern_item_t {

public:

  static pattern_item_t &get() {
    static pattern_item_t singleton;
    return singleton;
  }

};

}   // gliss