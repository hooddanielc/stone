#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "fully-specified-type.h"

/**
 * Patterns for function_header
 *
 * 1. fully_specified_type IDENTIFIER LEFT_PAREN
 */

namespace gliss {

namespace ast {

class fully_specified_type_t;

class function_header_t: public ast_t {

public:

  static constexpr int num_types = 1;

  virtual ~function_header_t() = default;

};  // function_header_t

class function_header_fully_specified_type_identifier_left_paren_t: public function_header_t {

public:

  std::unique_ptr<fully_specified_type_t> fully_specified_type_0;

  std::unique_ptr<token_t> identifier_1;

  std::unique_ptr<token_t> left_paren_2;

  function_header_fully_specified_type_identifier_left_paren_t(
    std::unique_ptr<fully_specified_type_t> &&fully_specified_type_0_,
    std::unique_ptr<token_t> &&identifier_1_,
    std::unique_ptr<token_t> &&left_paren_2_
  ): fully_specified_type_0(std::move(fully_specified_type_0_)),
     identifier_1(std::move(identifier_1_)),
     left_paren_2(std::move(left_paren_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<function_header_fully_specified_type_identifier_left_paren_t> make(
    std::unique_ptr<fully_specified_type_t> &&fully_specified_type_0_,
    const token_t *IDENTIFIER_1_,
    const token_t *LEFT_PAREN_2_
  ) {
    return std::make_unique<function_header_fully_specified_type_identifier_left_paren_t>(
      std::move(fully_specified_type_0_),
      std::make_unique<token_t>(*IDENTIFIER_1_),
      std::make_unique<token_t>(*LEFT_PAREN_2_)
    );
  }

};  // function_header_fully_specified_type_identifier_left_paren_t

}   // ast

}   // gliss
