#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "array-specifier.h"

/**
 * Patterns for struct_declarator
 *
 * 1. IDENTIFIER
 * 2. IDENTIFIER array_specifier
 */

namespace gliss {

namespace ast {

class array_specifier_t;

class struct_declarator_t: public ast_t {

public:

  static constexpr int rules = 2;

  static constexpr int id = 270;

  virtual ~struct_declarator_t() = default;

};  // struct_declarator_t

class struct_declarator_identifier_t: public struct_declarator_t {

public:

  std::unique_ptr<token_t> identifier_0;

  struct_declarator_identifier_t(
    std::unique_ptr<token_t> &&identifier_0_
  ): identifier_0(std::move(identifier_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<struct_declarator_identifier_t> make(
    const token_t *IDENTIFIER_0_
  ) {
    return std::make_unique<struct_declarator_identifier_t>(
      std::make_unique<token_t>(*IDENTIFIER_0_)
    );
  }

};  // struct_declarator_identifier_t

class struct_declarator_identifier_array_specifier_t: public struct_declarator_t {

public:

  std::unique_ptr<token_t> identifier_0;

  std::unique_ptr<array_specifier_t> array_specifier_1;

  struct_declarator_identifier_array_specifier_t(
    std::unique_ptr<token_t> &&identifier_0_,
    std::unique_ptr<array_specifier_t> &&array_specifier_1_
  ): identifier_0(std::move(identifier_0_)),
     array_specifier_1(std::move(array_specifier_1_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<struct_declarator_identifier_array_specifier_t> make(
    const token_t *IDENTIFIER_0_,
    std::unique_ptr<array_specifier_t> &&array_specifier_1_
  ) {
    return std::make_unique<struct_declarator_identifier_array_specifier_t>(
      std::make_unique<token_t>(*IDENTIFIER_0_),
      std::move(array_specifier_1_)
    );
  }

};  // struct_declarator_identifier_array_specifier_t

}   // ast

}   // gliss
