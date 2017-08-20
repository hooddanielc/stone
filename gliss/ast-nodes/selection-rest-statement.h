#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "selection-rest-statement-else.h"
#include "statement.h"

namespace gliss {

namespace ast {

class selection_rest_statement_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  selection_rest_statement_t(
    const selection_rest_statement_else_t &
  );

  selection_rest_statement_t(
    const statement_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // selection_rest_statement_t

const std::vector<std::vector<any_pattern_item_t>> selection_rest_statement_t::patterns = {
  {
    pattern_item_t<selection_rest_statement_else_t>::get()
  }, {
    pattern_item_t<statement_t>::get()
  }
};

}   // ast

}   // gliss