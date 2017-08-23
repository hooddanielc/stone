#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "fully-specified-type.h"
#include "array-specifier.h"
#include "initializer.h"

/**
 * Patterns for single_declaration
 *
 * 1. fully_specified_type
 * 2. fully_specified_type IDENTIFIER
 * 3. fully_specified_type IDENTIFIER array_specifier
 * 4. fully_specified_type IDENTIFIER array_specifier EQUAL initializer
 * 5. fully_specified_type IDENTIFIER EQUAL initializer
 */

namespace gliss {

namespace ast {

class fully_specified_type_t;
class array_specifier_t;
class initializer_t;

class single_declaration_t: public ast_t {

public:

  static constexpr int num_types = 5;

  virtual ~single_declaration_t() = default;

};  // single_declaration_t

class single_declaration_fully_specified_type_t: public single_declaration_t {

public:

  std::unique_ptr<fully_specified_type_t> fully_specified_type_0;

  single_declaration_fully_specified_type_t(
    std::unique_ptr<fully_specified_type_t> &&fully_specified_type_0_
  ): fully_specified_type_0(std::move(fully_specified_type_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<single_declaration_fully_specified_type_t> make(
    std::unique_ptr<fully_specified_type_t> &&fully_specified_type_0_
  ) {
    return std::make_unique<single_declaration_fully_specified_type_t>(
      std::move(fully_specified_type_0_)
    );
  }

};  // single_declaration_fully_specified_type_t

class single_declaration_fully_specified_type_identifier_t: public single_declaration_t {

public:

  std::unique_ptr<fully_specified_type_t> fully_specified_type_0;

  std::unique_ptr<token_t> identifier_1;

  single_declaration_fully_specified_type_identifier_t(
    std::unique_ptr<fully_specified_type_t> &&fully_specified_type_0_,
    std::unique_ptr<token_t> &&identifier_1_
  ): fully_specified_type_0(std::move(fully_specified_type_0_)),
     identifier_1(std::move(identifier_1_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<single_declaration_fully_specified_type_identifier_t> make(
    std::unique_ptr<fully_specified_type_t> &&fully_specified_type_0_,
    const token_t *IDENTIFIER_1_
  ) {
    return std::make_unique<single_declaration_fully_specified_type_identifier_t>(
      std::move(fully_specified_type_0_),
      std::make_unique<token_t>(*IDENTIFIER_1_)
    );
  }

};  // single_declaration_fully_specified_type_identifier_t

class single_declaration_fully_specified_type_identifier_array_specifier_t: public single_declaration_t {

public:

  std::unique_ptr<fully_specified_type_t> fully_specified_type_0;

  std::unique_ptr<token_t> identifier_1;

  std::unique_ptr<array_specifier_t> array_specifier_2;

  single_declaration_fully_specified_type_identifier_array_specifier_t(
    std::unique_ptr<fully_specified_type_t> &&fully_specified_type_0_,
    std::unique_ptr<token_t> &&identifier_1_,
    std::unique_ptr<array_specifier_t> &&array_specifier_2_
  ): fully_specified_type_0(std::move(fully_specified_type_0_)),
     identifier_1(std::move(identifier_1_)),
     array_specifier_2(std::move(array_specifier_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<single_declaration_fully_specified_type_identifier_array_specifier_t> make(
    std::unique_ptr<fully_specified_type_t> &&fully_specified_type_0_,
    const token_t *IDENTIFIER_1_,
    std::unique_ptr<array_specifier_t> &&array_specifier_2_
  ) {
    return std::make_unique<single_declaration_fully_specified_type_identifier_array_specifier_t>(
      std::move(fully_specified_type_0_),
      std::make_unique<token_t>(*IDENTIFIER_1_),
      std::move(array_specifier_2_)
    );
  }

};  // single_declaration_fully_specified_type_identifier_array_specifier_t

class single_declaration_fully_specified_type_identifier_array_specifier_equal_initializer_t: public single_declaration_t {

public:

  std::unique_ptr<fully_specified_type_t> fully_specified_type_0;

  std::unique_ptr<token_t> identifier_1;

  std::unique_ptr<array_specifier_t> array_specifier_2;

  std::unique_ptr<token_t> equal_3;

  std::unique_ptr<initializer_t> initializer_4;

  single_declaration_fully_specified_type_identifier_array_specifier_equal_initializer_t(
    std::unique_ptr<fully_specified_type_t> &&fully_specified_type_0_,
    std::unique_ptr<token_t> &&identifier_1_,
    std::unique_ptr<array_specifier_t> &&array_specifier_2_,
    std::unique_ptr<token_t> &&equal_3_,
    std::unique_ptr<initializer_t> &&initializer_4_
  ): fully_specified_type_0(std::move(fully_specified_type_0_)),
     identifier_1(std::move(identifier_1_)),
     array_specifier_2(std::move(array_specifier_2_)),
     equal_3(std::move(equal_3_)),
     initializer_4(std::move(initializer_4_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<single_declaration_fully_specified_type_identifier_array_specifier_equal_initializer_t> make(
    std::unique_ptr<fully_specified_type_t> &&fully_specified_type_0_,
    const token_t *IDENTIFIER_1_,
    std::unique_ptr<array_specifier_t> &&array_specifier_2_,
    const token_t *EQUAL_3_,
    std::unique_ptr<initializer_t> &&initializer_4_
  ) {
    return std::make_unique<single_declaration_fully_specified_type_identifier_array_specifier_equal_initializer_t>(
      std::move(fully_specified_type_0_),
      std::make_unique<token_t>(*IDENTIFIER_1_),
      std::move(array_specifier_2_),
      std::make_unique<token_t>(*EQUAL_3_),
      std::move(initializer_4_)
    );
  }

};  // single_declaration_fully_specified_type_identifier_array_specifier_equal_initializer_t

class single_declaration_fully_specified_type_identifier_equal_initializer_t: public single_declaration_t {

public:

  std::unique_ptr<fully_specified_type_t> fully_specified_type_0;

  std::unique_ptr<token_t> identifier_1;

  std::unique_ptr<token_t> equal_2;

  std::unique_ptr<initializer_t> initializer_3;

  single_declaration_fully_specified_type_identifier_equal_initializer_t(
    std::unique_ptr<fully_specified_type_t> &&fully_specified_type_0_,
    std::unique_ptr<token_t> &&identifier_1_,
    std::unique_ptr<token_t> &&equal_2_,
    std::unique_ptr<initializer_t> &&initializer_3_
  ): fully_specified_type_0(std::move(fully_specified_type_0_)),
     identifier_1(std::move(identifier_1_)),
     equal_2(std::move(equal_2_)),
     initializer_3(std::move(initializer_3_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<single_declaration_fully_specified_type_identifier_equal_initializer_t> make(
    std::unique_ptr<fully_specified_type_t> &&fully_specified_type_0_,
    const token_t *IDENTIFIER_1_,
    const token_t *EQUAL_2_,
    std::unique_ptr<initializer_t> &&initializer_3_
  ) {
    return std::make_unique<single_declaration_fully_specified_type_identifier_equal_initializer_t>(
      std::move(fully_specified_type_0_),
      std::make_unique<token_t>(*IDENTIFIER_1_),
      std::make_unique<token_t>(*EQUAL_2_),
      std::move(initializer_3_)
    );
  }

};  // single_declaration_fully_specified_type_identifier_equal_initializer_t

}   // ast

}   // gliss
