#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "single-declaration.h"

#include "array-specifier.h"
#include "initializer.h"

namespace gliss {

namespace ast {

class single_declaration_t;

class array_specifier_t;
class initializer_t;

class init_declarator_list_t: public ast_t {

public:

  static constexpr int num_types = 5;

  template <int n, typename = void>
  struct pattern;

  template<int n>
  struct pattern<n, typename std::enable_if<n == 0>::type> {
    using type = init_declarator_list_single_declaration_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  template<int n>
  struct pattern<n, typename std::enable_if<n == 1>::type> {
    using type = init_declarator_list_init_declarator_list_comma_identifier_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  template<int n>
  struct pattern<n, typename std::enable_if<n == 2>::type> {
    using type = init_declarator_list_init_declarator_list_comma_identifier_array_specifier_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  template<int n>
  struct pattern<n, typename std::enable_if<n == 3>::type> {
    using type = init_declarator_list_init_declarator_list_comma_identifier_array_specifier_equal_initializer_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  template<int n>
  struct pattern<n, typename std::enable_if<n == 4>::type> {
    using type = init_declarator_list_init_declarator_list_comma_identifier_equal_initializer_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  virtual ~init_declarator_list_t() = default;

};  // init_declarator_list_t

class init_declarator_list_single_declaration_t: public init_declarator_list_t {

public:

  std::unique_ptr<single_declaration_t> single_declaration_0;

  init_declarator_list_single_declaration_t(
    std::unique_ptr<single_declaration_t> &&single_declaration_0_
  ): single_declaration_0(std::move(single_declaration_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // init_declarator_list_single_declaration_t

class init_declarator_list_init_declarator_list_comma_identifier_t: public init_declarator_list_t {

public:

  std::unique_ptr<init_declarator_list_t> init_declarator_list_0;

  std::unique_ptr<token_t> comma_1;

  std::unique_ptr<token_t> identifier_2;

  init_declarator_list_init_declarator_list_comma_identifier_t(
    std::unique_ptr<init_declarator_list_t> &&init_declarator_list_0_,
    std::unique_ptr<token_t> &&comma_1_,
    std::unique_ptr<token_t> &&identifier_2_
  ): init_declarator_list_0(std::move(init_declarator_list_0_)),
     comma_1(std::move(comma_1_)),
     identifier_2(std::move(identifier_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // init_declarator_list_init_declarator_list_comma_identifier_t

class init_declarator_list_init_declarator_list_comma_identifier_array_specifier_t: public init_declarator_list_t {

public:

  std::unique_ptr<init_declarator_list_t> init_declarator_list_0;

  std::unique_ptr<token_t> comma_1;

  std::unique_ptr<token_t> identifier_2;

  std::unique_ptr<array_specifier_t> array_specifier_3;

  init_declarator_list_init_declarator_list_comma_identifier_array_specifier_t(
    std::unique_ptr<init_declarator_list_t> &&init_declarator_list_0_,
    std::unique_ptr<token_t> &&comma_1_,
    std::unique_ptr<token_t> &&identifier_2_,
    std::unique_ptr<array_specifier_t> &&array_specifier_3_
  ): init_declarator_list_0(std::move(init_declarator_list_0_)),
     comma_1(std::move(comma_1_)),
     identifier_2(std::move(identifier_2_)),
     array_specifier_3(std::move(array_specifier_3_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // init_declarator_list_init_declarator_list_comma_identifier_array_specifier_t

class init_declarator_list_init_declarator_list_comma_identifier_array_specifier_equal_initializer_t: public init_declarator_list_t {

public:

  std::unique_ptr<init_declarator_list_t> init_declarator_list_0;

  std::unique_ptr<token_t> comma_1;

  std::unique_ptr<token_t> identifier_2;

  std::unique_ptr<array_specifier_t> array_specifier_3;

  std::unique_ptr<token_t> equal_4;

  std::unique_ptr<initializer_t> initializer_5;

  init_declarator_list_init_declarator_list_comma_identifier_array_specifier_equal_initializer_t(
    std::unique_ptr<init_declarator_list_t> &&init_declarator_list_0_,
    std::unique_ptr<token_t> &&comma_1_,
    std::unique_ptr<token_t> &&identifier_2_,
    std::unique_ptr<array_specifier_t> &&array_specifier_3_,
    std::unique_ptr<token_t> &&equal_4_,
    std::unique_ptr<initializer_t> &&initializer_5_
  ): init_declarator_list_0(std::move(init_declarator_list_0_)),
     comma_1(std::move(comma_1_)),
     identifier_2(std::move(identifier_2_)),
     array_specifier_3(std::move(array_specifier_3_)),
     equal_4(std::move(equal_4_)),
     initializer_5(std::move(initializer_5_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // init_declarator_list_init_declarator_list_comma_identifier_array_specifier_equal_initializer_t

class init_declarator_list_init_declarator_list_comma_identifier_equal_initializer_t: public init_declarator_list_t {

public:

  std::unique_ptr<init_declarator_list_t> init_declarator_list_0;

  std::unique_ptr<token_t> comma_1;

  std::unique_ptr<token_t> identifier_2;

  std::unique_ptr<token_t> equal_3;

  std::unique_ptr<initializer_t> initializer_4;

  init_declarator_list_init_declarator_list_comma_identifier_equal_initializer_t(
    std::unique_ptr<init_declarator_list_t> &&init_declarator_list_0_,
    std::unique_ptr<token_t> &&comma_1_,
    std::unique_ptr<token_t> &&identifier_2_,
    std::unique_ptr<token_t> &&equal_3_,
    std::unique_ptr<initializer_t> &&initializer_4_
  ): init_declarator_list_0(std::move(init_declarator_list_0_)),
     comma_1(std::move(comma_1_)),
     identifier_2(std::move(identifier_2_)),
     equal_3(std::move(equal_3_)),
     initializer_4(std::move(initializer_4_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // init_declarator_list_init_declarator_list_comma_identifier_equal_initializer_t

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> init_declarator_list_t::pattern<0>::list = {
  pattern_item_t<single_declaration_t>::get()
};

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> init_declarator_list_t::pattern<1>::list = {
  pattern_item_t<init_declarator_list_t>::get(),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("COMMA")),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("IDENTIFIER"))
};

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> init_declarator_list_t::pattern<2>::list = {
  pattern_item_t<init_declarator_list_t>::get(),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("COMMA")),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("IDENTIFIER")),
  pattern_item_t<array_specifier_t>::get()
};

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> init_declarator_list_t::pattern<3>::list = {
  pattern_item_t<init_declarator_list_t>::get(),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("COMMA")),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("IDENTIFIER")),
  pattern_item_t<array_specifier_t>::get(),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("EQUAL")),
  pattern_item_t<initializer_t>::get()
};

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> init_declarator_list_t::pattern<4>::list = {
  pattern_item_t<init_declarator_list_t>::get(),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("COMMA")),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("IDENTIFIER")),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("EQUAL")),
  pattern_item_t<initializer_t>::get()
};

}   // ast

}   // gliss
