#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "storage-qualifier-subroutine-list.h"

namespace gliss {

namespace ast {

class storage_qualifier_t: public ast_t {

public:

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  storage_qualifier_t(
    const token_t &
  );

  storage_qualifier_t(
    const storage_qualifier_subroutine_list_t &
  );

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // storage_qualifier_t

const std::vector<std::vector<any_pattern_item_t>> storage_qualifier_t::patterns = {
  {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("CONST"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("INOUT"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("IN"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("OUT"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("CENTROID"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("PATCH"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("SAMPLE"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("UNIFORM"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("BUFFER"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("SHARED"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("COHERENT"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("VOLATILE"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("RESTRICT"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("READONLY"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("WRITEONLY"))
  }, {
    pattern_item_t<token_t>::get(token_t::uppercase_to_kind("SUBROUTINE"))
  }, {
    pattern_item_t<storage_qualifier_subroutine_list_t>::get()
  }
};

}   // ast

}   // gliss