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
  std::unique_ptr<ast::ast_t> auto_match() {
    for (const auto &pattern: node_t::patterns) {
      auto cursor_copy = cursor;

      for (const auto &pattern_item: pattern) {
        if (pattern_item.is_leaf()) {
          std::cout << "it is a leaf" << std::endl;
          auto match = cursor_copy.try_match();
          std::cout << "got one" << std::endl;
        } else {
          throw runtime_error("cannot auto match yet");
        }
      }

    }

    return std::make_unique<node_t>();
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
