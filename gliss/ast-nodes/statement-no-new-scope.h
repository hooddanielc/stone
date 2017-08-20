#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "compound-statement-no-new-scope.h"
#include "simple-statement.h"

namespace gliss {

namespace ast {

class statement_no_new_scope_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  statement_no_new_scope_t(
    const compound_statement_no_new_scope_t &
  );

  statement_no_new_scope_t(
    const simple_statement_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // statement_no_new_scope_t

const std::vector<std::vector<any_pattern_item_t>> statement_no_new_scope_t::patterns = {
  {
    pattern_item_t<compound_statement_no_new_scope_t>::get()
  }, {
    pattern_item_t<simple_statement_t>::get()
  }
};

}   // ast

}   // gliss
