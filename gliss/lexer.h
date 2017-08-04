#pragma once

#include "pos.h"
#include "token.h"
#include "error.h"

namespace gliss {

/* Convert source text into a vector of tokens. */
class lexer_t final {

public:

  /* An error in lexing. */
  class error_t final: public gliss::error_t {

  public:

    /* Report the position and what we found there. */
    error_t(const lexer_t *lexer, const char *msg): gliss::error_t(lexer->pos) {
      get_strm() << msg;
    }

  };  // lexer_t::error_t

  /* Convert the given source text into a vector of tokens, ending with an
     end token. */
  static std::vector<token_t> lex(const char *next_cursor) {
    return lexer_t(next_cursor).lex();
  }

private:

  /* Used by our public lex function. */
  lexer_t(const char *next_cursor):
    next_cursor(next_cursor),
    is_ready(false) {}

  /* Used by our public lex function. */
  std::vector<token_t> lex() {
    std::vector<token_t> tokens;
    enum { start } state = start;
    pos_t anchor_pos;
    bool go = true;
    do {
      char c = peek();
      switch (state) {
        case start: {
          switch (c) {
            case '\0': {
              tokens.emplace_back(pos, token_t::end);
              go = false;
              break;
            }
            default: {
              if (isspace(c)) {
                pop();
                break;
              }
              throw error_t(this, "bad character");
            }
          }
          break;
        }
      }  // switch
    } while (go);
    return tokens;
  }

  /* Return the current character from the source text but don't advance to
     the next one. */
  char peek() const {
    if (!is_ready) {
      cursor = next_cursor;
      pos = next_pos;
      switch (*cursor) {
        case '\0': {
          break;
        }
        case '\n': {
          ++next_cursor;
          next_pos.next_line();
          break;
        }
        default: {
          ++next_cursor;
          next_pos.next_col();
        }
      }  // switch
      is_ready = true;
    }
    return *cursor;
  }

  /* Return the current character from the source text and advance to the
     next one. */
  char pop() {
    char c = peek();
    is_ready = false;
    return c;
  }

  /* Our next position within the source text. */
  mutable const char *next_cursor;

  /* The (line, col) of next_cursor. */
  mutable pos_t next_pos;

  /* If true, then cursor and pos, below, are valid; otherwise,
     those fields contain junk.  Peeking makes us ready, popping makes us
     unready. */
  mutable bool is_ready;

  /* Our current position within the source text, when ready. */
  mutable const char *cursor;

  /* The (line, col) cursor, when ready. */
  mutable pos_t pos;

};  // lexer_t

}   // gliss
