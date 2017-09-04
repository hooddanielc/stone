#pragma once

#include <iostream>
#include "util.h"
#include "pos.h"
#include "error.h"
#include "ice.h"

namespace biglr {

class token_t final {

public:

  /* Tokens come in various kinds. */
  enum kind_t {
    slash_name,
    reduction,
    identifier,
    newline,
    arrow
  };

  token_t(const pos_t &pos, kind_t kind): pos(pos), kind(kind) {}

  token_t(const pos_t &pos, kind_t kind, std::string text):
    pos(pos),
    kind(kind),
    text(std::move(text)) {}

  kind_t get_kind() const {
    return kind;
  }

  pos_t get_pos() const {
    return pos;
  }

  std::string get_text() const {
    return text;
  }

  std::string get_description() const {
    switch (get_kind()) {
      case token_t::slash_name: return "slash_name";
      case token_t::reduction: return "reduction";
      case token_t::identifier: return "identifier";
      case token_t::newline: return "newline";
      case token_t::arrow: return "arrow";
    }
    return "unknown";
  }

private:

  pos_t pos;

  kind_t kind;

  std::string text;

};  // token_t

class grammar_t {

public:

  static std::shared_ptr<grammar_t> make(const char *grammar_src) {
    auto grammar = new grammar_t(grammar_src);
    std::shared_ptr<grammar_t> ptr(grammar);
    ptr->lex();
    return ptr;
  }

  static std::shared_ptr<grammar_t> from_file(const std::string &path) {
    auto str = get_file_contents(path);
    return make(str.c_str());
  }

  /* An error in lexing. */
  class error_t final: public biglr::error_t {

  public:

    /* Report the position and what we found there. */
    error_t(const grammar_t *lexer, const char *msg): biglr::error_t(lexer->pos) {
      get_strm() << msg;
    }

  };  // grammar_t::error_t

private:

  std::vector<token_t> tokens;

  /* Used by our public lex function. */
  grammar_t(const char *next_cursor):
    next_cursor(next_cursor),
    is_ready(false),
    anchor(nullptr) {}

  void parse_tokens() {
    for (const auto &token: tokens) {
      std::cout << token.get_description() << std::endl;
    }
  }

  void lex() {
    enum {
      newline,
      slash,
      slash_name,
      token_start,
      token_name,
      reduction_name,
      arrow_start,
      arrow_end,
      identifier_start,
      identifier,
      arrow_or_token
    } state = newline;
    bool go = true;
    do {
      char c = peek();

      if (c == '\0') {
        break;
      }

      switch (state) {
        case newline: {
          if (c == '/') {
            pop();
            state = slash;
            break;
          }
          if (c == '_' || isalnum(c)) {
            set_anchor();
            pop();
            state = reduction_name;
            break;
          }
          if (isspace(c)) {
            pop();
            break;
          }
          throw error_t(this, "bad character");
        }
        case slash: {
          if (isalnum(c) || c == '_') {
            set_anchor();
            pop();
            state = slash_name;
            break;
          }
          throw error_t(this, "bad character");
        }
        case slash_name: {
          if (isalnum(c)) {
            pop();
            break;
          }
          if (isspace(c) && c != '\n') {
            auto text = pop_anchor();
            tokens.emplace_back(anchor_pos, token_t::slash_name, text);
            pop();
            state = arrow_or_token;
            break;
          }
          throw error_t(this, "bad character");
        }
        case arrow_or_token: {
          if (isspace(c) && c != '\n') {
            pop();
            break;
          }
          if (c == '-') {
            pop();
            state = arrow_end;
            break;
          }
          if (isalnum(c) || c == '_') {
            set_anchor();
            state = identifier;
            pop();
            break;
          }
          throw error_t(this, "bad character");
        }
        case arrow_start: {
          if (isspace(c) && c != '\n') {
            pop();
            break;
          }
          if (c == '-') {
            pop();
            state = arrow_end;
            break;
          }
          throw error_t(this, "bad character");
        }
        case arrow_end: {
          if (c == '>') {
            tokens.emplace_back(pos, token_t::arrow);
            pop();
            state = identifier_start;
            break;
          }
          throw error_t(this, "bad character");
        }
        case reduction_name: {
          if (isalnum(c) || c == '_') {
            pop();
            break;
          }
          if (isspace(c) && c != '\n') {
            auto text = pop_anchor();
            tokens.emplace_back(anchor_pos, token_t::reduction, text);
            state = arrow_start;
            pop();
            break;
          }
          throw error_t(this, "bad character");
        }
        case identifier_start: {
          if (c == '\n') {
            tokens.emplace_back(anchor_pos, token_t::newline);
            state = newline;
            pop();
            break;
          }
          if (isspace(c)) {
            pop();
            break;
          }
          if (isalnum(c) || c == '_') {
            set_anchor();
            pop();
            state = identifier;
            break;
          }
          throw error_t(this, "bad character");
        }
        case identifier: {
          if (isalnum(c) || c == '_') {
            pop();
            break;
          }
          if (isspace(c)) {
            auto text = pop_anchor();
            tokens.emplace_back(anchor_pos, token_t::identifier, text);
            if (c == '\n') {
              tokens.emplace_back(pos, token_t::newline);
              state = newline;
            } else {
              state = identifier_start;
            }
            pop();
            break;
          }
          throw error_t(this, "bad character");
        }
        default: {
          if (c == '\0') {
            go = false;
            break;
          }
          throw error_t(this, "bad character");
        }
      }
    } while (go == true);
    parse_tokens();
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

};  // grammar_t

}   // biglr
