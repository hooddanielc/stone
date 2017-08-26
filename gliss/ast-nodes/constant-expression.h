#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "conditional-expression.h"

/**
 * Patterns for constant_expression
 *
 * 1. conditional_expression
 */

namespace gliss {

namespace ast {

class conditional_expression_t;

class constant_expression_t: public ast_t {

public:

  static constexpr int rules = 1;

  static constexpr int id = 239;

  virtual ~constant_expression_t() = default;

};  // constant_expression_t

class constant_expression_conditional_expression_t: public constant_expression_t {

public:

  std::unique_ptr<conditional_expression_t> conditional_expression_0;

  constant_expression_conditional_expression_t(
    std::unique_ptr<conditional_expression_t> &&conditional_expression_0_
  ): conditional_expression_0(std::move(conditional_expression_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<constant_expression_conditional_expression_t> make(
    std::unique_ptr<conditional_expression_t> &&conditional_expression_0_
  ) {
    return std::make_unique<constant_expression_conditional_expression_t>(
      std::move(conditional_expression_0_)
    );
  }

};  // constant_expression_conditional_expression_t

}   // ast

}   // gliss
