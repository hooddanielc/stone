#pragma once

#include <vector>
#include "ast-node.h"

#include "assignment-expression.h"
#include "initializer-list-body.h"
#include "initializer-list-body-trailing-comma.h"

class assignment_expression_t;
class initializer_list_body_t;
class initializer_list_body_trailing_comma_t;

namespace gliss {

class initializer_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  initializer_t(
    const assignment_expression_t &
  ) {}

  initializer_t(
    const initializer_list_body_t &
  ) {}

  initializer_t(
    const initializer_list_body_trailing_comma_t &
  ) {}

};  // initializer_t

const std::vector<std::vector<any_pattern_item_t>> initializer_t::patterns = {
  {
    pattern_item_t<assignment_expression_t>::get()
  }, {
    pattern_item_t<initializer_list_body_t>::get()
  }, {
    pattern_item_t<initializer_list_body_trailing_comma_t>::get()
  }
};

}   // gliss
