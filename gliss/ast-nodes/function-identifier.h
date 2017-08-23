#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "type-specifier.h"
#include "postfix-expression.h"

/**
 * Patterns for function_identifier
 *
 * 1. type_specifier
 * 2. postfix_expression
 */

namespace gliss {

namespace ast {

class type_specifier_t;
class postfix_expression_t;

class function_identifier_t: public ast_t {

public:

  static constexpr int num_types = 2;

  virtual ~function_identifier_t() = default;

};  // function_identifier_t

class function_identifier_type_specifier_t: public function_identifier_t {

public:

  std::unique_ptr<type_specifier_t> type_specifier_0;

  function_identifier_type_specifier_t(
    std::unique_ptr<type_specifier_t> &&type_specifier_0_
  ): type_specifier_0(std::move(type_specifier_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<function_identifier_type_specifier_t> make(
    std::unique_ptr<type_specifier_t> &&type_specifier_0_
  ) {
    return std::make_unique<function_identifier_type_specifier_t>(
      std::move(type_specifier_0_)
    );
  }

};  // function_identifier_type_specifier_t

class function_identifier_postfix_expression_t: public function_identifier_t {

public:

  std::unique_ptr<postfix_expression_t> postfix_expression_0;

  function_identifier_postfix_expression_t(
    std::unique_ptr<postfix_expression_t> &&postfix_expression_0_
  ): postfix_expression_0(std::move(postfix_expression_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<function_identifier_postfix_expression_t> make(
    std::unique_ptr<postfix_expression_t> &&postfix_expression_0_
  ) {
    return std::make_unique<function_identifier_postfix_expression_t>(
      std::move(postfix_expression_0_)
    );
  }

};  // function_identifier_postfix_expression_t

}   // ast

}   // gliss
