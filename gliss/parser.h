#pragma once

#include <memory>

#include "token.h"
#include "cursor.h"
#include "expr.h"

namespace gliss {

class parser_t final {

public:

  /* Convert an array of tokens into a syntax tree. */
  static std::unique_ptr<expr_t> parse(const std::vector<token_t> &tokens) {
    cursor_t cursor(&tokens[0], &tokens[tokens.size() - 1]);
    return parser_t(cursor).parse();
  }

private:

  const cursor_t cursor;

  parser_t(const cursor_t &cursor_) : cursor(cursor_) {}

  std::unique_ptr<expr_t> parse() {
    auto ptr = std::make_unique<expr_t>();
    return ptr;
  }

};  // parser_t

}   // gliss
