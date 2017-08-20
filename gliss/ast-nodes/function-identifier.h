#pragma once

#include <vector>
#include "ast-node.h"

#include "type-specifier.h"
#include "postfix-expression.h"

class type_specifier_t;
class postfix_expression_t;

namespace gliss {

class function_identifier_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  function_identifier_t(
    const type_specifier_t &
  ) {}

  function_identifier_t(
    const postfix_expression_t &
  ) {}

};  // function_identifier_t

const std::vector<std::vector<any_pattern_item_t>> function_identifier_t::patterns = {
  {
    pattern_item_t<type_specifier_t>::get()
  }, {
    pattern_item_t<postfix_expression_t>::get()
  }
};

}   // gliss
