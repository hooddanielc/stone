#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"


namespace gliss {

namespace ast {

class variable_identifier_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  variable_identifier_t(
    const token_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // variable_identifier_t

const std::vector<std::vector<any_pattern_item_t>> variable_identifier_t::patterns = {
  {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("IDENTIFIER"))
  }
};

}   // ast

}   // gliss
