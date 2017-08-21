#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "function-call-header.h"
#include "assignment-expression.h"


namespace gliss {

namespace ast {

class function_call_header_with_parameters_t: public ast_t {

public:

  using unique_pattern_t = std::shared_ptr<any_pattern_item_t>;

  using pattern_t = std::vector<unique_pattern_t>;

  static const std::vector<pattern_t> patterns;

  function_call_header_with_parameters_t(
    const function_call_header_t &,
    const assignment_expression_t &
  );

  function_call_header_with_parameters_t(
    const function_call_header_with_parameters_t &,
    const token_t &,
    const assignment_expression_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // function_call_header_with_parameters_t

const std::vector<function_call_header_with_parameters_t::pattern_t> function_call_header_with_parameters_t::patterns = {
  {
    pattern_item_t<function_call_header_t>::get(),
    pattern_item_t<assignment_expression_t>::get()
  }, {
    pattern_item_t<function_call_header_with_parameters_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("COMMA")),
    pattern_item_t<assignment_expression_t>::get()
  }
};

}   // ast

}   // gliss
