#pragma once

#include <vector>
#include "ast-node.h"

#include "nothing.h"
#include "statement-list.h"

class nothing_t;
class statement_list_t;

namespace gliss {

class switch_statement_list_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  switch_statement_list_t(
    const nothing_t &
  ) {}

  switch_statement_list_t(
    const statement_list_t &
  ) {}

};  // switch_statement_list_t

const std::vector<std::vector<any_pattern_item_t>> switch_statement_list_t::patterns = {
  {
    pattern_item_t<nothing_t>::get()
  }, {
    pattern_item_t<statement_list_t>::get()
  }
};

}   // gliss
