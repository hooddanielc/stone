#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"


namespace gliss {

namespace ast {

class type_name_list_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  type_name_list_t(
    const token_t &
  );

  type_name_list_t(
    const type_name_list_t &,
    const token_t &,
    const token_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // type_name_list_t

const std::vector<std::vector<any_pattern_item_t>> type_name_list_t::patterns = {
  {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("TYPE_NAME"))
  }, {
    pattern_item_t<type_name_list_t>::get(),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("COMMA")),
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("TYPE_NAME"))
  }
};

}   // ast

}   // gliss
