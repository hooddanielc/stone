#pragma once

#include <iostream>
#include "util.h"
#include "pos.h"
#include "error.h"
#include "ice.h"
#include "rule.h"
#include "symbol.h"

namespace biglr {

/* Token class for grammar file syntax */
class g_tok_t final {

public:

  /* Tokens come in various kinds. */
  enum kind_t {
    slash_name,
    reduction,
    identifier,
    newline,
    arrow
  };

  g_tok_t(const pos_t &pos, kind_t kind): pos(pos), kind(kind) {}

  g_tok_t(const pos_t &pos, kind_t kind, std::string text):
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
      case g_tok_t::slash_name: return "slash_name";
      case g_tok_t::reduction: return "reduction";
      case g_tok_t::identifier: return "identifier";
      case g_tok_t::newline: return "newline";
      case g_tok_t::arrow: return "arrow";
    }
    return "unknown";
  }

private:

  pos_t pos;

  kind_t kind;

  std::string text;

};  // g_tok_t

class lexer_t {

public:

  static std::shared_ptr<lexer_t> make(const char *grammar_src) {
    auto lexer = new lexer_t(grammar_src);
    std::shared_ptr<lexer_t> ptr(lexer);
    ptr->lex();
    return ptr;
  }

  /* An error in lexing. */
  class error_t final: public biglr::error_t {

  public:

    /* Report the position and what we found there. */
    error_t(const lexer_t *lexer, const char *msg): biglr::error_t(lexer->pos) {
      get_strm() << msg;
    }

  };  // lexer_t::error_t

  /* An error in parsing. */
  class parse_error_t final: public biglr::error_t {

  public:

    /* Report the position and what we found there. */
    parse_error_t(const g_tok_t &token, const char *msg): biglr::error_t(token.get_pos()) {
      get_strm() << msg;
    }

  };  // lexer_t::error_t

  std::vector<std::shared_ptr<rule_t>> get_rules() {
    return parsed_rules;
  }

  std::vector<std::shared_ptr<token_t>> get_tokens() {
    return parsed_tokens;
  }

  std::vector<std::shared_ptr<reduction_t>> get_reductions() {
    return parsed_reductions;
  }

private:

  std::vector<std::shared_ptr<rule_t>> parsed_rules;

  std::vector<std::shared_ptr<token_t>> parsed_tokens;

  std::vector<std::shared_ptr<reduction_t>> parsed_reductions;

  std::vector<g_tok_t> lex_tokens;

  /* Used by our public lex function. */
  lexer_t(const char *next_cursor):
    next_cursor(next_cursor),
    is_ready(false),
    anchor(nullptr) {}

  void parse_tokens() {
    enum {
      newline,
      slash_token,
      slash_top,
      reduction_start,
      reduction_rules
    } state = newline;
    std::vector<std::shared_ptr<symbol_t>> symbols;
    std::vector<std::shared_ptr<reduction_t>> reductions;
    rule_t::rhs_t rhs;
    std::vector<std::shared_ptr<rule_t>> rules;

    for (const auto &token: lex_tokens) {
      if (state == newline) {
        switch (token.get_kind()) {
          case g_tok_t::slash_name:
            if (token.get_text() == "token") {
              state = slash_token;
            } else if (token.get_text() == "top") {
              rhs.clear();
              reductions.push_back(top_t::make());
              state = slash_top;
            } else {
              throw parse_error_t(token, "unrecognized slash name");
            }
            break;
          case g_tok_t::reduction:
            rhs.clear();
            reductions.push_back(reduction_t::make(token.get_text()));
            state = reduction_start;
            break;
          default:
            throw parse_error_t(token, "unrecognized token at new line");
        }
      } else if (state == reduction_start) {
        if (token.get_kind() == g_tok_t::arrow) {
          state = reduction_rules;
        } else {
          throw parse_error_t(token, "unrecognized token after reduction name");
        }
      } else if (state == reduction_rules) {
        if (token.get_kind() == g_tok_t::identifier) {
          if (token_t::exists(token.get_text())) {
            rhs.push_back(token_t::make(token.get_text()));
          } else {
            rhs.push_back(reduction_t::make(token.get_text()));
          }
        } else if (token.get_kind() == g_tok_t::newline) {
          rules.push_back(rule_t::make(reductions.back(), rhs));
          rhs.clear();
          state = newline;
        } else {
          throw parse_error_t(token, "unrecognized token after reduction arrow");
        }
      } else if (state == slash_token) {
        if (token.get_kind() == g_tok_t::identifier) {
          symbols.push_back(token_t::make(token.get_text()));
        } else if (token.get_kind() == g_tok_t::newline) {
          state = newline;
        } else {
          throw parse_error_t(token, "unrecognized token after /token");
        }
      } else if (state == slash_top) {
        if (token.get_kind() == g_tok_t::arrow) {
          state = reduction_rules;
        } else {
          throw parse_error_t(token, "unrecognized token after /token");
        }
      } else {
        throw parse_error_t(token, "unexpected token");
      }
    }

    parsed_tokens = token_t::get_store();
    parsed_tokens.push_back(break_t::make());
    parsed_reductions = reduction_t::get_store();
    parsed_rules = rule_t::get_store();
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
      arrow_or_token,
      escape_arrow_or_token,
      escape_identifier_start,
      comment_start
    } state = newline;
    bool go = true;
    do {
      char c = peek();

      if (c == '\0') {
        break;
      }

      switch (state) {
        case escape_arrow_or_token: {
          if (c == '\n') {
            pop();
            state = identifier_start;
            break;
          }
          throw error_t(this, "bad character escape_arrow_or_token");
          break;
        }
        case escape_identifier_start: {
          if (c == '\n') {
            pop();
            state = identifier_start;
            break;
          }
          throw error_t(this, "bad character escape_identifier_start");
          break;
        }
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
          throw error_t(this, "bad character newline");
        }
        case slash: {
          if (c == '/') {
            pop();
            state = comment_start;
            break;          
          }
          if (isalnum(c) || c == '_') {
            set_anchor();
            pop();
            state = slash_name;
            break;
          }
          throw error_t(this, "bad character slash");
        }
        case comment_start: {
          if (c == '\n') {
            state = newline;
          }
          pop();
          break;
        }
        case slash_name: {
          if (isalnum(c)) {
            pop();
            break;
          }
          if (isspace(c) && c != '\n') {
            auto text = pop_anchor();
            lex_tokens.emplace_back(anchor_pos, g_tok_t::slash_name, text);
            pop();
            state = arrow_or_token;
            break;
          }
          throw error_t(this, "bad character slash_name");
        }
        case arrow_or_token: {
          if (c == '\\') {
            state = escape_identifier_start;
            pop();
            break;
          }
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
          throw error_t(this, "bad character arrow_or_token");
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
          throw error_t(this, "bad character arrow_start");
        }
        case arrow_end: {
          if (c == '>') {
            lex_tokens.emplace_back(pos, g_tok_t::arrow);
            pop();
            state = identifier_start;
            break;
          }
          throw error_t(this, "bad character arrow_end");
        }
        case reduction_name: {
          if (isalnum(c) || c == '_') {
            pop();
            break;
          }
          if (isspace(c) && c != '\n') {
            auto text = pop_anchor();
            lex_tokens.emplace_back(anchor_pos, g_tok_t::reduction, text);
            state = arrow_start;
            pop();
            break;
          }
          throw error_t(this, "bad character reduction_name");
        }
        case identifier_start: {
          if (c == '\\') {
            state = escape_identifier_start;
            pop();
            break;
          }
          if (c == '\n') {
            lex_tokens.emplace_back(anchor_pos, g_tok_t::newline);
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
          throw error_t(this, "bad character identifier_start");
        }
        case identifier: {
          if (isalnum(c) || c == '_') {
            pop();
            break;
          }
          if (isspace(c)) {
            auto text = pop_anchor();
            lex_tokens.emplace_back(anchor_pos, g_tok_t::identifier, text);
            if (c == '\n') {
              lex_tokens.emplace_back(pos, g_tok_t::newline);
              state = newline;
            } else {
              state = identifier_start;
            }
            pop();
            break;
          }
          throw error_t(this, "bad character identifier");
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

};  // lexer_t

}   // biglr
