#pragma once

/**
 * DO NOT MODIFY - AUTO GENERATED BY "../scripts/gen_cpp_node_constants.js"
 */

#include <vector>
#include "../ast.h"
#include "type-name-list.h"

/**
 * Patterns for storage_qualifier
 *
 * 1. CONST
 * 2. INOUT
 * 3. IN
 * 4. OUT
 * 5. CENTROID
 * 6. PATCH
 * 7. SAMPLE
 * 8. UNIFORM
 * 9. BUFFER
 * 10. SHARED
 * 11. COHERENT
 * 12. VOLATILE
 * 13. RESTRICT
 * 14. READONLY
 * 15. WRITEONLY
 * 16. SUBROUTINE
 * 17. SUBROUTINE LEFT_PAREN type_name_list RIGHT_PAREN
 */

namespace gliss {

namespace ast {

class type_name_list_t;

class storage_qualifier_t: public ast_t {

public:

  static constexpr int rules = 17;

  static constexpr int id = 260;

  virtual ~storage_qualifier_t() = default;

};  // storage_qualifier_t

class storage_qualifier_const_t: public storage_qualifier_t {

public:

  std::unique_ptr<token_t> const_0;

  storage_qualifier_const_t(
    std::unique_ptr<token_t> &&const_0_
  ): const_0(std::move(const_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<storage_qualifier_const_t> make(
    const token_t *CONST_0_
  ) {
    return std::make_unique<storage_qualifier_const_t>(
      std::make_unique<token_t>(*CONST_0_)
    );
  }

};  // storage_qualifier_const_t

class storage_qualifier_inout_t: public storage_qualifier_t {

public:

  std::unique_ptr<token_t> inout_0;

  storage_qualifier_inout_t(
    std::unique_ptr<token_t> &&inout_0_
  ): inout_0(std::move(inout_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<storage_qualifier_inout_t> make(
    const token_t *INOUT_0_
  ) {
    return std::make_unique<storage_qualifier_inout_t>(
      std::make_unique<token_t>(*INOUT_0_)
    );
  }

};  // storage_qualifier_inout_t

class storage_qualifier_in_t: public storage_qualifier_t {

public:

  std::unique_ptr<token_t> in_0;

  storage_qualifier_in_t(
    std::unique_ptr<token_t> &&in_0_
  ): in_0(std::move(in_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<storage_qualifier_in_t> make(
    const token_t *IN_0_
  ) {
    return std::make_unique<storage_qualifier_in_t>(
      std::make_unique<token_t>(*IN_0_)
    );
  }

};  // storage_qualifier_in_t

class storage_qualifier_out_t: public storage_qualifier_t {

public:

  std::unique_ptr<token_t> out_0;

  storage_qualifier_out_t(
    std::unique_ptr<token_t> &&out_0_
  ): out_0(std::move(out_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<storage_qualifier_out_t> make(
    const token_t *OUT_0_
  ) {
    return std::make_unique<storage_qualifier_out_t>(
      std::make_unique<token_t>(*OUT_0_)
    );
  }

};  // storage_qualifier_out_t

class storage_qualifier_centroid_t: public storage_qualifier_t {

public:

  std::unique_ptr<token_t> centroid_0;

  storage_qualifier_centroid_t(
    std::unique_ptr<token_t> &&centroid_0_
  ): centroid_0(std::move(centroid_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<storage_qualifier_centroid_t> make(
    const token_t *CENTROID_0_
  ) {
    return std::make_unique<storage_qualifier_centroid_t>(
      std::make_unique<token_t>(*CENTROID_0_)
    );
  }

};  // storage_qualifier_centroid_t

class storage_qualifier_patch_t: public storage_qualifier_t {

public:

  std::unique_ptr<token_t> patch_0;

  storage_qualifier_patch_t(
    std::unique_ptr<token_t> &&patch_0_
  ): patch_0(std::move(patch_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<storage_qualifier_patch_t> make(
    const token_t *PATCH_0_
  ) {
    return std::make_unique<storage_qualifier_patch_t>(
      std::make_unique<token_t>(*PATCH_0_)
    );
  }

};  // storage_qualifier_patch_t

class storage_qualifier_sample_t: public storage_qualifier_t {

public:

  std::unique_ptr<token_t> sample_0;

  storage_qualifier_sample_t(
    std::unique_ptr<token_t> &&sample_0_
  ): sample_0(std::move(sample_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<storage_qualifier_sample_t> make(
    const token_t *SAMPLE_0_
  ) {
    return std::make_unique<storage_qualifier_sample_t>(
      std::make_unique<token_t>(*SAMPLE_0_)
    );
  }

};  // storage_qualifier_sample_t

class storage_qualifier_uniform_t: public storage_qualifier_t {

public:

  std::unique_ptr<token_t> uniform_0;

  storage_qualifier_uniform_t(
    std::unique_ptr<token_t> &&uniform_0_
  ): uniform_0(std::move(uniform_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<storage_qualifier_uniform_t> make(
    const token_t *UNIFORM_0_
  ) {
    return std::make_unique<storage_qualifier_uniform_t>(
      std::make_unique<token_t>(*UNIFORM_0_)
    );
  }

};  // storage_qualifier_uniform_t

class storage_qualifier_buffer_t: public storage_qualifier_t {

public:

  std::unique_ptr<token_t> buffer_0;

  storage_qualifier_buffer_t(
    std::unique_ptr<token_t> &&buffer_0_
  ): buffer_0(std::move(buffer_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<storage_qualifier_buffer_t> make(
    const token_t *BUFFER_0_
  ) {
    return std::make_unique<storage_qualifier_buffer_t>(
      std::make_unique<token_t>(*BUFFER_0_)
    );
  }

};  // storage_qualifier_buffer_t

class storage_qualifier_shared_t: public storage_qualifier_t {

public:

  std::unique_ptr<token_t> shared_0;

  storage_qualifier_shared_t(
    std::unique_ptr<token_t> &&shared_0_
  ): shared_0(std::move(shared_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<storage_qualifier_shared_t> make(
    const token_t *SHARED_0_
  ) {
    return std::make_unique<storage_qualifier_shared_t>(
      std::make_unique<token_t>(*SHARED_0_)
    );
  }

};  // storage_qualifier_shared_t

class storage_qualifier_coherent_t: public storage_qualifier_t {

public:

  std::unique_ptr<token_t> coherent_0;

  storage_qualifier_coherent_t(
    std::unique_ptr<token_t> &&coherent_0_
  ): coherent_0(std::move(coherent_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<storage_qualifier_coherent_t> make(
    const token_t *COHERENT_0_
  ) {
    return std::make_unique<storage_qualifier_coherent_t>(
      std::make_unique<token_t>(*COHERENT_0_)
    );
  }

};  // storage_qualifier_coherent_t

class storage_qualifier_volatile_t: public storage_qualifier_t {

public:

  std::unique_ptr<token_t> volatile_0;

  storage_qualifier_volatile_t(
    std::unique_ptr<token_t> &&volatile_0_
  ): volatile_0(std::move(volatile_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<storage_qualifier_volatile_t> make(
    const token_t *VOLATILE_0_
  ) {
    return std::make_unique<storage_qualifier_volatile_t>(
      std::make_unique<token_t>(*VOLATILE_0_)
    );
  }

};  // storage_qualifier_volatile_t

class storage_qualifier_restrict_t: public storage_qualifier_t {

public:

  std::unique_ptr<token_t> restrict_0;

  storage_qualifier_restrict_t(
    std::unique_ptr<token_t> &&restrict_0_
  ): restrict_0(std::move(restrict_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<storage_qualifier_restrict_t> make(
    const token_t *RESTRICT_0_
  ) {
    return std::make_unique<storage_qualifier_restrict_t>(
      std::make_unique<token_t>(*RESTRICT_0_)
    );
  }

};  // storage_qualifier_restrict_t

class storage_qualifier_readonly_t: public storage_qualifier_t {

public:

  std::unique_ptr<token_t> readonly_0;

  storage_qualifier_readonly_t(
    std::unique_ptr<token_t> &&readonly_0_
  ): readonly_0(std::move(readonly_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<storage_qualifier_readonly_t> make(
    const token_t *READONLY_0_
  ) {
    return std::make_unique<storage_qualifier_readonly_t>(
      std::make_unique<token_t>(*READONLY_0_)
    );
  }

};  // storage_qualifier_readonly_t

class storage_qualifier_writeonly_t: public storage_qualifier_t {

public:

  std::unique_ptr<token_t> writeonly_0;

  storage_qualifier_writeonly_t(
    std::unique_ptr<token_t> &&writeonly_0_
  ): writeonly_0(std::move(writeonly_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<storage_qualifier_writeonly_t> make(
    const token_t *WRITEONLY_0_
  ) {
    return std::make_unique<storage_qualifier_writeonly_t>(
      std::make_unique<token_t>(*WRITEONLY_0_)
    );
  }

};  // storage_qualifier_writeonly_t

class storage_qualifier_subroutine_t: public storage_qualifier_t {

public:

  std::unique_ptr<token_t> subroutine_0;

  storage_qualifier_subroutine_t(
    std::unique_ptr<token_t> &&subroutine_0_
  ): subroutine_0(std::move(subroutine_0_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<storage_qualifier_subroutine_t> make(
    const token_t *SUBROUTINE_0_
  ) {
    return std::make_unique<storage_qualifier_subroutine_t>(
      std::make_unique<token_t>(*SUBROUTINE_0_)
    );
  }

};  // storage_qualifier_subroutine_t

class storage_qualifier_subroutine_left_paren_type_name_list_right_paren_t: public storage_qualifier_t {

public:

  std::unique_ptr<token_t> subroutine_0;

  std::unique_ptr<token_t> left_paren_1;

  std::unique_ptr<type_name_list_t> type_name_list_2;

  std::unique_ptr<token_t> right_paren_3;

  storage_qualifier_subroutine_left_paren_type_name_list_right_paren_t(
    std::unique_ptr<token_t> &&subroutine_0_,
    std::unique_ptr<token_t> &&left_paren_1_,
    std::unique_ptr<type_name_list_t> &&type_name_list_2_,
    std::unique_ptr<token_t> &&right_paren_3_
  ): subroutine_0(std::move(subroutine_0_)),
     left_paren_1(std::move(left_paren_1_)),
     type_name_list_2(std::move(type_name_list_2_)),
     right_paren_3(std::move(right_paren_3_)) {}

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static std::unique_ptr<storage_qualifier_subroutine_left_paren_type_name_list_right_paren_t> make(
    const token_t *SUBROUTINE_0_,
    const token_t *LEFT_PAREN_1_,
    std::unique_ptr<type_name_list_t> &&type_name_list_2_,
    const token_t *RIGHT_PAREN_3_
  ) {
    return std::make_unique<storage_qualifier_subroutine_left_paren_type_name_list_right_paren_t>(
      std::make_unique<token_t>(*SUBROUTINE_0_),
      std::make_unique<token_t>(*LEFT_PAREN_1_),
      std::move(type_name_list_2_),
      std::make_unique<token_t>(*RIGHT_PAREN_3_)
    );
  }

};  // storage_qualifier_subroutine_left_paren_type_name_list_right_paren_t

}   // ast

}   // gliss
