#pragma once

#include <vector>
#include "ast-node.h"

#include "primary-expression.h"
#include "postfix-expression-integer-array.h"
#include "function-call.h"
#include "postfix-expression-field-selection.h"
#include "postfix-expression-increment.h"
#include "postfix-expression-decrement.h"

class primary_expression_t;
class postfix_expression_integer_array_t;
class function_call_t;
class postfix_expression_field_selection_t;
class postfix_expression_increment_t;
class postfix_expression_decrement_t;

namespace gliss {

class postfix_expression_t: public ast_node_t {

public:

  static const std::vector<ast_node_t> nodes;

  static const std::vector<std::vector<any_pattern_item_t>> patterns;

  postfix_expression_t(
    const primary_expression_t &
  ) {}

  postfix_expression_t(
    const postfix_expression_integer_array_t &
  ) {}

  postfix_expression_t(
    const function_call_t &
  ) {}

  postfix_expression_t(
    const postfix_expression_field_selection_t &
  ) {}

  postfix_expression_t(
    const postfix_expression_increment_t &
  ) {}

  postfix_expression_t(
    const postfix_expression_decrement_t &
  ) {}

};  // postfix_expression_t

const std::vector<std::vector<any_pattern_item_t>> postfix_expression_t::patterns = {
  {
    pattern_item_t<primary_expression_t>::get()
  }, {
    pattern_item_t<postfix_expression_integer_array_t>::get()
  }, {
    pattern_item_t<function_call_t>::get()
  }, {
    pattern_item_t<postfix_expression_field_selection_t>::get()
  }, {
    pattern_item_t<postfix_expression_increment_t>::get()
  }, {
    pattern_item_t<postfix_expression_decrement_t>::get()
  }
};

}   // gliss
