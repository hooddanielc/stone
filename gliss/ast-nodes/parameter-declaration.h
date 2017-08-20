#pragma once

#include <vector>
#include "ast-node.h"

#include "type-qualifier.h"
#include "parameter-declarator.h"
#include "parameter-type-specifier.h"

class type_qualifier_t;
class parameter_declarator_t;
class parameter_type_specifier_t;

namespace gliss {

class parameter_declaration_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  parameter_declaration_t(
    const type_qualifier_t &,
    const parameter_declarator_t &
  ) {}

  parameter_declaration_t(
    const parameter_declarator_t &
  ) {}

  parameter_declaration_t(
    const type_qualifier_t &,
    const parameter_type_specifier_t &
  ) {}

  parameter_declaration_t(
    const parameter_type_specifier_t &
  ) {}

};  // parameter_declaration_t

const std::vector<std::vector<any_pattern_item_t>> parameter_declaration_t::patterns = {
  {
    pattern_item_t<type_qualifier_t>::get(),
    pattern_item_t<parameter_declarator_t>::get()
  }, {
    pattern_item_t<parameter_declarator_t>::get()
  }, {
    pattern_item_t<type_qualifier_t>::get(),
    pattern_item_t<parameter_type_specifier_t>::get()
  }, {
    pattern_item_t<parameter_type_specifier_t>::get()
  }
};

}   // gliss
