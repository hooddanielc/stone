#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "function-call-header-with-parameters.h"
#include "function-call-header-no-parameters.h"

/**
 * Patterns for function_call_generic
 *
 * 1. function_call_header_with_parameters RIGHT_PAREN
 * 2. function_call_header_no_parameters RIGHT_PAREN
 */

namespace gliss {

namespace ast {

class function_call_header_with_parameters_t;
class function_call_header_no_parameters_t;

class function_call_generic_t: public ast_t {

public:

  static constexpr int rules = 2;

  static constexpr int id = 217;

  virtual ~function_call_generic_t() = default;

};  // function_call_generic_t

class function_call_generic_function_call_header_with_parameters_right_paren_t: public function_call_generic_t {

public:

  std::unique_ptr<function_call_header_with_parameters_t> function_call_header_with_parameters_0;

  std::unique_ptr<token_t> right_paren_1;

  function_call_generic_function_call_header_with_parameters_right_paren_t(
    std::unique_ptr<function_call_header_with_parameters_t> &&function_call_header_with_parameters_0_,
    std::unique_ptr<token_t> &&right_paren_1_
  ): function_call_header_with_parameters_0(std::move(function_call_header_with_parameters_0_)),
     right_paren_1(std::move(right_paren_1_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<function_call_generic_function_call_header_with_parameters_right_paren_t> make(
    std::unique_ptr<function_call_header_with_parameters_t> &&function_call_header_with_parameters_0_,
    const token_t *RIGHT_PAREN_1_
  ) {
    return std::make_unique<function_call_generic_function_call_header_with_parameters_right_paren_t>(
      std::move(function_call_header_with_parameters_0_),
      std::make_unique<token_t>(*RIGHT_PAREN_1_)
    );
  }

};  // function_call_generic_function_call_header_with_parameters_right_paren_t

class function_call_generic_function_call_header_no_parameters_right_paren_t: public function_call_generic_t {

public:

  std::unique_ptr<function_call_header_no_parameters_t> function_call_header_no_parameters_0;

  std::unique_ptr<token_t> right_paren_1;

  function_call_generic_function_call_header_no_parameters_right_paren_t(
    std::unique_ptr<function_call_header_no_parameters_t> &&function_call_header_no_parameters_0_,
    std::unique_ptr<token_t> &&right_paren_1_
  ): function_call_header_no_parameters_0(std::move(function_call_header_no_parameters_0_)),
     right_paren_1(std::move(right_paren_1_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<function_call_generic_function_call_header_no_parameters_right_paren_t> make(
    std::unique_ptr<function_call_header_no_parameters_t> &&function_call_header_no_parameters_0_,
    const token_t *RIGHT_PAREN_1_
  ) {
    return std::make_unique<function_call_generic_function_call_header_no_parameters_right_paren_t>(
      std::move(function_call_header_no_parameters_0_),
      std::make_unique<token_t>(*RIGHT_PAREN_1_)
    );
  }

};  // function_call_generic_function_call_header_no_parameters_right_paren_t

}   // ast

}   // gliss
