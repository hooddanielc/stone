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

  /* Heper method to print tokens returned from lex */
  static void print_tokens(const std::vector<token_t> &tokens) {
    for (const auto &token: tokens) {
      std::cout << token << std::endl;
    }
  }

private:

  /* Used by our public lex function. */
  lexer_t(const char *next_cursor):
    next_cursor(next_cursor),
    is_ready(false),
    anchor(nullptr) {}

  /* Used by our public lex function. */
  std::vector<token_t> lex() {
    enum {
      start,
      start_zero,
      start_dot,
      start_slash,
      start_star,
      start_equal,
      start_plus,
      start_minus,
      start_bang,
      start_mod,
      start_ampersand,
      start_vertical_bar,
      start_caret,
      start_left_angle,
      start_right_angle,
      right_op_start,
      left_op_start,
      multiline_comment,
      multiline_comment_end_star,
      oneline_comment,
      name,
      int_constant,
      octal_constant,
      int_suffix,
      hexadecimal_constant,
      float_constant,
      float_exponent_part
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
            case ';': add_single_token(token_t::semicolon); break;
            case '(': add_single_token(token_t::left_paren); break;
            case ')': add_single_token(token_t::right_paren); break;
            case '[': add_single_token(token_t::left_bracket); break;
            case ']': add_single_token(token_t::right_bracket); break;
            case '{': add_single_token(token_t::left_brace); break;
            case '}': add_single_token(token_t::right_brace); break;
            case '~': add_single_token(token_t::tilde); break;
            case ',': add_single_token(token_t::comma); break;
            case '0': {
              set_anchor();
              pop();
              state = start_zero;
              break;
            }
            case '.': {
              set_anchor();
              pop();
              state = start_dot;
              break;
            }
            case '+': {
              set_anchor();
              pop();
              state = start_plus;
              break;
            }
            case '-': {
              set_anchor();
              pop();
              state = start_minus;
              break;
            }
            case '/': {
              set_anchor();
              pop();
              state = start_slash;
              break;
            }
            case '*': {
              set_anchor();
              pop();
              state = start_star;
              break;
            }
            case '%': {
              set_anchor();
              pop();
              state = start_mod;
              break;
            }
            case '=': {
              set_anchor();
              pop();
              state = start_equal;
              break;
            }
            case '!': {
              set_anchor();
              pop();
              state = start_bang;
              break;
            }
            case '&': {
              set_anchor();
              pop();
              state = start_ampersand;
              break;
            }
            case '|': {
              set_anchor();
              pop();
              state = start_vertical_bar;
              break;
            }
            case '^': {
              set_anchor();
              pop();
              state = start_caret;
              break;
            }
            case '<': {
              set_anchor();
              pop();
              state = start_left_angle;
              break;
            }
            case '>': {
              set_anchor();
              pop();
              state = start_right_angle;
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
              if (isdigit(c)) {
                set_anchor();
                pop();
                state = int_constant;
                break;
              }
              throw error_t(this, "bad character");
            }
          }
          break;
        }
        case start_dot: {
          if (isdigit(c)) {
            pop();
            state = float_constant;
          } else {
            pop_anchor();
            state = start;
            tokens.emplace_back(anchor_pos, token_t::dot);
          }
        }
        case start_plus: {
          switch (c) {
            case '+': {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::inc_op);
              break;
            }
            case '=': {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::add_assign);
              break;
            }
            default: {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::plus);
              break;
            }
          }
          break;
        }
        case start_minus: {
          switch (c) {
            case '-': {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::dec_op);
              break;
            }
            case '=': {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::sub_assign);
              break;
            }
            default: {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::dash);
              break;
            }
          }
          break;
        }
        case start_star: {
          switch (c) {
            case '=': {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::mul_assign);
              break;
            }
            default: {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::star);
              break;
            }
          }
          break;
        }
        case start_bang: {
          switch (c) {
            case '=': {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::ne_op);
              break;
            }
            default: {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::bang);
              break;
            }
          }
          break;
        }
        case start_ampersand: {
          switch (c) {
            case '=': {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::and_assign);
              break;
            }
            case '&': {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::and_op);
              break;
            }
            default: {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::ampersand);
              break;
            }
          }
          break;
        }
        case start_vertical_bar: {
          switch (c) {
            case '=': {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::or_assign);
              break;
            }
            case '|': {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::or_op);
              break;
            }
            default: {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::ampersand);
              break;
            }
          }
          break;
        }
        case start_mod: {
          switch (c) {
            case '=': {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::mod_assign);
              break;
            }
            default: {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::percent);
              break;
            }
          }
          break;
        }
        case start_caret: {
          switch (c) {
            case '=': {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::xor_assign);
              break;
            }
            case '^': {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::xor_op);
              break;
            }
            default: {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::caret);
              break;
            }
          }
          break;
        }
        case start_left_angle: {
          switch (c) {
            case '=': {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::le_op);
              break;
            }
            case '<': {
              pop();
              state = left_op_start;
              break;
            }
            default: {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::left_angle);
              break;
            }
          }
          break;
        }
        case left_op_start: {
          switch (c) {
            case '=': {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::left_assign);
              break;
            }
            default: {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::left_op);
              break;
            }
          }
          break;
        }
        case start_right_angle: {
          switch (c) {
            case '=': {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::ge_op);
              break;
            }
            case '>': {
              pop();
              state = right_op_start;
              break;
            }
            default: {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::right_angle);
              break;
            }
          }
          break;
        }
        case right_op_start: {
          switch (c) {
            case '=': {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::right_assign);
              break;
            }
            default: {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::right_op);
              break;
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
            case '=': {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::div_assign);
              break;
            }
            default: {
              pop_anchor();
              pop();
              state = start;
              tokens.emplace_back(anchor_pos, token_t::slash);
              break;
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
              pop_anchor();
              pop();
              tokens.emplace_back(anchor_pos, token_t::eq_op);
              state = start;
              break;
            }
            default: {
              pop_anchor();
              tokens.emplace_back(anchor_pos, token_t::equal);
              state = start;
              break;
            }
          }
          break;
        }
        case multiline_comment: {
          pop();
          if (c == '*') {
            state = multiline_comment_end_star;
          }
          break;
        }
        case multiline_comment_end_star: {
          if (c == '/') {
            pop_anchor();
            state = start;
          } else {
            state = multiline_comment;
          }
          pop();
          break;
        }
        case oneline_comment: {
          pop();
          if (!c || c == '\n') {
            pop_anchor();
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
        case start_zero: {
          if (c == 'x' || c == 'X') {
            pop();
            state = hexadecimal_constant;
            break;
          }
          if (c == 'u' || c == 'U') {
            pop();
            state = int_suffix;
            break;
          }
          if (isspace(c)) {
            auto text = pop_anchor();
            pop();
            tokens.emplace_back(anchor_pos, token_t::intconstant, std::move(text));
            state = start;
            break;
          }
          if (isdigit(c)) {
            pop();
            state = octal_constant;
            break;
          }
          throw error_t(this, "bad character after leading zero");
        }
        case int_constant: {
          if (c == '.') {
            pop();
            state = float_constant;
            break;
          }
          if (c == 'u' || c == 'U') {
            pop();
            state = int_suffix;
            break;
          }
          if (isdigit(c)) {
            pop();
            break;
          }
          if (c == 'e' || c == 'E') {
            pop();
            state = float_exponent_part;
            break;
          }
          if (isspace(c)) {
            auto text = pop_anchor();
            pop();
            tokens.emplace_back(anchor_pos, token_t::intconstant);
            break;
          }
          throw error_t(this, "bad character in integer-constant");
        }
        case int_suffix: {
          if (!isspace(c)) {
            throw error_t(this, "bad character after integer-suffix");
          }
          auto text = pop_anchor();
          pop();
          tokens.emplace_back(anchor_pos, token_t::intconstant, std::move(text));
          state = start;
          break;
        }
        case hexadecimal_constant: {
          break;
        }
        case octal_constant: {
          break;
        }
        case float_constant: {
          if (c == 'l' || c == 'L') {
            break;
          }
          if (c == 'f' || c == 'F') {
            break;
          }
          if (c == 'e' || c == 'E') {
            pop();
            state = float_exponent_part;
            break;
          }
          if (isdigit(c)) {
            pop();
            break;
          }
          if (isspace(c)) {
            auto text = pop_anchor();
            pop();
            tokens.emplace_back(anchor_pos, token_t::floatconstant, std::move(text));
            state = start;
            break;
          }

          throw error_t(this, "bad character in floating-point constant");
        }
        case float_exponent_part: {
          break;
        }
      }  // switch
    } while (go);
    return std::move(tokens);
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

  /* Add a token at the current position, set anchor, advance 1 character
     and reset anchor. Used for tokens using only one character that can
     not be included in multi character tokens. ex. left_paren, right_paren
     etc.*/
  void add_single_token(token_t::kind_t kind) {
    set_anchor();
    pop();
    pop_anchor();
    tokens.emplace_back(anchor_pos, kind);
  }

  /* Temporarily holds tokens while lexing */
  std::vector<token_t> tokens;

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
