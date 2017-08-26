#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "constant-expression.h"

/**
 * Patterns for layout_qualifier_id
 *
 * 1. IDENTIFIER
 * 2. IDENTIFIER EQUAL constant_expression
 * 3. SHARED
 */

namespace gliss {

namespace ast {

class constant_expression_t;

class layout_qualifier_id_t: public ast_t {

public:

  static constexpr int rules = 3;

  static constexpr int id = 256;

  virtual ~layout_qualifier_id_t() = default;

};  // layout_qualifier_id_t

class layout_qualifier_id_identifier_t: public layout_qualifier_id_t {

public:

  std::unique_ptr<token_t> identifier_0;

  layout_qualifier_id_identifier_t(
    std::unique_ptr<token_t> &&identifier_0_
  ): identifier_0(std::move(identifier_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<layout_qualifier_id_identifier_t> make(
    const token_t *IDENTIFIER_0_
  ) {
    return std::make_unique<layout_qualifier_id_identifier_t>(
      std::make_unique<token_t>(*IDENTIFIER_0_)
    );
  }

};  // layout_qualifier_id_identifier_t

class layout_qualifier_id_identifier_equal_constant_expression_t: public layout_qualifier_id_t {

public:

  std::unique_ptr<token_t> identifier_0;

  std::unique_ptr<token_t> equal_1;

  std::unique_ptr<constant_expression_t> constant_expression_2;

  layout_qualifier_id_identifier_equal_constant_expression_t(
    std::unique_ptr<token_t> &&identifier_0_,
    std::unique_ptr<token_t> &&equal_1_,
    std::unique_ptr<constant_expression_t> &&constant_expression_2_
  ): identifier_0(std::move(identifier_0_)),
     equal_1(std::move(equal_1_)),
     constant_expression_2(std::move(constant_expression_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<layout_qualifier_id_identifier_equal_constant_expression_t> make(
    const token_t *IDENTIFIER_0_,
    const token_t *EQUAL_1_,
    std::unique_ptr<constant_expression_t> &&constant_expression_2_
  ) {
    return std::make_unique<layout_qualifier_id_identifier_equal_constant_expression_t>(
      std::make_unique<token_t>(*IDENTIFIER_0_),
      std::make_unique<token_t>(*EQUAL_1_),
      std::move(constant_expression_2_)
    );
  }

};  // layout_qualifier_id_identifier_equal_constant_expression_t

class layout_qualifier_id_shared_t: public layout_qualifier_id_t {

public:

  std::unique_ptr<token_t> shared_0;

  layout_qualifier_id_shared_t(
    std::unique_ptr<token_t> &&shared_0_
  ): shared_0(std::move(shared_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<layout_qualifier_id_shared_t> make(
    const token_t *SHARED_0_
  ) {
    return std::make_unique<layout_qualifier_id_shared_t>(
      std::make_unique<token_t>(*SHARED_0_)
    );
  }

};  // layout_qualifier_id_shared_t

}   // ast

}   // gliss
