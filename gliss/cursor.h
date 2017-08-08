#include <set>
#include <cassert>
#include "token.h"
#include "ice.h"

namespace gliss {

class cursor_t final {

public:

  cursor_t(
    const token_t *start_,
    const token_t *limit_
  ) noexcept: token(start_), limit(limit_) {
    assert(token <= limit);
  }

  cursor_t(const cursor_t &that) noexcept = default;

  cursor_t &operator=(const cursor_t &that) noexcept = default;

  const token_t &operator*() const noexcept {
    return *get();
  }

  const token_t *operator->() const noexcept {
    return get();
  }

  const token_t *get() const noexcept {
    if (token == limit && limit->get_kind() != token_t::end) {
      throw ice_t(limit->get_pos(), __FILE__, __LINE__);
    }

    return token;
  }

  cursor_t &operator++() noexcept {
    if (token < limit) {
      ++token;
    }
    return *this;
  }

  const token_t *match(token_t::kind_t kind) {
    auto *temp = try_match(kind);
    if (!temp) {
      throw std::runtime_error { "syntax error" };
    }
    return temp;
  }

  const token_t *match_any(const std::set<token_t::kind_t> &kinds) {
    auto *temp = try_match_any(kinds);
    if (!temp) {
      throw std::runtime_error { "syntax error" };
    }
    return temp;
  }

  const token_t *try_match(token_t::kind_t kind) noexcept {
    auto *temp = get();
    if (temp->get_kind() != kind) {
      return nullptr;
    }
    ++(*this);
    return temp;
  }

  const token_t *try_match_any(
    const std::set<token_t::kind_t> &kinds
  ) noexcept {
    auto *temp = get();
    auto iter = kinds.find(temp->get_kind());
    if (iter == kinds.end()) {
      return nullptr;
    }
    ++(*this);
    return temp;
  }

private:

  const token_t *token, *limit;

};  // cursor_t

}   // gliss
