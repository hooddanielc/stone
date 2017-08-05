#pragma once

#include <cctype>
#include <map>

#include "pos.h"
#include "token.h"
#include "error.h"
#include "ice.h"

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
    is_ready(false),
    anchor(nullptr) {}

  /* Used by our public lex function. */
  std::vector<token_t> lex() {
    std::vector<token_t> tokens;
    enum {
      start,
      start_slash,
      start_equal,
      multiline_comment,
      multiline_comment_end_star,
      oneline_comment,
      name
    } state = start;
    bool go = true;
    do {
      char c = peek();
      switch (state) {
        case start: {
          switch (c) {
            case '\0': {
              go = false;
              break;
            }
            case '/': {
              pop();
              state = start_slash;
              break;
            }
            case '=': {
              set_anchor();
              pop();
              state = start_equal;
              break;
            }
            default: {
              if (isspace(c)) {
                pop();
                break;
              }
              if (isalpha(c) || c == '_') {
                set_anchor();
                pop();
                state = name;
                break;
              }
              throw error_t(this, "bad character");
            }
          }
          break;
        }
        case start_slash: {
          switch (c) {
            case '*': {
              pop();
              state = multiline_comment;
              break;
            }
            case '/': {
              pop();
              state = oneline_comment;
              break;
            }
            default: {
              throw error_t(this, "bad character");
            }
          }
          break;
        }
        case start_equal: {
          switch (c) {
            case '\0': {
              go = false;
              throw error_t(this, "end-of-program after equals");
              break;
            }
            case '=': {
              pop();
              tokens.emplace_back(anchor_pos, token_t::eq_op);
              state = start;
              break;
            }
            default: {
              tokens.emplace_back(anchor_pos, token_t::equal);
              state = start;
              break;
            }
          }
        }
        case multiline_comment: {
          pop();
          if (c == '*') {
            state = multiline_comment_end_star;
          }
          break;
        }
        case multiline_comment_end_star: {
          pop();
          if (c == '/') {
            state = start;
          } else {
            state = multiline_comment;
          }
          break;
        }
        case oneline_comment: {
          pop();
          if (!c || c == '\n') {
            state = start;
          }
          break;
        }
        case name: {
          if (isalnum(c) || c == '_') {
            pop();
          } else {
            auto text = pop_anchor();
            auto kind = token_t::str_to_kind(text);

            if (kind == token_t::identifier) {
              tokens.emplace_back(anchor_pos, kind, std::move(text));
            } else {
              tokens.emplace_back(anchor_pos, kind);
            }
            state = start;
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

  /* Sets an anchor at the current cursor position. Throws if
     anchor is alread defined. Anchor should not be set if
     a previous anchor was dropped. */
  void set_anchor() const {
    anchor_pos = pos;

    if (anchor) {
      throw ice_t(pos, __FILE__, __LINE__);
    }

    anchor = cursor;
  }

  /* Return the lexeme starting from anchor, and set anchor to null */
  std::string pop_anchor() {
    if (!anchor) {
      throw ice_t(pos, __FILE__, __LINE__);
    }

    std::string text(anchor, cursor - anchor);
    anchor = nullptr;
    return text;
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

  /* The (line, col) cursor of an anchor. Usually the start of a lexeme. */
  mutable pos_t anchor_pos;

  /* Position in source text for anchor */
  mutable const char *anchor;

};  // lexer_t

}   // gliss
