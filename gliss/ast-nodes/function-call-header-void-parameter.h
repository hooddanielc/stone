#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "function-call-header.h"

namespace gliss {

namespace ast {

class function_call_header_void_parameter_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  function_call_header_void_parameter_t(
    const function_call_header_t &,
    const token_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // function_call_header_void_parameter_t

const std::vector<std::vector<any_pattern_item_t>> function_call_header_void_parameter_t::patterns = {
  {
    pattern_item_t<function_call_header_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("VOID"))
  }
};

}   // ast

}   // gliss
