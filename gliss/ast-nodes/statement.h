#pragma once

#include <vector>
#include "ast-node.h"

#include "compound-statement.h"
#include "simple-statement.h"

class compound_statement_t;
class simple_statement_t;

namespace gliss {

class statement_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  statement_t(
    const compound_statement_t &
  ) {}

  statement_t(
    const simple_statement_t &
  ) {}

};  // statement_t

const std::vector<std::vector<any_pattern_item_t>> statement_t::patterns = {
  {
    pattern_item_t<compound_statement_t>::get()
  }, {
    pattern_item_t<simple_statement_t>::get()
  }
};

}   // gliss
