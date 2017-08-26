#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "inclusive-or-expression.h"

/**
 * Patterns for logical_and_expression
 *
 * 1. inclusive_or_expression
 * 2. logical_and_expression AND_OP inclusive_or_expression
 */

namespace gliss {

namespace ast {

class inclusive_or_expression_t;

class logical_and_expression_t: public ast_t {

public:

  static constexpr int rules = 2;

  static constexpr int id = 232;

  virtual ~logical_and_expression_t() = default;

};  // logical_and_expression_t

class logical_and_expression_inclusive_or_expression_t: public logical_and_expression_t {

public:

  std::unique_ptr<inclusive_or_expression_t> inclusive_or_expression_0;

  logical_and_expression_inclusive_or_expression_t(
    std::unique_ptr<inclusive_or_expression_t> &&inclusive_or_expression_0_
  ): inclusive_or_expression_0(std::move(inclusive_or_expression_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<logical_and_expression_inclusive_or_expression_t> make(
    std::unique_ptr<inclusive_or_expression_t> &&inclusive_or_expression_0_
  ) {
    return std::make_unique<logical_and_expression_inclusive_or_expression_t>(
      std::move(inclusive_or_expression_0_)
    );
  }

};  // logical_and_expression_inclusive_or_expression_t

class logical_and_expression_logical_and_expression_and_op_inclusive_or_expression_t: public logical_and_expression_t {

public:

  std::unique_ptr<logical_and_expression_t> logical_and_expression_0;

  std::unique_ptr<token_t> and_op_1;

  std::unique_ptr<inclusive_or_expression_t> inclusive_or_expression_2;

  logical_and_expression_logical_and_expression_and_op_inclusive_or_expression_t(
    std::unique_ptr<logical_and_expression_t> &&logical_and_expression_0_,
    std::unique_ptr<token_t> &&and_op_1_,
    std::unique_ptr<inclusive_or_expression_t> &&inclusive_or_expression_2_
  ): logical_and_expression_0(std::move(logical_and_expression_0_)),
     and_op_1(std::move(and_op_1_)),
     inclusive_or_expression_2(std::move(inclusive_or_expression_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<logical_and_expression_logical_and_expression_and_op_inclusive_or_expression_t> make(
    std::unique_ptr<logical_and_expression_t> &&logical_and_expression_0_,
    const token_t *AND_OP_1_,
    std::unique_ptr<inclusive_or_expression_t> &&inclusive_or_expression_2_
  ) {
    return std::make_unique<logical_and_expression_logical_and_expression_and_op_inclusive_or_expression_t>(
      std::move(logical_and_expression_0_),
      std::make_unique<token_t>(*AND_OP_1_),
      std::move(inclusive_or_expression_2_)
    );
  }

};  // logical_and_expression_logical_and_expression_and_op_inclusive_or_expression_t

}   // ast

}   // gliss
