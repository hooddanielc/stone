#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "conditional-expression.h"
#include "unary-expression.h"
#include "assignment-operator.h"

/**
 * Patterns for assignment_expression
 *
 * 1. conditional_expression
 * 2. unary_expression assignment_operator assignment_expression
 */

namespace gliss {

namespace ast {

class conditional_expression_t;
class unary_expression_t;
class assignment_operator_t;

class assignment_expression_t: public ast_t {

public:

  static constexpr int num_types = 2;

  virtual ~assignment_expression_t() = default;

};  // assignment_expression_t

class assignment_expression_conditional_expression_t: public assignment_expression_t {

public:

  std::unique_ptr<conditional_expression_t> conditional_expression_0;

  assignment_expression_conditional_expression_t(
    std::unique_ptr<conditional_expression_t> &&conditional_expression_0_
  ): conditional_expression_0(std::move(conditional_expression_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<assignment_expression_conditional_expression_t> make(
    std::unique_ptr<conditional_expression_t> &&conditional_expression_0_
  ) {
    return std::make_unique<assignment_expression_conditional_expression_t>(
      std::move(conditional_expression_0_)
    );
  }

};  // assignment_expression_conditional_expression_t

class assignment_expression_unary_expression_assignment_operator_assignment_expression_t: public assignment_expression_t {

public:

  std::unique_ptr<unary_expression_t> unary_expression_0;

  std::unique_ptr<assignment_operator_t> assignment_operator_1;

  std::unique_ptr<assignment_expression_t> assignment_expression_2;

  assignment_expression_unary_expression_assignment_operator_assignment_expression_t(
    std::unique_ptr<unary_expression_t> &&unary_expression_0_,
    std::unique_ptr<assignment_operator_t> &&assignment_operator_1_,
    std::unique_ptr<assignment_expression_t> &&assignment_expression_2_
  ): unary_expression_0(std::move(unary_expression_0_)),
     assignment_operator_1(std::move(assignment_operator_1_)),
     assignment_expression_2(std::move(assignment_expression_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<assignment_expression_unary_expression_assignment_operator_assignment_expression_t> make(
    std::unique_ptr<unary_expression_t> &&unary_expression_0_,
    std::unique_ptr<assignment_operator_t> &&assignment_operator_1_,
    std::unique_ptr<assignment_expression_t> &&assignment_expression_2_
  ) {
    return std::make_unique<assignment_expression_unary_expression_assignment_operator_assignment_expression_t>(
      std::move(unary_expression_0_),
      std::move(assignment_operator_1_),
      std::move(assignment_expression_2_)
    );
  }

};  // assignment_expression_unary_expression_assignment_operator_assignment_expression_t

}   // ast

}   // gliss
