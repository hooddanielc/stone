#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "statement.h"

namespace gliss {

namespace ast {

class selection_rest_statement_t: public ast_t {

public:

  using unique_pattern_t = std::shared_ptr<any_pattern_item_t>;

  using pattern_t = std::vector<unique_pattern_t>;

  static const std::vector<pattern_t> patterns;

  selection_rest_statement_t(
    const statement_t &,
    const token_t &,
    const statement_t &
  );

  selection_rest_statement_t(
    const statement_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // selection_rest_statement_t

const std::vector<selection_rest_statement_t::pattern_t> selection_rest_statement_t::patterns = {
  {
    pattern_item_t<statement_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("ELSE")),
    pattern_item_t<statement_t>::get()
  }, {
    pattern_item_t<statement_t>::get()
  }
};

}   // ast

}   // gliss
