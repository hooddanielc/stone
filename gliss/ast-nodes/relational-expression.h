#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "shift-expression.h"

/**
 * Patterns for relational_expression
 *
 * 1. shift_expression
 * 2. relational_expression LEFT_ANGLE shift_expression
 * 3. relational_expression RIGHT_ANGLE shift_expression
 * 4. relational_expression LE_OP shift_expression
 * 5. relational_expression GE_OP shift_expression
 */

namespace gliss {

namespace ast {

class shift_expression_t;

class relational_expression_t: public ast_t {

public:

  static constexpr int rules = 5;

  static constexpr int id = 227;

  virtual ~relational_expression_t() = default;

};  // relational_expression_t

class relational_expression_shift_expression_t: public relational_expression_t {

public:

  std::unique_ptr<shift_expression_t> shift_expression_0;

  relational_expression_shift_expression_t(
    std::unique_ptr<shift_expression_t> &&shift_expression_0_
  ): shift_expression_0(std::move(shift_expression_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<relational_expression_shift_expression_t> make(
    std::unique_ptr<shift_expression_t> &&shift_expression_0_
  ) {
    return std::make_unique<relational_expression_shift_expression_t>(
      std::move(shift_expression_0_)
    );
  }

};  // relational_expression_shift_expression_t

class relational_expression_relational_expression_left_angle_shift_expression_t: public relational_expression_t {

public:

  std::unique_ptr<relational_expression_t> relational_expression_0;

  std::unique_ptr<token_t> left_angle_1;

  std::unique_ptr<shift_expression_t> shift_expression_2;

  relational_expression_relational_expression_left_angle_shift_expression_t(
    std::unique_ptr<relational_expression_t> &&relational_expression_0_,
    std::unique_ptr<token_t> &&left_angle_1_,
    std::unique_ptr<shift_expression_t> &&shift_expression_2_
  ): relational_expression_0(std::move(relational_expression_0_)),
     left_angle_1(std::move(left_angle_1_)),
     shift_expression_2(std::move(shift_expression_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<relational_expression_relational_expression_left_angle_shift_expression_t> make(
    std::unique_ptr<relational_expression_t> &&relational_expression_0_,
    const token_t *LEFT_ANGLE_1_,
    std::unique_ptr<shift_expression_t> &&shift_expression_2_
  ) {
    return std::make_unique<relational_expression_relational_expression_left_angle_shift_expression_t>(
      std::move(relational_expression_0_),
      std::make_unique<token_t>(*LEFT_ANGLE_1_),
      std::move(shift_expression_2_)
    );
  }

};  // relational_expression_relational_expression_left_angle_shift_expression_t

class relational_expression_relational_expression_right_angle_shift_expression_t: public relational_expression_t {

public:

  std::unique_ptr<relational_expression_t> relational_expression_0;

  std::unique_ptr<token_t> right_angle_1;

  std::unique_ptr<shift_expression_t> shift_expression_2;

  relational_expression_relational_expression_right_angle_shift_expression_t(
    std::unique_ptr<relational_expression_t> &&relational_expression_0_,
    std::unique_ptr<token_t> &&right_angle_1_,
    std::unique_ptr<shift_expression_t> &&shift_expression_2_
  ): relational_expression_0(std::move(relational_expression_0_)),
     right_angle_1(std::move(right_angle_1_)),
     shift_expression_2(std::move(shift_expression_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<relational_expression_relational_expression_right_angle_shift_expression_t> make(
    std::unique_ptr<relational_expression_t> &&relational_expression_0_,
    const token_t *RIGHT_ANGLE_1_,
    std::unique_ptr<shift_expression_t> &&shift_expression_2_
  ) {
    return std::make_unique<relational_expression_relational_expression_right_angle_shift_expression_t>(
      std::move(relational_expression_0_),
      std::make_unique<token_t>(*RIGHT_ANGLE_1_),
      std::move(shift_expression_2_)
    );
  }

};  // relational_expression_relational_expression_right_angle_shift_expression_t

class relational_expression_relational_expression_le_op_shift_expression_t: public relational_expression_t {

public:

  std::unique_ptr<relational_expression_t> relational_expression_0;

  std::unique_ptr<token_t> le_op_1;

  std::unique_ptr<shift_expression_t> shift_expression_2;

  relational_expression_relational_expression_le_op_shift_expression_t(
    std::unique_ptr<relational_expression_t> &&relational_expression_0_,
    std::unique_ptr<token_t> &&le_op_1_,
    std::unique_ptr<shift_expression_t> &&shift_expression_2_
  ): relational_expression_0(std::move(relational_expression_0_)),
     le_op_1(std::move(le_op_1_)),
     shift_expression_2(std::move(shift_expression_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<relational_expression_relational_expression_le_op_shift_expression_t> make(
    std::unique_ptr<relational_expression_t> &&relational_expression_0_,
    const token_t *LE_OP_1_,
    std::unique_ptr<shift_expression_t> &&shift_expression_2_
  ) {
    return std::make_unique<relational_expression_relational_expression_le_op_shift_expression_t>(
      std::move(relational_expression_0_),
      std::make_unique<token_t>(*LE_OP_1_),
      std::move(shift_expression_2_)
    );
  }

};  // relational_expression_relational_expression_le_op_shift_expression_t

class relational_expression_relational_expression_ge_op_shift_expression_t: public relational_expression_t {

public:

  std::unique_ptr<relational_expression_t> relational_expression_0;

  std::unique_ptr<token_t> ge_op_1;

  std::unique_ptr<shift_expression_t> shift_expression_2;

  relational_expression_relational_expression_ge_op_shift_expression_t(
    std::unique_ptr<relational_expression_t> &&relational_expression_0_,
    std::unique_ptr<token_t> &&ge_op_1_,
    std::unique_ptr<shift_expression_t> &&shift_expression_2_
  ): relational_expression_0(std::move(relational_expression_0_)),
     ge_op_1(std::move(ge_op_1_)),
     shift_expression_2(std::move(shift_expression_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<relational_expression_relational_expression_ge_op_shift_expression_t> make(
    std::unique_ptr<relational_expression_t> &&relational_expression_0_,
    const token_t *GE_OP_1_,
    std::unique_ptr<shift_expression_t> &&shift_expression_2_
  ) {
    return std::make_unique<relational_expression_relational_expression_ge_op_shift_expression_t>(
      std::move(relational_expression_0_),
      std::make_unique<token_t>(*GE_OP_1_),
      std::move(shift_expression_2_)
    );
  }

};  // relational_expression_relational_expression_ge_op_shift_expression_t

}   // ast

}   // gliss
