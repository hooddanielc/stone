#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "type-specifier.h"
#include "type-qualifier.h"

namespace gliss {

namespace ast {

class type_specifier_t;
class type_qualifier_t;

class fully_specified_type_t: public ast_t {

public:

  static constexpr int num_types = 2;

  template <int n, typename = void>
  struct pattern;

  template<int n>
  struct pattern<n, typename std::enable_if<n == 0>::type> {
    using type = fully_specified_type_type_specifier_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  template<int n>
  struct pattern<n, typename std::enable_if<n == 1>::type> {
    using type = fully_specified_type_type_qualifier_type_specifier_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  virtual ~fully_specified_type_t() = default;

};  // fully_specified_type_t

class fully_specified_type_type_specifier_t: public fully_specified_type_t {

public:

  std::unique_ptr<type_specifier_t> type_specifier_0;

  fully_specified_type_type_specifier_t(
    std::unique_ptr<type_specifier_t> &&type_specifier_0_
  ): type_specifier_0(std::move(type_specifier_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // fully_specified_type_type_specifier_t

class fully_specified_type_type_qualifier_type_specifier_t: public fully_specified_type_t {

public:

  std::unique_ptr<type_qualifier_t> type_qualifier_0;

  std::unique_ptr<type_specifier_t> type_specifier_1;

  fully_specified_type_type_qualifier_type_specifier_t(
    std::unique_ptr<type_qualifier_t> &&type_qualifier_0_,
    std::unique_ptr<type_specifier_t> &&type_specifier_1_
  ): type_qualifier_0(std::move(type_qualifier_0_)),
     type_specifier_1(std::move(type_specifier_1_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // fully_specified_type_type_qualifier_type_specifier_t

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> fully_specified_type_t::pattern<0>::list = {
  pattern_item_t<type_specifier_t>::get()
};

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> fully_specified_type_t::pattern<1>::list = {
  pattern_item_t<type_qualifier_t>::get(),
  pattern_item_t<type_specifier_t>::get()
};

}   // ast

}   // gliss
