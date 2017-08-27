#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "expression.h"
#include "fully-specified-type.h"
#include "initializer.h"

/**
 * Patterns for condition
 *
 * 1. expression
 * 2. fully_specified_type IDENTIFIER EQUAL initializer
 */

namespace gliss {

namespace ast {

class expression_t;
class fully_specified_type_t;
class initializer_t;

class condition_t: public ast_t {

public:

  static constexpr int rules = 2;

  static constexpr int id = 284;

  virtual ~condition_t() = default;

};  // condition_t

class condition_expression_t: public condition_t {

public:

  std::shared_ptr<expression_t> expression_0;

  condition_expression_t(
    std::shared_ptr<expression_t> expression_0_
  ): expression_0(expression_0_) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  virtual int get_id() const override {
    return 284;
  }

  static std::shared_ptr<condition_expression_t> make(
    std::shared_ptr<expression_t> expression_0_
  ) {
    return std::make_shared<condition_expression_t>(
      expression_0_
    );
  }

};  // condition_expression_t

class condition_fully_specified_type_identifier_equal_initializer_t: public condition_t {

public:

  std::shared_ptr<fully_specified_type_t> fully_specified_type_0;

  std::shared_ptr<ast_token_t> identifier_1;

  std::shared_ptr<ast_token_t> equal_2;

  std::shared_ptr<initializer_t> initializer_3;

  condition_fully_specified_type_identifier_equal_initializer_t(
    std::shared_ptr<fully_specified_type_t> fully_specified_type_0_,
    std::shared_ptr<ast_token_t> identifier_1_,
    std::shared_ptr<ast_token_t> equal_2_,
    std::shared_ptr<initializer_t> initializer_3_
  ): fully_specified_type_0(fully_specified_type_0_),
     identifier_1(identifier_1_),
     equal_2(equal_2_),
     initializer_3(initializer_3_) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  virtual int get_id() const override {
    return 284;
  }

  static std::shared_ptr<condition_fully_specified_type_identifier_equal_initializer_t> make(
    std::shared_ptr<fully_specified_type_t> fully_specified_type_0_,
    std::shared_ptr<ast_token_t> IDENTIFIER_1_,
    std::shared_ptr<ast_token_t> EQUAL_2_,
    std::shared_ptr<initializer_t> initializer_3_
  ) {
    return std::make_shared<condition_fully_specified_type_identifier_equal_initializer_t>(
      fully_specified_type_0_,
      IDENTIFIER_1_,
      EQUAL_2_,
      initializer_3_
    );
  }

};  // condition_fully_specified_type_identifier_equal_initializer_t

}   // ast

}   // gliss
