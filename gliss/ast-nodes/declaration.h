#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "function-prototype.h"
#include "init-declarator-list.h"
#include "precision-qualifier.h"
#include "type-specifier.h"
#include "type-qualifier.h"
#include "struct-declaration-list.h"
#include "array-specifier.h"
#include "identifier-list.h"

/**
 * Patterns for declaration
 *
 * 1. function_prototype SEMICOLON
 * 2. init_declarator_list SEMICOLON
 * 3. PRECISION precision_qualifier type_specifier SEMICOLON
 * 4. type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE SEMICOLON
 * 5. type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER SEMICOLON
 * 6. type_qualifier IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE IDENTIFIER array_specifier SEMICOLON
 * 7. type_qualifier SEMICOLON
 * 8. type_qualifier IDENTIFIER SEMICOLON
 * 9. type_qualifier IDENTIFIER identifier_list SEMICOLON
 */

namespace gliss {

namespace ast {

class function_prototype_t;
class init_declarator_list_t;
class precision_qualifier_t;
class type_specifier_t;
class type_qualifier_t;
class struct_declaration_list_t;
class array_specifier_t;
class identifier_list_t;

class declaration_t: public ast_t {

public:

  static constexpr int rules = 9;

  static constexpr int id = 240;

  virtual ~declaration_t() = default;

};  // declaration_t

class declaration_function_prototype_semicolon_t: public declaration_t {

public:

  std::unique_ptr<function_prototype_t> function_prototype_0;

  std::unique_ptr<token_t> semicolon_1;

  declaration_function_prototype_semicolon_t(
    std::unique_ptr<function_prototype_t> &&function_prototype_0_,
    std::unique_ptr<token_t> &&semicolon_1_
  ): function_prototype_0(std::move(function_prototype_0_)),
     semicolon_1(std::move(semicolon_1_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<declaration_function_prototype_semicolon_t> make(
    std::unique_ptr<function_prototype_t> &&function_prototype_0_,
    const token_t *SEMICOLON_1_
  ) {
    return std::make_unique<declaration_function_prototype_semicolon_t>(
      std::move(function_prototype_0_),
      std::make_unique<token_t>(*SEMICOLON_1_)
    );
  }

};  // declaration_function_prototype_semicolon_t

class declaration_init_declarator_list_semicolon_t: public declaration_t {

public:

  std::unique_ptr<init_declarator_list_t> init_declarator_list_0;

  std::unique_ptr<token_t> semicolon_1;

  declaration_init_declarator_list_semicolon_t(
    std::unique_ptr<init_declarator_list_t> &&init_declarator_list_0_,
    std::unique_ptr<token_t> &&semicolon_1_
  ): init_declarator_list_0(std::move(init_declarator_list_0_)),
     semicolon_1(std::move(semicolon_1_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<declaration_init_declarator_list_semicolon_t> make(
    std::unique_ptr<init_declarator_list_t> &&init_declarator_list_0_,
    const token_t *SEMICOLON_1_
  ) {
    return std::make_unique<declaration_init_declarator_list_semicolon_t>(
      std::move(init_declarator_list_0_),
      std::make_unique<token_t>(*SEMICOLON_1_)
    );
  }

};  // declaration_init_declarator_list_semicolon_t

class declaration_precision_precision_qualifier_type_specifier_semicolon_t: public declaration_t {

public:

  std::unique_ptr<token_t> precision_0;

  std::unique_ptr<precision_qualifier_t> precision_qualifier_1;

  std::unique_ptr<type_specifier_t> type_specifier_2;

  std::unique_ptr<token_t> semicolon_3;

  declaration_precision_precision_qualifier_type_specifier_semicolon_t(
    std::unique_ptr<token_t> &&precision_0_,
    std::unique_ptr<precision_qualifier_t> &&precision_qualifier_1_,
    std::unique_ptr<type_specifier_t> &&type_specifier_2_,
    std::unique_ptr<token_t> &&semicolon_3_
  ): precision_0(std::move(precision_0_)),
     precision_qualifier_1(std::move(precision_qualifier_1_)),
     type_specifier_2(std::move(type_specifier_2_)),
     semicolon_3(std::move(semicolon_3_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<declaration_precision_precision_qualifier_type_specifier_semicolon_t> make(
    const token_t *PRECISION_0_,
    std::unique_ptr<precision_qualifier_t> &&precision_qualifier_1_,
    std::unique_ptr<type_specifier_t> &&type_specifier_2_,
    const token_t *SEMICOLON_3_
  ) {
    return std::make_unique<declaration_precision_precision_qualifier_type_specifier_semicolon_t>(
      std::make_unique<token_t>(*PRECISION_0_),
      std::move(precision_qualifier_1_),
      std::move(type_specifier_2_),
      std::make_unique<token_t>(*SEMICOLON_3_)
    );
  }

};  // declaration_precision_precision_qualifier_type_specifier_semicolon_t

class declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_semicolon_t: public declaration_t {

public:

  std::unique_ptr<type_qualifier_t> type_qualifier_0;

  std::unique_ptr<token_t> identifier_1;

  std::unique_ptr<token_t> left_brace_2;

  std::unique_ptr<struct_declaration_list_t> struct_declaration_list_3;

  std::unique_ptr<token_t> right_brace_4;

  std::unique_ptr<token_t> semicolon_5;

  declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_semicolon_t(
    std::unique_ptr<type_qualifier_t> &&type_qualifier_0_,
    std::unique_ptr<token_t> &&identifier_1_,
    std::unique_ptr<token_t> &&left_brace_2_,
    std::unique_ptr<struct_declaration_list_t> &&struct_declaration_list_3_,
    std::unique_ptr<token_t> &&right_brace_4_,
    std::unique_ptr<token_t> &&semicolon_5_
  ): type_qualifier_0(std::move(type_qualifier_0_)),
     identifier_1(std::move(identifier_1_)),
     left_brace_2(std::move(left_brace_2_)),
     struct_declaration_list_3(std::move(struct_declaration_list_3_)),
     right_brace_4(std::move(right_brace_4_)),
     semicolon_5(std::move(semicolon_5_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_semicolon_t> make(
    std::unique_ptr<type_qualifier_t> &&type_qualifier_0_,
    const token_t *IDENTIFIER_1_,
    const token_t *LEFT_BRACE_2_,
    std::unique_ptr<struct_declaration_list_t> &&struct_declaration_list_3_,
    const token_t *RIGHT_BRACE_4_,
    const token_t *SEMICOLON_5_
  ) {
    return std::make_unique<declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_semicolon_t>(
      std::move(type_qualifier_0_),
      std::make_unique<token_t>(*IDENTIFIER_1_),
      std::make_unique<token_t>(*LEFT_BRACE_2_),
      std::move(struct_declaration_list_3_),
      std::make_unique<token_t>(*RIGHT_BRACE_4_),
      std::make_unique<token_t>(*SEMICOLON_5_)
    );
  }

};  // declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_semicolon_t

class declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_semicolon_t: public declaration_t {

public:

  std::unique_ptr<type_qualifier_t> type_qualifier_0;

  std::unique_ptr<token_t> identifier_1;

  std::unique_ptr<token_t> left_brace_2;

  std::unique_ptr<struct_declaration_list_t> struct_declaration_list_3;

  std::unique_ptr<token_t> right_brace_4;

  std::unique_ptr<token_t> identifier_5;

  std::unique_ptr<token_t> semicolon_6;

  declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_semicolon_t(
    std::unique_ptr<type_qualifier_t> &&type_qualifier_0_,
    std::unique_ptr<token_t> &&identifier_1_,
    std::unique_ptr<token_t> &&left_brace_2_,
    std::unique_ptr<struct_declaration_list_t> &&struct_declaration_list_3_,
    std::unique_ptr<token_t> &&right_brace_4_,
    std::unique_ptr<token_t> &&identifier_5_,
    std::unique_ptr<token_t> &&semicolon_6_
  ): type_qualifier_0(std::move(type_qualifier_0_)),
     identifier_1(std::move(identifier_1_)),
     left_brace_2(std::move(left_brace_2_)),
     struct_declaration_list_3(std::move(struct_declaration_list_3_)),
     right_brace_4(std::move(right_brace_4_)),
     identifier_5(std::move(identifier_5_)),
     semicolon_6(std::move(semicolon_6_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_semicolon_t> make(
    std::unique_ptr<type_qualifier_t> &&type_qualifier_0_,
    const token_t *IDENTIFIER_1_,
    const token_t *LEFT_BRACE_2_,
    std::unique_ptr<struct_declaration_list_t> &&struct_declaration_list_3_,
    const token_t *RIGHT_BRACE_4_,
    const token_t *IDENTIFIER_5_,
    const token_t *SEMICOLON_6_
  ) {
    return std::make_unique<declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_semicolon_t>(
      std::move(type_qualifier_0_),
      std::make_unique<token_t>(*IDENTIFIER_1_),
      std::make_unique<token_t>(*LEFT_BRACE_2_),
      std::move(struct_declaration_list_3_),
      std::make_unique<token_t>(*RIGHT_BRACE_4_),
      std::make_unique<token_t>(*IDENTIFIER_5_),
      std::make_unique<token_t>(*SEMICOLON_6_)
    );
  }

};  // declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_semicolon_t

class declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_array_specifier_semicolon_t: public declaration_t {

public:

  std::unique_ptr<type_qualifier_t> type_qualifier_0;

  std::unique_ptr<token_t> identifier_1;

  std::unique_ptr<token_t> left_brace_2;

  std::unique_ptr<struct_declaration_list_t> struct_declaration_list_3;

  std::unique_ptr<token_t> right_brace_4;

  std::unique_ptr<token_t> identifier_5;

  std::unique_ptr<array_specifier_t> array_specifier_6;

  std::unique_ptr<token_t> semicolon_7;

  declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_array_specifier_semicolon_t(
    std::unique_ptr<type_qualifier_t> &&type_qualifier_0_,
    std::unique_ptr<token_t> &&identifier_1_,
    std::unique_ptr<token_t> &&left_brace_2_,
    std::unique_ptr<struct_declaration_list_t> &&struct_declaration_list_3_,
    std::unique_ptr<token_t> &&right_brace_4_,
    std::unique_ptr<token_t> &&identifier_5_,
    std::unique_ptr<array_specifier_t> &&array_specifier_6_,
    std::unique_ptr<token_t> &&semicolon_7_
  ): type_qualifier_0(std::move(type_qualifier_0_)),
     identifier_1(std::move(identifier_1_)),
     left_brace_2(std::move(left_brace_2_)),
     struct_declaration_list_3(std::move(struct_declaration_list_3_)),
     right_brace_4(std::move(right_brace_4_)),
     identifier_5(std::move(identifier_5_)),
     array_specifier_6(std::move(array_specifier_6_)),
     semicolon_7(std::move(semicolon_7_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_array_specifier_semicolon_t> make(
    std::unique_ptr<type_qualifier_t> &&type_qualifier_0_,
    const token_t *IDENTIFIER_1_,
    const token_t *LEFT_BRACE_2_,
    std::unique_ptr<struct_declaration_list_t> &&struct_declaration_list_3_,
    const token_t *RIGHT_BRACE_4_,
    const token_t *IDENTIFIER_5_,
    std::unique_ptr<array_specifier_t> &&array_specifier_6_,
    const token_t *SEMICOLON_7_
  ) {
    return std::make_unique<declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_array_specifier_semicolon_t>(
      std::move(type_qualifier_0_),
      std::make_unique<token_t>(*IDENTIFIER_1_),
      std::make_unique<token_t>(*LEFT_BRACE_2_),
      std::move(struct_declaration_list_3_),
      std::make_unique<token_t>(*RIGHT_BRACE_4_),
      std::make_unique<token_t>(*IDENTIFIER_5_),
      std::move(array_specifier_6_),
      std::make_unique<token_t>(*SEMICOLON_7_)
    );
  }

};  // declaration_type_qualifier_identifier_left_brace_struct_declaration_list_right_brace_identifier_array_specifier_semicolon_t

class declaration_type_qualifier_semicolon_t: public declaration_t {

public:

  std::unique_ptr<type_qualifier_t> type_qualifier_0;

  std::unique_ptr<token_t> semicolon_1;

  declaration_type_qualifier_semicolon_t(
    std::unique_ptr<type_qualifier_t> &&type_qualifier_0_,
    std::unique_ptr<token_t> &&semicolon_1_
  ): type_qualifier_0(std::move(type_qualifier_0_)),
     semicolon_1(std::move(semicolon_1_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<declaration_type_qualifier_semicolon_t> make(
    std::unique_ptr<type_qualifier_t> &&type_qualifier_0_,
    const token_t *SEMICOLON_1_
  ) {
    return std::make_unique<declaration_type_qualifier_semicolon_t>(
      std::move(type_qualifier_0_),
      std::make_unique<token_t>(*SEMICOLON_1_)
    );
  }

};  // declaration_type_qualifier_semicolon_t

class declaration_type_qualifier_identifier_semicolon_t: public declaration_t {

public:

  std::unique_ptr<type_qualifier_t> type_qualifier_0;

  std::unique_ptr<token_t> identifier_1;

  std::unique_ptr<token_t> semicolon_2;

  declaration_type_qualifier_identifier_semicolon_t(
    std::unique_ptr<type_qualifier_t> &&type_qualifier_0_,
    std::unique_ptr<token_t> &&identifier_1_,
    std::unique_ptr<token_t> &&semicolon_2_
  ): type_qualifier_0(std::move(type_qualifier_0_)),
     identifier_1(std::move(identifier_1_)),
     semicolon_2(std::move(semicolon_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<declaration_type_qualifier_identifier_semicolon_t> make(
    std::unique_ptr<type_qualifier_t> &&type_qualifier_0_,
    const token_t *IDENTIFIER_1_,
    const token_t *SEMICOLON_2_
  ) {
    return std::make_unique<declaration_type_qualifier_identifier_semicolon_t>(
      std::move(type_qualifier_0_),
      std::make_unique<token_t>(*IDENTIFIER_1_),
      std::make_unique<token_t>(*SEMICOLON_2_)
    );
  }

};  // declaration_type_qualifier_identifier_semicolon_t

class declaration_type_qualifier_identifier_identifier_list_semicolon_t: public declaration_t {

public:

  std::unique_ptr<type_qualifier_t> type_qualifier_0;

  std::unique_ptr<token_t> identifier_1;

  std::unique_ptr<identifier_list_t> identifier_list_2;

  std::unique_ptr<token_t> semicolon_3;

  declaration_type_qualifier_identifier_identifier_list_semicolon_t(
    std::unique_ptr<type_qualifier_t> &&type_qualifier_0_,
    std::unique_ptr<token_t> &&identifier_1_,
    std::unique_ptr<identifier_list_t> &&identifier_list_2_,
    std::unique_ptr<token_t> &&semicolon_3_
  ): type_qualifier_0(std::move(type_qualifier_0_)),
     identifier_1(std::move(identifier_1_)),
     identifier_list_2(std::move(identifier_list_2_)),
     semicolon_3(std::move(semicolon_3_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<declaration_type_qualifier_identifier_identifier_list_semicolon_t> make(
    std::unique_ptr<type_qualifier_t> &&type_qualifier_0_,
    const token_t *IDENTIFIER_1_,
    std::unique_ptr<identifier_list_t> &&identifier_list_2_,
    const token_t *SEMICOLON_3_
  ) {
    return std::make_unique<declaration_type_qualifier_identifier_identifier_list_semicolon_t>(
      std::move(type_qualifier_0_),
      std::make_unique<token_t>(*IDENTIFIER_1_),
      std::move(identifier_list_2_),
      std::make_unique<token_t>(*SEMICOLON_3_)
    );
  }

};  // declaration_type_qualifier_identifier_identifier_list_semicolon_t

}   // ast

}   // gliss
