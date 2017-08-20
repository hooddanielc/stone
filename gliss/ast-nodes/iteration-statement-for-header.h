#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"


namespace gliss {

namespace ast {

class iteration_statement_for_header_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  iteration_statement_for_header_t(
    const token_t &,
    const token_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // iteration_statement_for_header_t

const std::vector<std::vector<any_pattern_item_t>> iteration_statement_for_header_t::patterns = {
  {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("FOR")),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("LEFT_PAREN"))
  }
};

}   // ast

}   // gliss
