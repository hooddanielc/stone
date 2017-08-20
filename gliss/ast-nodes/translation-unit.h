#pragma once

#include <vector>
#include "ast-node.h"

#include "external-declaration.h"
#include "translation-unit.h"

class external_declaration_t;
class translation_unit_t;

namespace gliss {

class translation_unit_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  translation_unit_t(
    const external_declaration_t &
  ) {}

  translation_unit_t(
    const translation_unit_t &,
    const external_declaration_t &
  ) {}

};  // translation_unit_t

const std::vector<std::vector<any_pattern_item_t>> translation_unit_t::patterns = {
  {
    pattern_item_t<external_declaration_t>::get()
  }, {
    pattern_item_t<translation_unit_t>::get(),
    pattern_item_t<external_declaration_t>::get()
  }
};

}   // gliss
