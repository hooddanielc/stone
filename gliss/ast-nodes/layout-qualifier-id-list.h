#pragma once

#include <vector>
#include "ast-node.h"

#include "layout-qualifier-id.h"
#include "layout-qualifier-id-list.h"

class layout_qualifier_id_t;
class layout_qualifier_id_list_t;

namespace gliss {

class layout_qualifier_id_list_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  layout_qualifier_id_list_t(
    const layout_qualifier_id_t &
  ) {}

  layout_qualifier_id_list_t(
    const layout_qualifier_id_list_t &,
    const token_t &,
    const layout_qualifier_id_t &
  ) {}

};  // layout_qualifier_id_list_t

const std::vector<std::vector<any_pattern_item_t>> layout_qualifier_id_list_t::patterns = {
  {
    pattern_item_t<layout_qualifier_id_t>::get()
  }, {
    pattern_item_t<layout_qualifier_id_list_t>::get(),
    pattern_item_t<token_t>::get(),
    pattern_item_t<layout_qualifier_id_t>::get()
  }
};

}   // gliss
