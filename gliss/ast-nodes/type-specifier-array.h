#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "type-specifier-nonarray.h"
#include "array-specifier.h"

namespace gliss {

namespace ast {

class type_specifier_array_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  type_specifier_array_t(
    const type_specifier_nonarray_t &,
    const array_specifier_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // type_specifier_array_t

const std::vector<std::vector<any_pattern_item_t>> type_specifier_array_t::patterns = {
  {
    pattern_item_t<type_specifier_nonarray_t>::get(),
    pattern_item_t<array_specifier_t>::get()
  }
};

}   // ast

}   // gliss
