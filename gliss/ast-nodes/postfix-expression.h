#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "primary-expression.h"

#include "integer-expression.h"
#include "function-call.h"

/**
 * Patterns for postfix_expression
 *
 * 1. primary_expression
 * 2. postfix_expression LEFT_BRACKET integer_expression RIGHT_BRACKET
 * 3. function_call
 * 4. postfix_expression DOT FIELD_SELECTION
 * 5. postfix_expression INC_OP
 * 6. postfix_expression DEC_OP
 */

namespace gliss {

namespace ast {

class primary_expression_t;

class integer_expression_t;
class function_call_t;

class postfix_expression_t: public ast_t {

public:

  static constexpr int rules = 6;

  static constexpr int id = 214;

  virtual ~postfix_expression_t() = default;

};  // postfix_expression_t

class postfix_expression_primary_expression_t: public postfix_expression_t {

public:

  std::shared_ptr<primary_expression_t> primary_expression_0;

  postfix_expression_primary_expression_t(
    std::shared_ptr<primary_expression_t> primary_expression_0_
  ): primary_expression_0(primary_expression_0_) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  virtual int get_id() const override {
    return 214;
  }

  static std::shared_ptr<postfix_expression_primary_expression_t> make(
    std::shared_ptr<primary_expression_t> primary_expression_0_
  ) {
    return std::make_shared<postfix_expression_primary_expression_t>(
      primary_expression_0_
    );
  }

};  // postfix_expression_primary_expression_t

class postfix_expression_postfix_expression_left_bracket_integer_expression_right_bracket_t: public postfix_expression_t {

public:

  std::shared_ptr<postfix_expression_t> postfix_expression_0;

  std::shared_ptr<ast_token_t> left_bracket_1;

  std::shared_ptr<integer_expression_t> integer_expression_2;

  std::shared_ptr<ast_token_t> right_bracket_3;

  postfix_expression_postfix_expression_left_bracket_integer_expression_right_bracket_t(
    std::shared_ptr<postfix_expression_t> postfix_expression_0_,
    std::shared_ptr<ast_token_t> left_bracket_1_,
    std::shared_ptr<integer_expression_t> integer_expression_2_,
    std::shared_ptr<ast_token_t> right_bracket_3_
  ): postfix_expression_0(postfix_expression_0_),
     left_bracket_1(left_bracket_1_),
     integer_expression_2(integer_expression_2_),
     right_bracket_3(right_bracket_3_) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  virtual int get_id() const override {
    return 214;
  }

  static std::shared_ptr<postfix_expression_postfix_expression_left_bracket_integer_expression_right_bracket_t> make(
    std::shared_ptr<postfix_expression_t> postfix_expression_0_,
    std::shared_ptr<ast_token_t> LEFT_BRACKET_1_,
    std::shared_ptr<integer_expression_t> integer_expression_2_,
    std::shared_ptr<ast_token_t> RIGHT_BRACKET_3_
  ) {
    return std::make_shared<postfix_expression_postfix_expression_left_bracket_integer_expression_right_bracket_t>(
      postfix_expression_0_,
      LEFT_BRACKET_1_,
      integer_expression_2_,
      RIGHT_BRACKET_3_
    );
  }

};  // postfix_expression_postfix_expression_left_bracket_integer_expression_right_bracket_t

class postfix_expression_function_call_t: public postfix_expression_t {

public:

  std::shared_ptr<function_call_t> function_call_0;

  postfix_expression_function_call_t(
    std::shared_ptr<function_call_t> function_call_0_
  ): function_call_0(function_call_0_) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  virtual int get_id() const override {
    return 214;
  }

  static std::shared_ptr<postfix_expression_function_call_t> make(
    std::shared_ptr<function_call_t> function_call_0_
  ) {
    return std::make_shared<postfix_expression_function_call_t>(
      function_call_0_
    );
  }

};  // postfix_expression_function_call_t

class postfix_expression_postfix_expression_dot_field_selection_t: public postfix_expression_t {

public:

  std::shared_ptr<postfix_expression_t> postfix_expression_0;

  std::shared_ptr<ast_token_t> dot_1;

  std::shared_ptr<ast_token_t> field_selection_2;

  postfix_expression_postfix_expression_dot_field_selection_t(
    std::shared_ptr<postfix_expression_t> postfix_expression_0_,
    std::shared_ptr<ast_token_t> dot_1_,
    std::shared_ptr<ast_token_t> field_selection_2_
  ): postfix_expression_0(postfix_expression_0_),
     dot_1(dot_1_),
     field_selection_2(field_selection_2_) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  virtual int get_id() const override {
    return 214;
  }

  static std::shared_ptr<postfix_expression_postfix_expression_dot_field_selection_t> make(
    std::shared_ptr<postfix_expression_t> postfix_expression_0_,
    std::shared_ptr<ast_token_t> DOT_1_,
    std::shared_ptr<ast_token_t> FIELD_SELECTION_2_
  ) {
    return std::make_shared<postfix_expression_postfix_expression_dot_field_selection_t>(
      postfix_expression_0_,
      DOT_1_,
      FIELD_SELECTION_2_
    );
  }

};  // postfix_expression_postfix_expression_dot_field_selection_t

class postfix_expression_postfix_expression_inc_op_t: public postfix_expression_t {

public:

  std::shared_ptr<postfix_expression_t> postfix_expression_0;

  std::shared_ptr<ast_token_t> inc_op_1;

  postfix_expression_postfix_expression_inc_op_t(
    std::shared_ptr<postfix_expression_t> postfix_expression_0_,
    std::shared_ptr<ast_token_t> inc_op_1_
  ): postfix_expression_0(postfix_expression_0_),
     inc_op_1(inc_op_1_) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  virtual int get_id() const override {
    return 214;
  }

  static std::shared_ptr<postfix_expression_postfix_expression_inc_op_t> make(
    std::shared_ptr<postfix_expression_t> postfix_expression_0_,
    std::shared_ptr<ast_token_t> INC_OP_1_
  ) {
    return std::make_shared<postfix_expression_postfix_expression_inc_op_t>(
      postfix_expression_0_,
      INC_OP_1_
    );
  }

};  // postfix_expression_postfix_expression_inc_op_t

class postfix_expression_postfix_expression_dec_op_t: public postfix_expression_t {

public:

  std::shared_ptr<postfix_expression_t> postfix_expression_0;

  std::shared_ptr<ast_token_t> dec_op_1;

  postfix_expression_postfix_expression_dec_op_t(
    std::shared_ptr<postfix_expression_t> postfix_expression_0_,
    std::shared_ptr<ast_token_t> dec_op_1_
  ): postfix_expression_0(postfix_expression_0_),
     dec_op_1(dec_op_1_) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  virtual int get_id() const override {
    return 214;
  }

  static std::shared_ptr<postfix_expression_postfix_expression_dec_op_t> make(
    std::shared_ptr<postfix_expression_t> postfix_expression_0_,
    std::shared_ptr<ast_token_t> DEC_OP_1_
  ) {
    return std::make_shared<postfix_expression_postfix_expression_dec_op_t>(
      postfix_expression_0_,
      DEC_OP_1_
    );
  }

};  // postfix_expression_postfix_expression_dec_op_t

}   // ast

}   // gliss
