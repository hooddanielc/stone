#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "initializer.h"


namespace gliss {

namespace ast {

class initializer_t;


class initializer_list_t: public ast_t {

public:

  static constexpr int num_types = 2;

  template <int n, typename = void>
  struct pattern;

  template<int n>
  struct pattern<n, typename std::enable_if<n == 0>::type> {
    using type = initializer_list_initializer_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  template<int n>
  struct pattern<n, typename std::enable_if<n == 1>::type> {
    using type = initializer_list_initializer_list_comma_initializer_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  virtual ~initializer_list_t() = default;

};  // initializer_list_t


class initializer_list_initializer_t: public initializer_list_t {

public:

  std::unique_ptr<initializer_t> initializer_0;

  initializer_list_initializer_t(
    std::unique_ptr<initializer_t> &&initializer_0_
  ): initializer_0(std::move(initializer_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // initializer_list_initializer_t
  

class initializer_list_initializer_list_comma_initializer_t: public initializer_list_t {

public:

  std::unique_ptr<initializer_list_t> initializer_list_0;

  std::unique_ptr<token_t> comma_1;

  std::unique_ptr<initializer_t> initializer_2;

  initializer_list_initializer_list_comma_initializer_t(
    std::unique_ptr<initializer_list_t> &&initializer_list_0_,
    std::unique_ptr<token_t> &&comma_1_,
    std::unique_ptr<initializer_t> &&initializer_2_
  ): initializer_list_0(std::move(initializer_list_0_)),
     comma_1(std::move(comma_1_)),
     initializer_2(std::move(initializer_2_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // initializer_list_initializer_list_comma_initializer_t
  

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> initializer_list_t::pattern<0>::list = {
  pattern_item_t<initializer_t>::get()
};

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> initializer_list_t::pattern<1>::list = {
  pattern_item_t<initializer_list_t>::get(),
  pattern_item_t<token_t>::get(token_t::uppercase_to_kind("COMMA")),
  pattern_item_t<initializer_t>::get()
};

}   // ast

}   // gliss
