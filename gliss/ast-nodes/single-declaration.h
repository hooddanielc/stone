#pragma once

#include <vector>
#include "ast-node.h"

#include "fully-specified-type.h"
#include "fully-specified-type-identifier.h"
#include "fully-specified-type-identifier-array.h"
#include "fully-specified-type-identifier-array-initializer.h"
#include "fully-specified-type-initializer.h"

class fully_specified_type_t;
class fully_specified_type_identifier_t;
class fully_specified_type_identifier_array_t;
class fully_specified_type_identifier_array_initializer_t;
class fully_specified_type_initializer_t;

namespace gliss {

class single_declaration_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  single_declaration_t(
    const fully_specified_type_t &
  ) {}

  single_declaration_t(
    const fully_specified_type_identifier_t &
  ) {}

  single_declaration_t(
    const fully_specified_type_identifier_array_t &
  ) {}

  single_declaration_t(
    const fully_specified_type_identifier_array_initializer_t &
  ) {}

  single_declaration_t(
    const fully_specified_type_initializer_t &
  ) {}

};  // single_declaration_t

const std::vector<std::vector<any_pattern_item_t>> single_declaration_t::patterns = {
  {
    pattern_item_t<fully_specified_type_t>::get()
  }, {
    pattern_item_t<fully_specified_type_identifier_t>::get()
  }, {
    pattern_item_t<fully_specified_type_identifier_array_t>::get()
  }, {
    pattern_item_t<fully_specified_type_identifier_array_initializer_t>::get()
  }, {
    pattern_item_t<fully_specified_type_initializer_t>::get()
  }
};

}   // gliss
