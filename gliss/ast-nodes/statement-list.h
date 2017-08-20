#pragma once

#include <vector>
#include "ast-node.h"

#include "statement.h"
#include "statement-list.h"

class statement_t;
class statement_list_t;

namespace gliss {

class statement_list_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  statement_list_t(
    const statement_t &
  ) {}

  statement_list_t(
    const statement_list_t &,
    const statement_t &
  ) {}

};  // statement_list_t

const std::vector<std::vector<any_pattern_item_t>> statement_list_t::patterns = {
  {
    pattern_item_t<statement_t>::get()
  }, {
    pattern_item_t<statement_list_t>::get(),
    pattern_item_t<statement_t>::get()
  }
};

}   // gliss
