#pragma once

#include <cctype>
#include <map>

#include "error.h"
#include "ice.h"

namespace gliss {

/* Convert source text into a vector of lines and source positions. */
class preprocessor_lexer_t final {

public:

  using pos_t = glsl::pos_t;

  /* An error in lexing. */
  class error_t final: public gliss::error_t {

  public:

    /* Report the position and what we found there. */
    error_t(const preprocessor_lexer_t *lexer, const char *msg): gliss::error_t(lexer->pos) {
      get_strm() << msg;
    }

  };  // preprocessor_lexer_t::error_t

  /* Convert the given source text into a vector of tokens, ending with an
     end token. */
  static std::vector<std::shared_ptr<std::pair<std::string, pos_t>>> lex(const char *next_cursor) {
    return preprocessor_lexer_t(next_cursor).lex();
  }

private:

  /* Used by our public lex function. */
  preprocessor_lexer_t(const char *next_cursor):
    next_cursor(next_cursor),
    is_ready(false),
    anchor(nullptr) {}

  /* Used by our public lex function. */
  std::vector<std::shared_ptr<std::pair<std::string, pos_t>>> lex() {
    enum {
      start,
      hash_start,
      name,
      directive_name,
      directive_definition,
      line
    } state = start;
    bool go = true;
    do {
      char c = peek();
      std::cout << "c = " << c << std::endl;
      if (c == '\0') {
        go = false;
      }
      switch (state) {
        case start: {
          switch (c) {
            case '#': {
              set_anchor();
              pop();
              state = hash_start;
              break;
            }
            default: {
              if (isspace(c)) {
                pop();
                break;
              }

              state = line;
              break;
            }
          } // switch (c)
          break;
        } // case start
        case hash_start: {
          if (c == '\n') { // single hash is ignored
            pop_anchor();
            pop();
            state = start;
            break;
          }
          if (isspace(c)) {
            pop();
            break;
          }
          if (c == '#') {
            throw error_t(this, "double hash beginning new line");
          }
          if (isalpha(c) || c == '_') {
            pop_anchor();
            set_anchor();
            state = directive_name;
            break;
          }
          throw error_t(this, "bad character");
          break;
        }
        case line: {
          if (c == '\n' || c == '\0') {
            state = start;
            pop();
            break;
          }

          pop();
          break;
        }
        case name: {
          throw error_t(this, "bad character");
          break;
        }
        case directive_name: {
          if (isspace(c)) {
            auto directive_name = pop_anchor();
            std::cout << "DIRECTIVE NAME = '" << directive_name << "'" << std::endl;
            pop();
            // TODO PUSH DIRECTIVE NAME
            // TODO CHECK IF PREPROCESSOR IS ALLOWED
            // ALLOWED DIRECTIVES
            // #
            // #define
            // #undef
            // #if
            // #ifdef
            // #ifndef
            // #else
            // #elif
            // #endif
            // #error
            // #pragma
            // #extension
            // #version
            // #line
            if (c == '\n') {
              state = start;
            } else {
              state = directive_definition;
            }
            break;
          }
          if (isalpha(c)) {
            pop();
            break;
          }
          throw error_t(this, "bad character in directive name");
          break;
        }
        case directive_definition: {
          lex_directive_definition();
          state = start;
          break;
        }
      } // switch(state)
    } while (go);
    throw std::runtime_error("not implemented");
  }

  /* advance cursor to the next line */
  void lex_directive_definition() {
    enum {
      start,
      identifier
    } state = start;
    for (;;) {
      char c = peek();
      std::cout << "def c = " << c << std::endl;
      if (c == '\n' || c == '\0') {
        // TODO PUSH END OF DIRECTIVE DEFINITION
        pop();
        break;
      }
      switch (state) {
        case start: {
          switch (c) {
            case '(': {
              pop();
              // TODO PUSH OPEN PAREN
              break;
            }
            case ')': {
              pop();
              // TODO PUSH CLOSE PAREN
              break;
            }
            case '-': {
              pop();
              // TODO PUSH MINUS
              break;
            }
            case '~': {
              pop();
              // TODO PUSH TILDE
              break;
            }
            case '!': {
              pop();
              // TODO PUSH BANG
              break;
            }
            case '*': {
              pop();
              // TODO PUSH STAR
              break;
            }
            case '/': {
              pop();
              // TODO PUSH SLASH
              break;
            }
            case '%': {
              pop();
              // TODO PUSH PERCENT
              break;
            }
            case '+': {
              pop();
              // TODO PUSH TILDE
              break;
            }
            case '<': {
              pop();
              // TODO PUSH LEFT ANGLE
              break;
            }
            case '>': {
              pop();
              // TODO PUSH RIGHT ANGLE
              break;
            }
            case '=': {
              pop();
              // TODO PUSH EQUAL OP
              break;
            }
            case '&': {
              pop();
              // TODO PUSH AMPERSAND OP
              break;
            }
            case '^': {
              pop();
              // TODO PUSH CARET
              break;
            }
            case '|': {
              pop();
              // TODO PUSH PIPE
              break;
            }
            case ',': {
              pop();
              // TODO PUSH COMMA
              break;
            }
            default: {
              if (isalnum(c) || c == '_') {
                state = identifier;
                set_anchor();
                pop();
                break;
              }
              if (isspace(c)) {
                pop();
                break;
              }
              throw error_t(this, "unrecognized character in preprocessor definition");
              break;
            }
          }
          break;
        }
        case identifier: {
          switch (c) {
            default: {
              if (isalnum(c) || c == '_') {
                // either source code or identifier
                // we should just pop until we get to the next space
                pop();
                break;
              }

              std::cout << "IDENTIFIER = " << pop_anchor() << std::endl;
              // TODO PUSH IDENTIFIER
              state = start;
              break;
            }
          }
          break;
        }
      }
    }
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

};  // preprocessor_lexer_t

}   // gliss
