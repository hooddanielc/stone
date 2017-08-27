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

  static constexpr int id = 228;

  virtual ~relational_expression_t() = default;

};  // relational_expression_t

class relational_expression_shift_expression_t: public relational_expression_t {

public:

  std::shared_ptr<shift_expression_t> shift_expression_0;

  relational_expression_shift_expression_t(
    std::shared_ptr<shift_expression_t> shift_expression_0_
  ): shift_expression_0(shift_expression_0_) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  virtual int get_id() const override {
    return 228;
  }

  static std::shared_ptr<relational_expression_shift_expression_t> make(
    std::shared_ptr<shift_expression_t> shift_expression_0_
  ) {
    return std::make_shared<relational_expression_shift_expression_t>(
      shift_expression_0_
    );
  }

};  // relational_expression_shift_expression_t

class relational_expression_relational_expression_left_angle_shift_expression_t: public relational_expression_t {

public:

  std::shared_ptr<relational_expression_t> relational_expression_0;

  std::shared_ptr<ast_token_t> left_angle_1;

  std::shared_ptr<shift_expression_t> shift_expression_2;

  relational_expression_relational_expression_left_angle_shift_expression_t(
    std::shared_ptr<relational_expression_t> relational_expression_0_,
    std::shared_ptr<ast_token_t> left_angle_1_,
    std::shared_ptr<shift_expression_t> shift_expression_2_
  ): relational_expression_0(relational_expression_0_),
     left_angle_1(left_angle_1_),
     shift_expression_2(shift_expression_2_) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  virtual int get_id() const override {
    return 228;
  }

  static std::shared_ptr<relational_expression_relational_expression_left_angle_shift_expression_t> make(
    std::shared_ptr<relational_expression_t> relational_expression_0_,
    std::shared_ptr<ast_token_t> LEFT_ANGLE_1_,
    std::shared_ptr<shift_expression_t> shift_expression_2_
  ) {
    return std::make_shared<relational_expression_relational_expression_left_angle_shift_expression_t>(
      relational_expression_0_,
      LEFT_ANGLE_1_,
      shift_expression_2_
    );
  }

};  // relational_expression_relational_expression_left_angle_shift_expression_t

class relational_expression_relational_expression_right_angle_shift_expression_t: public relational_expression_t {

public:

  std::shared_ptr<relational_expression_t> relational_expression_0;

  std::shared_ptr<ast_token_t> right_angle_1;

  std::shared_ptr<shift_expression_t> shift_expression_2;

  relational_expression_relational_expression_right_angle_shift_expression_t(
    std::shared_ptr<relational_expression_t> relational_expression_0_,
    std::shared_ptr<ast_token_t> right_angle_1_,
    std::shared_ptr<shift_expression_t> shift_expression_2_
  ): relational_expression_0(relational_expression_0_),
     right_angle_1(right_angle_1_),
     shift_expression_2(shift_expression_2_) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  virtual int get_id() const override {
    return 228;
  }

  static std::shared_ptr<relational_expression_relational_expression_right_angle_shift_expression_t> make(
    std::shared_ptr<relational_expression_t> relational_expression_0_,
    std::shared_ptr<ast_token_t> RIGHT_ANGLE_1_,
    std::shared_ptr<shift_expression_t> shift_expression_2_
  ) {
    return std::make_shared<relational_expression_relational_expression_right_angle_shift_expression_t>(
      relational_expression_0_,
      RIGHT_ANGLE_1_,
      shift_expression_2_
    );
  }

};  // relational_expression_relational_expression_right_angle_shift_expression_t

class relational_expression_relational_expression_le_op_shift_expression_t: public relational_expression_t {

public:

  std::shared_ptr<relational_expression_t> relational_expression_0;

  std::shared_ptr<ast_token_t> le_op_1;

  std::shared_ptr<shift_expression_t> shift_expression_2;

  relational_expression_relational_expression_le_op_shift_expression_t(
    std::shared_ptr<relational_expression_t> relational_expression_0_,
    std::shared_ptr<ast_token_t> le_op_1_,
    std::shared_ptr<shift_expression_t> shift_expression_2_
  ): relational_expression_0(relational_expression_0_),
     le_op_1(le_op_1_),
     shift_expression_2(shift_expression_2_) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  virtual int get_id() const override {
    return 228;
  }

  static std::shared_ptr<relational_expression_relational_expression_le_op_shift_expression_t> make(
    std::shared_ptr<relational_expression_t> relational_expression_0_,
    std::shared_ptr<ast_token_t> LE_OP_1_,
    std::shared_ptr<shift_expression_t> shift_expression_2_
  ) {
    return std::make_shared<relational_expression_relational_expression_le_op_shift_expression_t>(
      relational_expression_0_,
      LE_OP_1_,
      shift_expression_2_
    );
  }

};  // relational_expression_relational_expression_le_op_shift_expression_t

class relational_expression_relational_expression_ge_op_shift_expression_t: public relational_expression_t {

public:

  std::shared_ptr<relational_expression_t> relational_expression_0;

  std::shared_ptr<ast_token_t> ge_op_1;

  std::shared_ptr<shift_expression_t> shift_expression_2;

  relational_expression_relational_expression_ge_op_shift_expression_t(
    std::shared_ptr<relational_expression_t> relational_expression_0_,
    std::shared_ptr<ast_token_t> ge_op_1_,
    std::shared_ptr<shift_expression_t> shift_expression_2_
  ): relational_expression_0(relational_expression_0_),
     ge_op_1(ge_op_1_),
     shift_expression_2(shift_expression_2_) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  virtual int get_id() const override {
    return 228;
  }

  static std::shared_ptr<relational_expression_relational_expression_ge_op_shift_expression_t> make(
    std::shared_ptr<relational_expression_t> relational_expression_0_,
    std::shared_ptr<ast_token_t> GE_OP_1_,
    std::shared_ptr<shift_expression_t> shift_expression_2_
  ) {
    return std::make_shared<relational_expression_relational_expression_ge_op_shift_expression_t>(
      relational_expression_0_,
      GE_OP_1_,
      shift_expression_2_
    );
  }

};  // relational_expression_relational_expression_ge_op_shift_expression_t

}   // ast

}   // gliss
