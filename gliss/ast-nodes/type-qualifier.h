#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "single-type-qualifier.h"


namespace gliss {

namespace ast {

class type_qualifier_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  type_qualifier_t(
    const single_type_qualifier_t &
  );

  type_qualifier_t(
    const type_qualifier_t &,
    const single_type_qualifier_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // type_qualifier_t

const std::vector<std::vector<any_pattern_item_t>> type_qualifier_t::patterns = {
  {
    pattern_item_t<single_type_qualifier_t>::get()
  }, {
    pattern_item_t<type_qualifier_t>::get(),
    pattern_item_t<single_type_qualifier_t>::get()
  }
};

}   // ast

}   // gliss