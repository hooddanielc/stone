#include "token.h"
#include "cursor.h"

namespace gliss {

class parser_t final {

public:

  /* Convert an array of tokens into a syntax tree. */
  static std::unique_ptr<expr_t> parse(const std::vector &tokens) {
    cursor_t cursor(&tokens[0], &tokens[tokens.size() - 1]);
    return parser_t(cursor).parse();
  }

private:

  const cursor_t cursor;

  parser_t(const cursor_t &cursor) : cursor(cursor_) {}

  std::unique_ptr<expr_t> parser(const cursor_t &cursor) {
    std::unique_ptr<expr_t> ptr;
    return ptr;
  }

};  // parser_t

}   // gliss