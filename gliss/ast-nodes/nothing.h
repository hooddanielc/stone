#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"

/**
 * Patterns for nothing
 *

 */

namespace gliss {

namespace ast {

class nothing_t: public ast_t {

public:

  static constexpr int rules = 0;

  static constexpr int id = -1;

  virtual void accept(const visitor_t &) const override {}
  virtual int get_id() const override {return -1;}

  virtual ~nothing_t() = default;

};  // nothing_t

}   // ast

}   // gliss
