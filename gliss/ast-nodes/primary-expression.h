#pragma once

#include <vector>
#include "ast-node.h"

#include "variable-identifier.h"
#include "expression.h"

class variable_identifier_t;
class expression_t;

namespace gliss {

class primary_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  primary_expression_t(
    const variable_identifier_t &
  ) {}

  primary_expression_t(
    const token_t &
  ) {}

  primary_expression_t(
    const token_t &,
    const expression_t &,
    const token_t &
  ) {}

};  // primary_expression_t

const std::vector<std::vector<any_pattern_item_t>> primary_expression_t::patterns = {
  {
    pattern_item_t<variable_identifier_t>::get()
  }, {
    pattern_item_t<token_t>::get()
  }, {
    pattern_item_t<token_t>::get()
  }, {
    pattern_item_t<token_t>::get()
  }, {
    pattern_item_t<token_t>::get()
  }, {
    pattern_item_t<token_t>::get()
  }, {
    pattern_item_t<token_t>::get(),
    pattern_item_t<expression_t>::get(),
    pattern_item_t<token_t>::get()
  }
};

}   // gliss
