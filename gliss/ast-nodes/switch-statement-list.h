#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "nothing.h"
#include "statement-list.h"

namespace gliss {

namespace ast {

class switch_statement_list_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  switch_statement_list_t(
    const nothing_t &
  );

  switch_statement_list_t(
    const statement_list_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // switch_statement_list_t

const std::vector<std::vector<any_pattern_item_t>> switch_statement_list_t::patterns = {
  {
    pattern_item_t<nothing_t>::get()
  }, {
    pattern_item_t<statement_list_t>::get()
  }
};

}   // ast

}   // gliss