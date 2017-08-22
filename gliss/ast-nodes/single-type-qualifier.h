#pragma once


/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */
  

#include <vector>
#include "../ast.h"
#include "storage-qualifier.h"
#include "layout-qualifier.h"
#include "precision-qualifier.h"
#include "interpolation-qualifier.h"
#include "invariant-qualifier.h"
#include "precise-qualifier.h"

namespace gliss {

namespace ast {

class storage_qualifier_t;
class layout_qualifier_t;
class precision_qualifier_t;
class interpolation_qualifier_t;
class invariant_qualifier_t;
class precise_qualifier_t;

class single_type_qualifier_t: public ast_t {

public:

  static constexpr int num_types = 6;

  template <int n, typename = void>
  struct pattern;

  template<int n>
  struct pattern<n, typename std::enable_if<n == 0>::type> {
    using type = single_type_qualifier_storage_qualifier_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  template<int n>
  struct pattern<n, typename std::enable_if<n == 1>::type> {
    using type = single_type_qualifier_layout_qualifier_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  template<int n>
  struct pattern<n, typename std::enable_if<n == 2>::type> {
    using type = single_type_qualifier_precision_qualifier_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  template<int n>
  struct pattern<n, typename std::enable_if<n == 3>::type> {
    using type = single_type_qualifier_interpolation_qualifier_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  template<int n>
  struct pattern<n, typename std::enable_if<n == 4>::type> {
    using type = single_type_qualifier_invariant_qualifier_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  template<int n>
  struct pattern<n, typename std::enable_if<n == 5>::type> {
    using type = single_type_qualifier_precise_qualifier_t;
    static std::vector<std::shared_ptr<any_pattern_item_t>> list;
  };

  virtual ~single_type_qualifier_t() = default;

};  // single_type_qualifier_t


class single_type_qualifier_storage_qualifier_t: public single_type_qualifier_t {

public:

  std::unique_ptr<storage_qualifier_t> storage_qualifier_0;

  single_type_qualifier_storage_qualifier_t(
    std::unique_ptr<storage_qualifier_t> &&storage_qualifier_0_
  ): storage_qualifier_0(std::move(storage_qualifier_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // single_type_qualifier_storage_qualifier_t
  

class single_type_qualifier_layout_qualifier_t: public single_type_qualifier_t {

public:

  std::unique_ptr<layout_qualifier_t> layout_qualifier_0;

  single_type_qualifier_layout_qualifier_t(
    std::unique_ptr<layout_qualifier_t> &&layout_qualifier_0_
  ): layout_qualifier_0(std::move(layout_qualifier_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // single_type_qualifier_layout_qualifier_t
  

class single_type_qualifier_precision_qualifier_t: public single_type_qualifier_t {

public:

  std::unique_ptr<precision_qualifier_t> precision_qualifier_0;

  single_type_qualifier_precision_qualifier_t(
    std::unique_ptr<precision_qualifier_t> &&precision_qualifier_0_
  ): precision_qualifier_0(std::move(precision_qualifier_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // single_type_qualifier_precision_qualifier_t
  

class single_type_qualifier_interpolation_qualifier_t: public single_type_qualifier_t {

public:

  std::unique_ptr<interpolation_qualifier_t> interpolation_qualifier_0;

  single_type_qualifier_interpolation_qualifier_t(
    std::unique_ptr<interpolation_qualifier_t> &&interpolation_qualifier_0_
  ): interpolation_qualifier_0(std::move(interpolation_qualifier_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // single_type_qualifier_interpolation_qualifier_t
  

class single_type_qualifier_invariant_qualifier_t: public single_type_qualifier_t {

public:

  std::unique_ptr<invariant_qualifier_t> invariant_qualifier_0;

  single_type_qualifier_invariant_qualifier_t(
    std::unique_ptr<invariant_qualifier_t> &&invariant_qualifier_0_
  ): invariant_qualifier_0(std::move(invariant_qualifier_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // single_type_qualifier_invariant_qualifier_t
  

class single_type_qualifier_precise_qualifier_t: public single_type_qualifier_t {

public:

  std::unique_ptr<precise_qualifier_t> precise_qualifier_0;

  single_type_qualifier_precise_qualifier_t(
    std::unique_ptr<precise_qualifier_t> &&precise_qualifier_0_
  ): precise_qualifier_0(std::move(precise_qualifier_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

};  // single_type_qualifier_precise_qualifier_t
  

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> single_type_qualifier_t::pattern<0>::list = {
  pattern_item_t<storage_qualifier_t>::get()
};

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> single_type_qualifier_t::pattern<1>::list = {
  pattern_item_t<layout_qualifier_t>::get()
};

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> single_type_qualifier_t::pattern<2>::list = {
  pattern_item_t<precision_qualifier_t>::get()
};

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> single_type_qualifier_t::pattern<3>::list = {
  pattern_item_t<interpolation_qualifier_t>::get()
};

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> single_type_qualifier_t::pattern<4>::list = {
  pattern_item_t<invariant_qualifier_t>::get()
};

template <>
std::vector<std::shared_ptr<any_pattern_item_t>> single_type_qualifier_t::pattern<5>::list = {
  pattern_item_t<precise_qualifier_t>::get()
};

}   // ast

}   // gliss
