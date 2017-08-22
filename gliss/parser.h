#pragma once

#include <memory>

#include "token.h"
#include "cursor.h"
#include "ast.h"
#include "ast-nodes/all.h"

namespace gliss {

class parser_t final {

public:

  static parser_t make(const std::vector<token_t> &tokens) {
    return cursor_t(&tokens[0], &tokens[tokens.size() - 1]);
  }

  /* Convert an array of tokens into a syntax tree. */
  static std::unique_ptr<ast::ast_t> parse(const std::vector<token_t> &tokens) {
    cursor_t cursor(&tokens[0], &tokens[tokens.size() - 1]);
    return parser_t(cursor).parse();
  }

  /* Auto matcher */
  template <typename node_t>
  std::unique_ptr<ast::ast_t> match_assignment_operator() {
    // it's time
    return std::make_unique<ast::nothing_t>();
  }

private:

  const cursor_t cursor;

  parser_t(const cursor_t &cursor_) : cursor(cursor_) {}

  std::unique_ptr<ast::ast_t> parse() {
    auto ptr = std::make_unique<ast::nothing_t>();
    return ptr;
  }

};  // parser_t

}   // gliss
