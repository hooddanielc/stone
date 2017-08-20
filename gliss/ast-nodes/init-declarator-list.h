#pragma once

#include <vector>
#include "ast-node.h"

#include "single-declaration.h"
#include "init-declarator-list.h"
#include "init-declarator-list-array.h"
#include "init-declarator-list-array-initializer.h"
#include "init-declarator-list-initializer.h"

class single_declaration_t;
class init_declarator_list_t;
class init_declarator_list_array_t;
class init_declarator_list_array_initializer_t;
class init_declarator_list_initializer_t;

namespace gliss {

class init_declarator_list_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  init_declarator_list_t(
    const single_declaration_t &
  ) {}

  init_declarator_list_t(
    const init_declarator_list_t &,
    const token_t &,
    const token_t &
  ) {}

  init_declarator_list_t(
    const init_declarator_list_array_t &
  ) {}

  init_declarator_list_t(
    const init_declarator_list_array_initializer_t &
  ) {}

  init_declarator_list_t(
    const init_declarator_list_initializer_t &
  ) {}

};  // init_declarator_list_t

const std::vector<std::vector<any_pattern_item_t>> init_declarator_list_t::patterns = {
  {
    pattern_item_t<single_declaration_t>::get()
  }, {
    pattern_item_t<init_declarator_list_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<token_t>::get()
  }, {
    pattern_item_t<init_declarator_list_array_t>::get()
  }, {
    pattern_item_t<init_declarator_list_array_initializer_t>::get()
  }, {
    pattern_item_t<init_declarator_list_initializer_t>::get()
  }
};

}   // gliss
