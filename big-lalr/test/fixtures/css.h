#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <functional>

namespace css {

class symbol_t {

public:

  enum kind_t {
      __break__ = 0,
      PERIOD = 1,
      ANY_VALUE = 2,
      WHITESPACE = 3,
      DOLLAR = 4,
      HASH_TOKEN = 5,
      COMMENT = 6,
      LEFT_PAREN = 7,
      CARET = 8,
      LESSER_THEN = 9,
      NEWLINE = 10,
      COMMA = 11,
      TAB = 12,
      PLUS = 13,
      IDENT_TOKEN = 14,
      RIGHT_BRACKET = 15,
      RIGHT_PAREN = 16,
      GREATER_THAN = 17,
      COLUMN_TOKEN = 18,
      TILDE = 19,
      HEX_DIGIT = 20,
      CDC_TOKEN = 21,
      PIPE = 22,
      ESCAPE = 23,
      ASTERISK = 24,
      STRING_TOKEN = 25,
      NUMBER_TOKEN = 26,
      UNICODE_RANGE_TOKEN = 27,
      INCLUDE_MATCH_TOKEN = 28,
      PREFIX_MATCH_TOKEN = 29,
      COLON = 30,
      DASH_MATCH_TOKEN = 31,
      PERCENT = 32,
      LETTER_I = 33,
      SUFFIX_MATCH_TOKEN = 34,
      LEFT_BRACKET = 35,
      EQUALS = 36,
      CDO_TOKEN = 37,
      SUBSTRING_MATCH_TOKEN = 38,
      AT = 39,
      ATTR_MATCHER = 40,
      CLASS_SELECTOR = 41,
      NS_PREFIX = 42,
      TYPE_SELECTOR = 43,
      COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST = 44,
      ATTR_MODIFIER = 45,
      COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST = 46,
      ATTRIBUTE_SELECTOR = 47,
      DIMENSION_TOKEN = 48,
      WQ_NAME = 49,
      SIMPLE_SELECTOR = 50,
      PSEUDO_CLASS_SELECTOR = 51,
      AT_KEYWORD_TOKEN = 52,
      PERCENTAGE_TOKEN = 53,
      ID_SELECTOR = 54,
      SUBCLASS_SELECTOR = 55,
      COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST = 56,
      PSEUDO_ELEMENT_SELECTOR = 57,
      COMPOUND_SELECTOR_LIST = 58,
      FUNCTION_TOKEN = 59,
      WHITESPACE_TOKEN = 60,
      COMPLEX_SELECTOR_LIST = 61,
      COMPOUND_SELECTOR = 62,
      SIMPLE_SELECTOR_LIST = 63,
      RELATIVE_SELECTOR_LIST = 64,
      COMPLEX_SELECTOR = 65,
      RELATIVE_SELECTOR = 66,
      SELECTOR_LIST = 67,
      COMBINATOR = 68,
      __omega__ = 69
  };   // symbol_t

  static std::string get_name(const kind_t &kind) {
    switch(kind) {
      case __break__: return "__break__";
      case PERIOD: return "PERIOD";
      case ANY_VALUE: return "ANY_VALUE";
      case WHITESPACE: return "WHITESPACE";
      case DOLLAR: return "DOLLAR";
      case HASH_TOKEN: return "HASH_TOKEN";
      case COMMENT: return "COMMENT";
      case LEFT_PAREN: return "LEFT_PAREN";
      case CARET: return "CARET";
      case LESSER_THEN: return "LESSER_THEN";
      case NEWLINE: return "NEWLINE";
      case COMMA: return "COMMA";
      case TAB: return "TAB";
      case PLUS: return "PLUS";
      case IDENT_TOKEN: return "IDENT_TOKEN";
      case RIGHT_BRACKET: return "RIGHT_BRACKET";
      case RIGHT_PAREN: return "RIGHT_PAREN";
      case GREATER_THAN: return "GREATER_THAN";
      case COLUMN_TOKEN: return "COLUMN_TOKEN";
      case TILDE: return "TILDE";
      case HEX_DIGIT: return "HEX_DIGIT";
      case CDC_TOKEN: return "CDC_TOKEN";
      case PIPE: return "PIPE";
      case ESCAPE: return "ESCAPE";
      case ASTERISK: return "ASTERISK";
      case STRING_TOKEN: return "STRING_TOKEN";
      case NUMBER_TOKEN: return "NUMBER_TOKEN";
      case UNICODE_RANGE_TOKEN: return "UNICODE_RANGE_TOKEN";
      case INCLUDE_MATCH_TOKEN: return "INCLUDE_MATCH_TOKEN";
      case PREFIX_MATCH_TOKEN: return "PREFIX_MATCH_TOKEN";
      case COLON: return "COLON";
      case DASH_MATCH_TOKEN: return "DASH_MATCH_TOKEN";
      case PERCENT: return "PERCENT";
      case LETTER_I: return "LETTER_I";
      case SUFFIX_MATCH_TOKEN: return "SUFFIX_MATCH_TOKEN";
      case LEFT_BRACKET: return "LEFT_BRACKET";
      case EQUALS: return "EQUALS";
      case CDO_TOKEN: return "CDO_TOKEN";
      case SUBSTRING_MATCH_TOKEN: return "SUBSTRING_MATCH_TOKEN";
      case AT: return "AT";
      case ATTR_MATCHER: return "ATTR_MATCHER";
      case CLASS_SELECTOR: return "CLASS_SELECTOR";
      case NS_PREFIX: return "NS_PREFIX";
      case TYPE_SELECTOR: return "TYPE_SELECTOR";
      case COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST: return "COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST";
      case ATTR_MODIFIER: return "ATTR_MODIFIER";
      case COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST: return "COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST";
      case ATTRIBUTE_SELECTOR: return "ATTRIBUTE_SELECTOR";
      case DIMENSION_TOKEN: return "DIMENSION_TOKEN";
      case WQ_NAME: return "WQ_NAME";
      case SIMPLE_SELECTOR: return "SIMPLE_SELECTOR";
      case PSEUDO_CLASS_SELECTOR: return "PSEUDO_CLASS_SELECTOR";
      case AT_KEYWORD_TOKEN: return "AT_KEYWORD_TOKEN";
      case PERCENTAGE_TOKEN: return "PERCENTAGE_TOKEN";
      case ID_SELECTOR: return "ID_SELECTOR";
      case SUBCLASS_SELECTOR: return "SUBCLASS_SELECTOR";
      case COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST: return "COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST";
      case PSEUDO_ELEMENT_SELECTOR: return "PSEUDO_ELEMENT_SELECTOR";
      case COMPOUND_SELECTOR_LIST: return "COMPOUND_SELECTOR_LIST";
      case FUNCTION_TOKEN: return "FUNCTION_TOKEN";
      case WHITESPACE_TOKEN: return "WHITESPACE_TOKEN";
      case COMPLEX_SELECTOR_LIST: return "COMPLEX_SELECTOR_LIST";
      case COMPOUND_SELECTOR: return "COMPOUND_SELECTOR";
      case SIMPLE_SELECTOR_LIST: return "SIMPLE_SELECTOR_LIST";
      case RELATIVE_SELECTOR_LIST: return "RELATIVE_SELECTOR_LIST";
      case COMPLEX_SELECTOR: return "COMPLEX_SELECTOR";
      case RELATIVE_SELECTOR: return "RELATIVE_SELECTOR";
      case SELECTOR_LIST: return "SELECTOR_LIST";
      case COMBINATOR: return "COMBINATOR";
      case __omega__: return "__omega__";
    }
    return "unknown";
  }
};

class pos_t final {

public:

  pos_t() noexcept: line_number(1), col_number(1) {}

  void next_col() {
    ++col_number;
  }

  void next_line() {
    ++line_number;
    col_number = 1;
  }

  int get_line() const {
    return line_number;
  }

  int get_col() const {
    return col_number;
  }

  friend std::ostream &operator<<(std::ostream &strm, const pos_t &that) {
    return strm
        << "line " << that.line_number
        << ", col " << that.col_number;
  }

private:

  int line_number, col_number;

};  // pos_t


    class token_t {
    public:
  
  enum kind_t {
    PERIOD = 1,
    ANY_VALUE = 2,
    WHITESPACE = 3,
    DOLLAR = 4,
    HASH_TOKEN = 5,
    COMMENT = 6,
    LEFT_PAREN = 7,
    CARET = 8,
    LESSER_THEN = 9,
    NEWLINE = 10,
    COMMA = 11,
    TAB = 12,
    PLUS = 13,
    IDENT_TOKEN = 14,
    RIGHT_BRACKET = 15,
    RIGHT_PAREN = 16,
    GREATER_THAN = 17,
    COLUMN_TOKEN = 18,
    TILDE = 19,
    HEX_DIGIT = 20,
    CDC_TOKEN = 21,
    PIPE = 22,
    ESCAPE = 23,
    ASTERISK = 24,
    STRING_TOKEN = 25,
    NUMBER_TOKEN = 26,
    UNICODE_RANGE_TOKEN = 27,
    INCLUDE_MATCH_TOKEN = 28,
    PREFIX_MATCH_TOKEN = 29,
    COLON = 30,
    DASH_MATCH_TOKEN = 31,
    PERCENT = 32,
    LETTER_I = 33,
    SUFFIX_MATCH_TOKEN = 34,
    LEFT_BRACKET = 35,
    EQUALS = 36,
    CDO_TOKEN = 37,
    SUBSTRING_MATCH_TOKEN = 38,
    AT = 39
  };   // kind_t

      /* Cache the kind. */
      token_t(kind_t kind): kind(kind) {}

      /* Cache the position and kind and set the text to the empty string. */
      token_t(const pos_t &pos, kind_t kind): pos(pos), kind(kind) {}

      /* Cache the position and kind and the text. */
      token_t(const pos_t &pos, kind_t kind, std::string &&text):
        pos(pos),
        kind(kind),
        text(std::move(text)) {}
  

  static std::string get_desc(kind_t kind) {
    switch(kind) {
      case PERIOD: return "PERIOD";
      case ANY_VALUE: return "ANY_VALUE";
      case WHITESPACE: return "WHITESPACE";
      case DOLLAR: return "DOLLAR";
      case HASH_TOKEN: return "HASH_TOKEN";
      case COMMENT: return "COMMENT";
      case LEFT_PAREN: return "LEFT_PAREN";
      case CARET: return "CARET";
      case LESSER_THEN: return "LESSER_THEN";
      case NEWLINE: return "NEWLINE";
      case COMMA: return "COMMA";
      case TAB: return "TAB";
      case PLUS: return "PLUS";
      case IDENT_TOKEN: return "IDENT_TOKEN";
      case RIGHT_BRACKET: return "RIGHT_BRACKET";
      case RIGHT_PAREN: return "RIGHT_PAREN";
      case GREATER_THAN: return "GREATER_THAN";
      case COLUMN_TOKEN: return "COLUMN_TOKEN";
      case TILDE: return "TILDE";
      case HEX_DIGIT: return "HEX_DIGIT";
      case CDC_TOKEN: return "CDC_TOKEN";
      case PIPE: return "PIPE";
      case ESCAPE: return "ESCAPE";
      case ASTERISK: return "ASTERISK";
      case STRING_TOKEN: return "STRING_TOKEN";
      case NUMBER_TOKEN: return "NUMBER_TOKEN";
      case UNICODE_RANGE_TOKEN: return "UNICODE_RANGE_TOKEN";
      case INCLUDE_MATCH_TOKEN: return "INCLUDE_MATCH_TOKEN";
      case PREFIX_MATCH_TOKEN: return "PREFIX_MATCH_TOKEN";
      case COLON: return "COLON";
      case DASH_MATCH_TOKEN: return "DASH_MATCH_TOKEN";
      case PERCENT: return "PERCENT";
      case LETTER_I: return "LETTER_I";
      case SUFFIX_MATCH_TOKEN: return "SUFFIX_MATCH_TOKEN";
      case LEFT_BRACKET: return "LEFT_BRACKET";
      case EQUALS: return "EQUALS";
      case CDO_TOKEN: return "CDO_TOKEN";
      case SUBSTRING_MATCH_TOKEN: return "SUBSTRING_MATCH_TOKEN";
      case AT: return "AT";
    }
    return "unknown";
  }


  kind_t get_kind() const {
    return kind;
  }

  std::string get_text() const {
    return text;
  }

  std::string get_name() const {
    return token_t::get_desc(kind);
  }

  pos_t get_pos() const {
    return pos;
  }

  static std::shared_ptr<token_t> make(kind_t kind) {
    auto ptr = new token_t(kind);
    std::shared_ptr<token_t> result(ptr);
    return result;
  }

  static std::shared_ptr<token_t> make(const pos_t &pos, kind_t kind) {
    auto ptr = new token_t(pos, kind);
    std::shared_ptr<token_t> result(ptr);
    return result;
  }

  static std::shared_ptr<token_t> make(const pos_t &pos, kind_t kind, std::string &&text) {
    auto ptr = new token_t(pos, kind, std::move(text));
    std::shared_ptr<token_t> result(ptr);
    return result;
  }

protected:

  /* Writes a human-readable dump of the token.  This is for debugging
     purposes only.  In production, a user never sees tokens directly. */
  friend std::ostream &operator<<(std::ostream &strm, const token_t &that) {
    strm << that.pos << "; " << get_desc(that.kind);
    if (!that.text.empty()) {
      strm << "; \"" << that.text << '"';
    }
    return strm;
  }

  friend std::ostream &operator<<(std::ostream &strm, const token_t *that) {
    strm << *that;
    return strm;
  }

  /* See accessors. */
  pos_t pos;

  /* See accessor. */
  kind_t kind;

  /* See accessor. */
  std::string text;
};   // token_t
class __omega___branch_t;
class __omega___from_SELECTOR_LIST_t;
class ATTR_MATCHER_branch_t;
class ATTR_MATCHER_from_ASTERISK_EQUALS_t;
class ATTR_MATCHER_from_DOLLAR_EQUALS_t;
class ATTR_MATCHER_from_CARET_EQUALS_t;
class ATTR_MATCHER_from_PIPE_EQUALS_t;
class ATTR_MATCHER_from_TILDE_EQUALS_t;
class ATTR_MATCHER_from_EQUALS_t;
class CLASS_SELECTOR_branch_t;
class CLASS_SELECTOR_from_PERIOD_IDENT_TOKEN_t;
class NS_PREFIX_branch_t;
class NS_PREFIX_from_PIPE_t;
class NS_PREFIX_from_IDENT_TOKEN_ASTERISK_PIPE_t;
class NS_PREFIX_from_IDENT_TOKEN_PIPE_t;
class NS_PREFIX_from_ASTERISK_PIPE_t;
class TYPE_SELECTOR_branch_t;
class TYPE_SELECTOR_from_WQ_NAME_t;
class TYPE_SELECTOR_from_ASTERISK_t;
class TYPE_SELECTOR_from_NS_PREFIX_ASTERISK_t;
class COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_branch_t;
class COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_t;
class COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t;
class COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t;
class COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t;
class ATTR_MODIFIER_branch_t;
class ATTR_MODIFIER_from_LETTER_I_t;
class COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_branch_t;
class COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_PSEUDO_CLASS_SELECTOR_t;
class COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_PSEUDO_CLASS_SELECTOR_t;
class ATTRIBUTE_SELECTOR_branch_t;
class ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_RIGHT_BRACKET_t;
class ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t;
class ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t;
class ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_RIGHT_BRACKET_t;
class ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_RIGHT_BRACKET_t;
class DIMENSION_TOKEN_branch_t;
class DIMENSION_TOKEN_from_NUMBER_TOKEN_IDENT_TOKEN_t;
class WQ_NAME_branch_t;
class WQ_NAME_from_NS_PREFIX_IDENT_TOKEN_t;
class WQ_NAME_from_IDENT_TOKEN_t;
class SIMPLE_SELECTOR_branch_t;
class SIMPLE_SELECTOR_from_TYPE_SELECTOR_t;
class SIMPLE_SELECTOR_from_SUBCLASS_SELECTOR_t;
class PSEUDO_CLASS_SELECTOR_branch_t;
class PSEUDO_CLASS_SELECTOR_from_COLON_IDENT_TOKEN_t;
class PSEUDO_CLASS_SELECTOR_from_COLON_FUNCTION_TOKEN_ANY_VALUE_RIGHT_PAREN_t;
class AT_KEYWORD_TOKEN_branch_t;
class AT_KEYWORD_TOKEN_from_AT_IDENT_TOKEN_t;
class PERCENTAGE_TOKEN_branch_t;
class PERCENTAGE_TOKEN_from_NUMBER_TOKEN_PERCENT_t;
class ID_SELECTOR_branch_t;
class ID_SELECTOR_from_HASH_TOKEN_t;
class SUBCLASS_SELECTOR_branch_t;
class SUBCLASS_SELECTOR_from_ID_SELECTOR_t;
class SUBCLASS_SELECTOR_from_CLASS_SELECTOR_t;
class SUBCLASS_SELECTOR_from_ATTRIBUTE_SELECTOR_t;
class SUBCLASS_SELECTOR_from_PSEUDO_CLASS_SELECTOR_t;
class COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_branch_t;
class COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_SUBCLASS_SELECTOR_t;
class COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_SUBCLASS_SELECTOR_t;
class PSEUDO_ELEMENT_SELECTOR_branch_t;
class PSEUDO_ELEMENT_SELECTOR_from_COLON_PSEUDO_CLASS_SELECTOR_t;
class COMPOUND_SELECTOR_LIST_branch_t;
class COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_t;
class COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_LIST_COMMA_COMPOUND_SELECTOR_t;
class FUNCTION_TOKEN_branch_t;
class FUNCTION_TOKEN_from_IDENT_TOKEN_LEFT_PAREN_t;
class WHITESPACE_TOKEN_branch_t;
class WHITESPACE_TOKEN_from_WHITESPACE_t;
class WHITESPACE_TOKEN_from_WHITESPACE_TOKEN_WHITESPACE_t;
class COMPLEX_SELECTOR_LIST_branch_t;
class COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_t;
class COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_COMMA_COMPLEX_SELECTOR_t;
class COMPOUND_SELECTOR_branch_t;
class COMPOUND_SELECTOR_from_TYPE_SELECTOR_t;
class COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t;
class COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t;
class COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t;
class COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t;
class COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t;
class COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t;
class SIMPLE_SELECTOR_LIST_branch_t;
class SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_t;
class SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_LIST_COMMA_SIMPLE_SELECTOR_t;
class RELATIVE_SELECTOR_LIST_branch_t;
class RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_t;
class RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_LIST_COMMA_RELATIVE_SELECTOR_t;
class COMPLEX_SELECTOR_branch_t;
class COMPLEX_SELECTOR_from_COMPOUND_SELECTOR_t;
class COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMBINATOR_COMPOUND_SELECTOR_t;
class COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMPOUND_SELECTOR_t;
class RELATIVE_SELECTOR_branch_t;
class RELATIVE_SELECTOR_from_COMPLEX_SELECTOR_t;
class RELATIVE_SELECTOR_from_COMBINATOR_COMPLEX_SELECTOR_t;
class SELECTOR_LIST_branch_t;
class SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_t;
class COMBINATOR_branch_t;
class COMBINATOR_from_GREATER_THAN_t;
class COMBINATOR_from_PLUS_t;
class COMBINATOR_from_TILDE_t;
class COMBINATOR_from_COLUMN_TOKEN_t;
class ast_token_t;

/* default visitor */
struct default_visitor_t {
  virtual ~default_visitor_t() = default;
  virtual void operator()(const __omega___branch_t *) const = 0;
  virtual void operator()(const __omega___from_SELECTOR_LIST_t *) const = 0;
  virtual void operator()(const ATTR_MATCHER_branch_t *) const = 0;
  virtual void operator()(const ATTR_MATCHER_from_ASTERISK_EQUALS_t *) const = 0;
  virtual void operator()(const ATTR_MATCHER_from_DOLLAR_EQUALS_t *) const = 0;
  virtual void operator()(const ATTR_MATCHER_from_CARET_EQUALS_t *) const = 0;
  virtual void operator()(const ATTR_MATCHER_from_PIPE_EQUALS_t *) const = 0;
  virtual void operator()(const ATTR_MATCHER_from_TILDE_EQUALS_t *) const = 0;
  virtual void operator()(const ATTR_MATCHER_from_EQUALS_t *) const = 0;
  virtual void operator()(const CLASS_SELECTOR_branch_t *) const = 0;
  virtual void operator()(const CLASS_SELECTOR_from_PERIOD_IDENT_TOKEN_t *) const = 0;
  virtual void operator()(const NS_PREFIX_branch_t *) const = 0;
  virtual void operator()(const NS_PREFIX_from_PIPE_t *) const = 0;
  virtual void operator()(const NS_PREFIX_from_IDENT_TOKEN_ASTERISK_PIPE_t *) const = 0;
  virtual void operator()(const NS_PREFIX_from_IDENT_TOKEN_PIPE_t *) const = 0;
  virtual void operator()(const NS_PREFIX_from_ASTERISK_PIPE_t *) const = 0;
  virtual void operator()(const TYPE_SELECTOR_branch_t *) const = 0;
  virtual void operator()(const TYPE_SELECTOR_from_WQ_NAME_t *) const = 0;
  virtual void operator()(const TYPE_SELECTOR_from_ASTERISK_t *) const = 0;
  virtual void operator()(const TYPE_SELECTOR_from_NS_PREFIX_ASTERISK_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_branch_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t *) const = 0;
  virtual void operator()(const ATTR_MODIFIER_branch_t *) const = 0;
  virtual void operator()(const ATTR_MODIFIER_from_LETTER_I_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_branch_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_PSEUDO_CLASS_SELECTOR_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_PSEUDO_CLASS_SELECTOR_t *) const = 0;
  virtual void operator()(const ATTRIBUTE_SELECTOR_branch_t *) const = 0;
  virtual void operator()(const ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_RIGHT_BRACKET_t *) const = 0;
  virtual void operator()(const ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t *) const = 0;
  virtual void operator()(const ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t *) const = 0;
  virtual void operator()(const ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_RIGHT_BRACKET_t *) const = 0;
  virtual void operator()(const ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_RIGHT_BRACKET_t *) const = 0;
  virtual void operator()(const DIMENSION_TOKEN_branch_t *) const = 0;
  virtual void operator()(const DIMENSION_TOKEN_from_NUMBER_TOKEN_IDENT_TOKEN_t *) const = 0;
  virtual void operator()(const WQ_NAME_branch_t *) const = 0;
  virtual void operator()(const WQ_NAME_from_NS_PREFIX_IDENT_TOKEN_t *) const = 0;
  virtual void operator()(const WQ_NAME_from_IDENT_TOKEN_t *) const = 0;
  virtual void operator()(const SIMPLE_SELECTOR_branch_t *) const = 0;
  virtual void operator()(const SIMPLE_SELECTOR_from_TYPE_SELECTOR_t *) const = 0;
  virtual void operator()(const SIMPLE_SELECTOR_from_SUBCLASS_SELECTOR_t *) const = 0;
  virtual void operator()(const PSEUDO_CLASS_SELECTOR_branch_t *) const = 0;
  virtual void operator()(const PSEUDO_CLASS_SELECTOR_from_COLON_IDENT_TOKEN_t *) const = 0;
  virtual void operator()(const PSEUDO_CLASS_SELECTOR_from_COLON_FUNCTION_TOKEN_ANY_VALUE_RIGHT_PAREN_t *) const = 0;
  virtual void operator()(const AT_KEYWORD_TOKEN_branch_t *) const = 0;
  virtual void operator()(const AT_KEYWORD_TOKEN_from_AT_IDENT_TOKEN_t *) const = 0;
  virtual void operator()(const PERCENTAGE_TOKEN_branch_t *) const = 0;
  virtual void operator()(const PERCENTAGE_TOKEN_from_NUMBER_TOKEN_PERCENT_t *) const = 0;
  virtual void operator()(const ID_SELECTOR_branch_t *) const = 0;
  virtual void operator()(const ID_SELECTOR_from_HASH_TOKEN_t *) const = 0;
  virtual void operator()(const SUBCLASS_SELECTOR_branch_t *) const = 0;
  virtual void operator()(const SUBCLASS_SELECTOR_from_ID_SELECTOR_t *) const = 0;
  virtual void operator()(const SUBCLASS_SELECTOR_from_CLASS_SELECTOR_t *) const = 0;
  virtual void operator()(const SUBCLASS_SELECTOR_from_ATTRIBUTE_SELECTOR_t *) const = 0;
  virtual void operator()(const SUBCLASS_SELECTOR_from_PSEUDO_CLASS_SELECTOR_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_branch_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_SUBCLASS_SELECTOR_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_SUBCLASS_SELECTOR_t *) const = 0;
  virtual void operator()(const PSEUDO_ELEMENT_SELECTOR_branch_t *) const = 0;
  virtual void operator()(const PSEUDO_ELEMENT_SELECTOR_from_COLON_PSEUDO_CLASS_SELECTOR_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_LIST_branch_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_LIST_COMMA_COMPOUND_SELECTOR_t *) const = 0;
  virtual void operator()(const FUNCTION_TOKEN_branch_t *) const = 0;
  virtual void operator()(const FUNCTION_TOKEN_from_IDENT_TOKEN_LEFT_PAREN_t *) const = 0;
  virtual void operator()(const WHITESPACE_TOKEN_branch_t *) const = 0;
  virtual void operator()(const WHITESPACE_TOKEN_from_WHITESPACE_t *) const = 0;
  virtual void operator()(const WHITESPACE_TOKEN_from_WHITESPACE_TOKEN_WHITESPACE_t *) const = 0;
  virtual void operator()(const COMPLEX_SELECTOR_LIST_branch_t *) const = 0;
  virtual void operator()(const COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_t *) const = 0;
  virtual void operator()(const COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_COMMA_COMPLEX_SELECTOR_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_branch_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_from_TYPE_SELECTOR_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t *) const = 0;
  virtual void operator()(const COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t *) const = 0;
  virtual void operator()(const SIMPLE_SELECTOR_LIST_branch_t *) const = 0;
  virtual void operator()(const SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_t *) const = 0;
  virtual void operator()(const SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_LIST_COMMA_SIMPLE_SELECTOR_t *) const = 0;
  virtual void operator()(const RELATIVE_SELECTOR_LIST_branch_t *) const = 0;
  virtual void operator()(const RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_t *) const = 0;
  virtual void operator()(const RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_LIST_COMMA_RELATIVE_SELECTOR_t *) const = 0;
  virtual void operator()(const COMPLEX_SELECTOR_branch_t *) const = 0;
  virtual void operator()(const COMPLEX_SELECTOR_from_COMPOUND_SELECTOR_t *) const = 0;
  virtual void operator()(const COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMBINATOR_COMPOUND_SELECTOR_t *) const = 0;
  virtual void operator()(const COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMPOUND_SELECTOR_t *) const = 0;
  virtual void operator()(const RELATIVE_SELECTOR_branch_t *) const = 0;
  virtual void operator()(const RELATIVE_SELECTOR_from_COMPLEX_SELECTOR_t *) const = 0;
  virtual void operator()(const RELATIVE_SELECTOR_from_COMBINATOR_COMPLEX_SELECTOR_t *) const = 0;
  virtual void operator()(const SELECTOR_LIST_branch_t *) const = 0;
  virtual void operator()(const SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_t *) const = 0;
  virtual void operator()(const COMBINATOR_branch_t *) const = 0;
  virtual void operator()(const COMBINATOR_from_GREATER_THAN_t *) const = 0;
  virtual void operator()(const COMBINATOR_from_PLUS_t *) const = 0;
  virtual void operator()(const COMBINATOR_from_TILDE_t *) const = 0;
  virtual void operator()(const COMBINATOR_from_COLUMN_TOKEN_t *) const = 0;
  virtual void operator()(const ast_token_t *) const = 0;
};  // default_visitor_t


class ast_t;

/* base class for all ast nodes */
class ast_t {

public:

  using visitor_t = default_visitor_t;

  virtual ~ast_t() = default;

  virtual symbol_t::kind_t get_symbol_id() const = 0;

  std::string get_name() {
    return symbol_t::get_name(get_symbol_id());
  }

  /* famous out of the box visitor pattern functionality */
  virtual void accept(const visitor_t &visitor) const = 0;

  /* return all children */
  std::vector<std::shared_ptr<ast_t>> get_children() const {
    return children;
  }

protected:

  ast_t(std::vector<std::shared_ptr<ast_t>> children_): children(children_) {}

  std::vector<std::shared_ptr<ast_t>> children;

};  // ast_t

/* an ast node holding a single token */
class ast_token_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(token->get_kind());
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  std::shared_ptr<token_t> get_token() const {
    return token;
  }

  static std::shared_ptr<ast_token_t> make(std::shared_ptr<token_t> token) {
    auto ptr = new ast_token_t(token);
    std::shared_ptr<ast_token_t> result(ptr);
    return result;
  }

protected:

  std::shared_ptr<token_t> token;

  ast_token_t(std::shared_ptr<token_t> token_): ast_t({}), token(token_) {
    assert(children.size() == 0);
  }

};  // ast_token_t


/* base class for ATTR_MATCHER_branch */
class ATTR_MATCHER_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 40;

protected:

  ATTR_MATCHER_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // ATTR_MATCHER_branch_t

class ATTR_MATCHER_from_ASTERISK_EQUALS_t: public ATTR_MATCHER_branch_t {

public:

  static std::shared_ptr<ATTR_MATCHER_from_ASTERISK_EQUALS_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new ATTR_MATCHER_from_ASTERISK_EQUALS_t(children);
    std::shared_ptr<ATTR_MATCHER_from_ASTERISK_EQUALS_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 63;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  ATTR_MATCHER_from_ASTERISK_EQUALS_t(std::vector<std::shared_ptr<ast_t>> children): ATTR_MATCHER_branch_t(children) {}

};  // ATTR_MATCHER_from_ASTERISK_EQUALS_t

const std::vector<symbol_t::kind_t> ATTR_MATCHER_from_ASTERISK_EQUALS_t::pattern = { symbol_t::ASTERISK, symbol_t::EQUALS };


class ATTR_MATCHER_from_DOLLAR_EQUALS_t: public ATTR_MATCHER_branch_t {

public:

  static std::shared_ptr<ATTR_MATCHER_from_DOLLAR_EQUALS_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new ATTR_MATCHER_from_DOLLAR_EQUALS_t(children);
    std::shared_ptr<ATTR_MATCHER_from_DOLLAR_EQUALS_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 64;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  ATTR_MATCHER_from_DOLLAR_EQUALS_t(std::vector<std::shared_ptr<ast_t>> children): ATTR_MATCHER_branch_t(children) {}

};  // ATTR_MATCHER_from_DOLLAR_EQUALS_t

const std::vector<symbol_t::kind_t> ATTR_MATCHER_from_DOLLAR_EQUALS_t::pattern = { symbol_t::DOLLAR, symbol_t::EQUALS };


class ATTR_MATCHER_from_CARET_EQUALS_t: public ATTR_MATCHER_branch_t {

public:

  static std::shared_ptr<ATTR_MATCHER_from_CARET_EQUALS_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new ATTR_MATCHER_from_CARET_EQUALS_t(children);
    std::shared_ptr<ATTR_MATCHER_from_CARET_EQUALS_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 65;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  ATTR_MATCHER_from_CARET_EQUALS_t(std::vector<std::shared_ptr<ast_t>> children): ATTR_MATCHER_branch_t(children) {}

};  // ATTR_MATCHER_from_CARET_EQUALS_t

const std::vector<symbol_t::kind_t> ATTR_MATCHER_from_CARET_EQUALS_t::pattern = { symbol_t::CARET, symbol_t::EQUALS };


class ATTR_MATCHER_from_PIPE_EQUALS_t: public ATTR_MATCHER_branch_t {

public:

  static std::shared_ptr<ATTR_MATCHER_from_PIPE_EQUALS_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new ATTR_MATCHER_from_PIPE_EQUALS_t(children);
    std::shared_ptr<ATTR_MATCHER_from_PIPE_EQUALS_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 66;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  ATTR_MATCHER_from_PIPE_EQUALS_t(std::vector<std::shared_ptr<ast_t>> children): ATTR_MATCHER_branch_t(children) {}

};  // ATTR_MATCHER_from_PIPE_EQUALS_t

const std::vector<symbol_t::kind_t> ATTR_MATCHER_from_PIPE_EQUALS_t::pattern = { symbol_t::PIPE, symbol_t::EQUALS };


class ATTR_MATCHER_from_TILDE_EQUALS_t: public ATTR_MATCHER_branch_t {

public:

  static std::shared_ptr<ATTR_MATCHER_from_TILDE_EQUALS_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new ATTR_MATCHER_from_TILDE_EQUALS_t(children);
    std::shared_ptr<ATTR_MATCHER_from_TILDE_EQUALS_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 67;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  ATTR_MATCHER_from_TILDE_EQUALS_t(std::vector<std::shared_ptr<ast_t>> children): ATTR_MATCHER_branch_t(children) {}

};  // ATTR_MATCHER_from_TILDE_EQUALS_t

const std::vector<symbol_t::kind_t> ATTR_MATCHER_from_TILDE_EQUALS_t::pattern = { symbol_t::TILDE, symbol_t::EQUALS };


class ATTR_MATCHER_from_EQUALS_t: public ATTR_MATCHER_branch_t {

public:

  static std::shared_ptr<ATTR_MATCHER_from_EQUALS_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new ATTR_MATCHER_from_EQUALS_t(children);
    std::shared_ptr<ATTR_MATCHER_from_EQUALS_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 68;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  ATTR_MATCHER_from_EQUALS_t(std::vector<std::shared_ptr<ast_t>> children): ATTR_MATCHER_branch_t(children) {}

};  // ATTR_MATCHER_from_EQUALS_t

const std::vector<symbol_t::kind_t> ATTR_MATCHER_from_EQUALS_t::pattern = { symbol_t::EQUALS };



/* base class for CLASS_SELECTOR_branch */
class CLASS_SELECTOR_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 41;

protected:

  CLASS_SELECTOR_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // CLASS_SELECTOR_branch_t

class CLASS_SELECTOR_from_PERIOD_IDENT_TOKEN_t: public CLASS_SELECTOR_branch_t {

public:

  static std::shared_ptr<CLASS_SELECTOR_from_PERIOD_IDENT_TOKEN_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new CLASS_SELECTOR_from_PERIOD_IDENT_TOKEN_t(children);
    std::shared_ptr<CLASS_SELECTOR_from_PERIOD_IDENT_TOKEN_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 57;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  CLASS_SELECTOR_from_PERIOD_IDENT_TOKEN_t(std::vector<std::shared_ptr<ast_t>> children): CLASS_SELECTOR_branch_t(children) {}

};  // CLASS_SELECTOR_from_PERIOD_IDENT_TOKEN_t

const std::vector<symbol_t::kind_t> CLASS_SELECTOR_from_PERIOD_IDENT_TOKEN_t::pattern = { symbol_t::PERIOD, symbol_t::IDENT_TOKEN };



/* base class for NS_PREFIX_branch */
class NS_PREFIX_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 42;

protected:

  NS_PREFIX_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // NS_PREFIX_branch_t

class NS_PREFIX_from_PIPE_t: public NS_PREFIX_branch_t {

public:

  static std::shared_ptr<NS_PREFIX_from_PIPE_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new NS_PREFIX_from_PIPE_t(children);
    std::shared_ptr<NS_PREFIX_from_PIPE_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 46;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  NS_PREFIX_from_PIPE_t(std::vector<std::shared_ptr<ast_t>> children): NS_PREFIX_branch_t(children) {}

};  // NS_PREFIX_from_PIPE_t

const std::vector<symbol_t::kind_t> NS_PREFIX_from_PIPE_t::pattern = { symbol_t::PIPE };


class NS_PREFIX_from_IDENT_TOKEN_ASTERISK_PIPE_t: public NS_PREFIX_branch_t {

public:

  static std::shared_ptr<NS_PREFIX_from_IDENT_TOKEN_ASTERISK_PIPE_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 3);
    auto ptr = new NS_PREFIX_from_IDENT_TOKEN_ASTERISK_PIPE_t(children);
    std::shared_ptr<NS_PREFIX_from_IDENT_TOKEN_ASTERISK_PIPE_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 47;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  NS_PREFIX_from_IDENT_TOKEN_ASTERISK_PIPE_t(std::vector<std::shared_ptr<ast_t>> children): NS_PREFIX_branch_t(children) {}

};  // NS_PREFIX_from_IDENT_TOKEN_ASTERISK_PIPE_t

const std::vector<symbol_t::kind_t> NS_PREFIX_from_IDENT_TOKEN_ASTERISK_PIPE_t::pattern = { symbol_t::IDENT_TOKEN, symbol_t::ASTERISK, symbol_t::PIPE };


class NS_PREFIX_from_IDENT_TOKEN_PIPE_t: public NS_PREFIX_branch_t {

public:

  static std::shared_ptr<NS_PREFIX_from_IDENT_TOKEN_PIPE_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new NS_PREFIX_from_IDENT_TOKEN_PIPE_t(children);
    std::shared_ptr<NS_PREFIX_from_IDENT_TOKEN_PIPE_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 48;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  NS_PREFIX_from_IDENT_TOKEN_PIPE_t(std::vector<std::shared_ptr<ast_t>> children): NS_PREFIX_branch_t(children) {}

};  // NS_PREFIX_from_IDENT_TOKEN_PIPE_t

const std::vector<symbol_t::kind_t> NS_PREFIX_from_IDENT_TOKEN_PIPE_t::pattern = { symbol_t::IDENT_TOKEN, symbol_t::PIPE };


class NS_PREFIX_from_ASTERISK_PIPE_t: public NS_PREFIX_branch_t {

public:

  static std::shared_ptr<NS_PREFIX_from_ASTERISK_PIPE_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new NS_PREFIX_from_ASTERISK_PIPE_t(children);
    std::shared_ptr<NS_PREFIX_from_ASTERISK_PIPE_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 49;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  NS_PREFIX_from_ASTERISK_PIPE_t(std::vector<std::shared_ptr<ast_t>> children): NS_PREFIX_branch_t(children) {}

};  // NS_PREFIX_from_ASTERISK_PIPE_t

const std::vector<symbol_t::kind_t> NS_PREFIX_from_ASTERISK_PIPE_t::pattern = { symbol_t::ASTERISK, symbol_t::PIPE };



/* base class for TYPE_SELECTOR_branch */
class TYPE_SELECTOR_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 43;

protected:

  TYPE_SELECTOR_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // TYPE_SELECTOR_branch_t

class TYPE_SELECTOR_from_WQ_NAME_t: public TYPE_SELECTOR_branch_t {

public:

  static std::shared_ptr<TYPE_SELECTOR_from_WQ_NAME_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new TYPE_SELECTOR_from_WQ_NAME_t(children);
    std::shared_ptr<TYPE_SELECTOR_from_WQ_NAME_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 43;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  TYPE_SELECTOR_from_WQ_NAME_t(std::vector<std::shared_ptr<ast_t>> children): TYPE_SELECTOR_branch_t(children) {}

};  // TYPE_SELECTOR_from_WQ_NAME_t

const std::vector<symbol_t::kind_t> TYPE_SELECTOR_from_WQ_NAME_t::pattern = { symbol_t::WQ_NAME };


class TYPE_SELECTOR_from_ASTERISK_t: public TYPE_SELECTOR_branch_t {

public:

  static std::shared_ptr<TYPE_SELECTOR_from_ASTERISK_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new TYPE_SELECTOR_from_ASTERISK_t(children);
    std::shared_ptr<TYPE_SELECTOR_from_ASTERISK_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 44;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  TYPE_SELECTOR_from_ASTERISK_t(std::vector<std::shared_ptr<ast_t>> children): TYPE_SELECTOR_branch_t(children) {}

};  // TYPE_SELECTOR_from_ASTERISK_t

const std::vector<symbol_t::kind_t> TYPE_SELECTOR_from_ASTERISK_t::pattern = { symbol_t::ASTERISK };


class TYPE_SELECTOR_from_NS_PREFIX_ASTERISK_t: public TYPE_SELECTOR_branch_t {

public:

  static std::shared_ptr<TYPE_SELECTOR_from_NS_PREFIX_ASTERISK_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new TYPE_SELECTOR_from_NS_PREFIX_ASTERISK_t(children);
    std::shared_ptr<TYPE_SELECTOR_from_NS_PREFIX_ASTERISK_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 45;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  TYPE_SELECTOR_from_NS_PREFIX_ASTERISK_t(std::vector<std::shared_ptr<ast_t>> children): TYPE_SELECTOR_branch_t(children) {}

};  // TYPE_SELECTOR_from_NS_PREFIX_ASTERISK_t

const std::vector<symbol_t::kind_t> TYPE_SELECTOR_from_NS_PREFIX_ASTERISK_t::pattern = { symbol_t::NS_PREFIX, symbol_t::ASTERISK };



/* base class for COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_branch */
class COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 44;

protected:

  COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_branch_t

class COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_t: public COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_branch_t {

public:

  static std::shared_ptr<COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_t(children);
    std::shared_ptr<COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 26;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_branch_t(children) {}

};  // COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_t

const std::vector<symbol_t::kind_t> COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_t::pattern = { symbol_t::PSEUDO_ELEMENT_SELECTOR };


class COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t: public COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_branch_t {

public:

  static std::shared_ptr<COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t(children);
    std::shared_ptr<COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 27;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t(std::vector<std::shared_ptr<ast_t>> children): COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_branch_t(children) {}

};  // COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t

const std::vector<symbol_t::kind_t> COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t::pattern = { symbol_t::PSEUDO_ELEMENT_SELECTOR, symbol_t::COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST };


class COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t: public COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_branch_t {

public:

  static std::shared_ptr<COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t(children);
    std::shared_ptr<COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 28;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t(std::vector<std::shared_ptr<ast_t>> children): COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_branch_t(children) {}

};  // COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t

const std::vector<symbol_t::kind_t> COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t::pattern = { symbol_t::PSEUDO_ELEMENT_SELECTOR, symbol_t::COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST };


class COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t: public COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_branch_t {

public:

  static std::shared_ptr<COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 3);
    auto ptr = new COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t(children);
    std::shared_ptr<COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 29;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t(std::vector<std::shared_ptr<ast_t>> children): COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_branch_t(children) {}

};  // COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t

const std::vector<symbol_t::kind_t> COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t::pattern = { symbol_t::PSEUDO_ELEMENT_SELECTOR, symbol_t::COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST, symbol_t::COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST };



/* base class for ATTR_MODIFIER_branch */
class ATTR_MODIFIER_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 45;

protected:

  ATTR_MODIFIER_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // ATTR_MODIFIER_branch_t

class ATTR_MODIFIER_from_LETTER_I_t: public ATTR_MODIFIER_branch_t {

public:

  static std::shared_ptr<ATTR_MODIFIER_from_LETTER_I_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new ATTR_MODIFIER_from_LETTER_I_t(children);
    std::shared_ptr<ATTR_MODIFIER_from_LETTER_I_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 69;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  ATTR_MODIFIER_from_LETTER_I_t(std::vector<std::shared_ptr<ast_t>> children): ATTR_MODIFIER_branch_t(children) {}

};  // ATTR_MODIFIER_from_LETTER_I_t

const std::vector<symbol_t::kind_t> ATTR_MODIFIER_from_LETTER_I_t::pattern = { symbol_t::LETTER_I };



/* base class for COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_branch */
class COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 46;

protected:

  COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_branch_t

class COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_PSEUDO_CLASS_SELECTOR_t: public COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_branch_t {

public:

  static std::shared_ptr<COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_PSEUDO_CLASS_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_PSEUDO_CLASS_SELECTOR_t(children);
    std::shared_ptr<COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_PSEUDO_CLASS_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 24;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_PSEUDO_CLASS_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_branch_t(children) {}

};  // COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_PSEUDO_CLASS_SELECTOR_t

const std::vector<symbol_t::kind_t> COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_PSEUDO_CLASS_SELECTOR_t::pattern = { symbol_t::PSEUDO_CLASS_SELECTOR };


class COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_PSEUDO_CLASS_SELECTOR_t: public COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_branch_t {

public:

  static std::shared_ptr<COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_PSEUDO_CLASS_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_PSEUDO_CLASS_SELECTOR_t(children);
    std::shared_ptr<COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_PSEUDO_CLASS_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 25;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_PSEUDO_CLASS_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_branch_t(children) {}

};  // COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_PSEUDO_CLASS_SELECTOR_t

const std::vector<symbol_t::kind_t> COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_PSEUDO_CLASS_SELECTOR_t::pattern = { symbol_t::COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST, symbol_t::PSEUDO_CLASS_SELECTOR };



/* base class for ATTRIBUTE_SELECTOR_branch */
class ATTRIBUTE_SELECTOR_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 47;

protected:

  ATTRIBUTE_SELECTOR_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // ATTRIBUTE_SELECTOR_branch_t

class ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_RIGHT_BRACKET_t: public ATTRIBUTE_SELECTOR_branch_t {

public:

  static std::shared_ptr<ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_RIGHT_BRACKET_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 3);
    auto ptr = new ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_RIGHT_BRACKET_t(children);
    std::shared_ptr<ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_RIGHT_BRACKET_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 58;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_RIGHT_BRACKET_t(std::vector<std::shared_ptr<ast_t>> children): ATTRIBUTE_SELECTOR_branch_t(children) {}

};  // ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_RIGHT_BRACKET_t

const std::vector<symbol_t::kind_t> ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_RIGHT_BRACKET_t::pattern = { symbol_t::LEFT_BRACKET, symbol_t::WQ_NAME, symbol_t::RIGHT_BRACKET };


class ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t: public ATTRIBUTE_SELECTOR_branch_t {

public:

  static std::shared_ptr<ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 6);
    auto ptr = new ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t(children);
    std::shared_ptr<ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 59;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t(std::vector<std::shared_ptr<ast_t>> children): ATTRIBUTE_SELECTOR_branch_t(children) {}

};  // ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t

const std::vector<symbol_t::kind_t> ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t::pattern = { symbol_t::LEFT_BRACKET, symbol_t::WQ_NAME, symbol_t::ATTR_MATCHER, symbol_t::IDENT_TOKEN, symbol_t::ATTR_MODIFIER, symbol_t::RIGHT_BRACKET };


class ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t: public ATTRIBUTE_SELECTOR_branch_t {

public:

  static std::shared_ptr<ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 6);
    auto ptr = new ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t(children);
    std::shared_ptr<ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 60;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t(std::vector<std::shared_ptr<ast_t>> children): ATTRIBUTE_SELECTOR_branch_t(children) {}

};  // ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t

const std::vector<symbol_t::kind_t> ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t::pattern = { symbol_t::LEFT_BRACKET, symbol_t::WQ_NAME, symbol_t::ATTR_MATCHER, symbol_t::STRING_TOKEN, symbol_t::ATTR_MODIFIER, symbol_t::RIGHT_BRACKET };


class ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_RIGHT_BRACKET_t: public ATTRIBUTE_SELECTOR_branch_t {

public:

  static std::shared_ptr<ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_RIGHT_BRACKET_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 5);
    auto ptr = new ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_RIGHT_BRACKET_t(children);
    std::shared_ptr<ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_RIGHT_BRACKET_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 61;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_RIGHT_BRACKET_t(std::vector<std::shared_ptr<ast_t>> children): ATTRIBUTE_SELECTOR_branch_t(children) {}

};  // ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_RIGHT_BRACKET_t

const std::vector<symbol_t::kind_t> ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_RIGHT_BRACKET_t::pattern = { symbol_t::LEFT_BRACKET, symbol_t::WQ_NAME, symbol_t::ATTR_MATCHER, symbol_t::IDENT_TOKEN, symbol_t::RIGHT_BRACKET };


class ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_RIGHT_BRACKET_t: public ATTRIBUTE_SELECTOR_branch_t {

public:

  static std::shared_ptr<ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_RIGHT_BRACKET_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 5);
    auto ptr = new ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_RIGHT_BRACKET_t(children);
    std::shared_ptr<ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_RIGHT_BRACKET_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 62;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_RIGHT_BRACKET_t(std::vector<std::shared_ptr<ast_t>> children): ATTRIBUTE_SELECTOR_branch_t(children) {}

};  // ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_RIGHT_BRACKET_t

const std::vector<symbol_t::kind_t> ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_RIGHT_BRACKET_t::pattern = { symbol_t::LEFT_BRACKET, symbol_t::WQ_NAME, symbol_t::ATTR_MATCHER, symbol_t::STRING_TOKEN, symbol_t::RIGHT_BRACKET };



/* base class for DIMENSION_TOKEN_branch */
class DIMENSION_TOKEN_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 48;

protected:

  DIMENSION_TOKEN_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // DIMENSION_TOKEN_branch_t

class DIMENSION_TOKEN_from_NUMBER_TOKEN_IDENT_TOKEN_t: public DIMENSION_TOKEN_branch_t {

public:

  static std::shared_ptr<DIMENSION_TOKEN_from_NUMBER_TOKEN_IDENT_TOKEN_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new DIMENSION_TOKEN_from_NUMBER_TOKEN_IDENT_TOKEN_t(children);
    std::shared_ptr<DIMENSION_TOKEN_from_NUMBER_TOKEN_IDENT_TOKEN_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 7;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  DIMENSION_TOKEN_from_NUMBER_TOKEN_IDENT_TOKEN_t(std::vector<std::shared_ptr<ast_t>> children): DIMENSION_TOKEN_branch_t(children) {}

};  // DIMENSION_TOKEN_from_NUMBER_TOKEN_IDENT_TOKEN_t

const std::vector<symbol_t::kind_t> DIMENSION_TOKEN_from_NUMBER_TOKEN_IDENT_TOKEN_t::pattern = { symbol_t::NUMBER_TOKEN, symbol_t::IDENT_TOKEN };



/* base class for WQ_NAME_branch */
class WQ_NAME_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 49;

protected:

  WQ_NAME_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // WQ_NAME_branch_t

class WQ_NAME_from_NS_PREFIX_IDENT_TOKEN_t: public WQ_NAME_branch_t {

public:

  static std::shared_ptr<WQ_NAME_from_NS_PREFIX_IDENT_TOKEN_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new WQ_NAME_from_NS_PREFIX_IDENT_TOKEN_t(children);
    std::shared_ptr<WQ_NAME_from_NS_PREFIX_IDENT_TOKEN_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 50;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  WQ_NAME_from_NS_PREFIX_IDENT_TOKEN_t(std::vector<std::shared_ptr<ast_t>> children): WQ_NAME_branch_t(children) {}

};  // WQ_NAME_from_NS_PREFIX_IDENT_TOKEN_t

const std::vector<symbol_t::kind_t> WQ_NAME_from_NS_PREFIX_IDENT_TOKEN_t::pattern = { symbol_t::NS_PREFIX, symbol_t::IDENT_TOKEN };


class WQ_NAME_from_IDENT_TOKEN_t: public WQ_NAME_branch_t {

public:

  static std::shared_ptr<WQ_NAME_from_IDENT_TOKEN_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new WQ_NAME_from_IDENT_TOKEN_t(children);
    std::shared_ptr<WQ_NAME_from_IDENT_TOKEN_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 51;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  WQ_NAME_from_IDENT_TOKEN_t(std::vector<std::shared_ptr<ast_t>> children): WQ_NAME_branch_t(children) {}

};  // WQ_NAME_from_IDENT_TOKEN_t

const std::vector<symbol_t::kind_t> WQ_NAME_from_IDENT_TOKEN_t::pattern = { symbol_t::IDENT_TOKEN };



/* base class for SIMPLE_SELECTOR_branch */
class SIMPLE_SELECTOR_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 50;

protected:

  SIMPLE_SELECTOR_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // SIMPLE_SELECTOR_branch_t

class SIMPLE_SELECTOR_from_TYPE_SELECTOR_t: public SIMPLE_SELECTOR_branch_t {

public:

  static std::shared_ptr<SIMPLE_SELECTOR_from_TYPE_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new SIMPLE_SELECTOR_from_TYPE_SELECTOR_t(children);
    std::shared_ptr<SIMPLE_SELECTOR_from_TYPE_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 37;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  SIMPLE_SELECTOR_from_TYPE_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): SIMPLE_SELECTOR_branch_t(children) {}

};  // SIMPLE_SELECTOR_from_TYPE_SELECTOR_t

const std::vector<symbol_t::kind_t> SIMPLE_SELECTOR_from_TYPE_SELECTOR_t::pattern = { symbol_t::TYPE_SELECTOR };


class SIMPLE_SELECTOR_from_SUBCLASS_SELECTOR_t: public SIMPLE_SELECTOR_branch_t {

public:

  static std::shared_ptr<SIMPLE_SELECTOR_from_SUBCLASS_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new SIMPLE_SELECTOR_from_SUBCLASS_SELECTOR_t(children);
    std::shared_ptr<SIMPLE_SELECTOR_from_SUBCLASS_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 38;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  SIMPLE_SELECTOR_from_SUBCLASS_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): SIMPLE_SELECTOR_branch_t(children) {}

};  // SIMPLE_SELECTOR_from_SUBCLASS_SELECTOR_t

const std::vector<symbol_t::kind_t> SIMPLE_SELECTOR_from_SUBCLASS_SELECTOR_t::pattern = { symbol_t::SUBCLASS_SELECTOR };



/* base class for PSEUDO_CLASS_SELECTOR_branch */
class PSEUDO_CLASS_SELECTOR_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 51;

protected:

  PSEUDO_CLASS_SELECTOR_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // PSEUDO_CLASS_SELECTOR_branch_t

class PSEUDO_CLASS_SELECTOR_from_COLON_IDENT_TOKEN_t: public PSEUDO_CLASS_SELECTOR_branch_t {

public:

  static std::shared_ptr<PSEUDO_CLASS_SELECTOR_from_COLON_IDENT_TOKEN_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new PSEUDO_CLASS_SELECTOR_from_COLON_IDENT_TOKEN_t(children);
    std::shared_ptr<PSEUDO_CLASS_SELECTOR_from_COLON_IDENT_TOKEN_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 70;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  PSEUDO_CLASS_SELECTOR_from_COLON_IDENT_TOKEN_t(std::vector<std::shared_ptr<ast_t>> children): PSEUDO_CLASS_SELECTOR_branch_t(children) {}

};  // PSEUDO_CLASS_SELECTOR_from_COLON_IDENT_TOKEN_t

const std::vector<symbol_t::kind_t> PSEUDO_CLASS_SELECTOR_from_COLON_IDENT_TOKEN_t::pattern = { symbol_t::COLON, symbol_t::IDENT_TOKEN };


class PSEUDO_CLASS_SELECTOR_from_COLON_FUNCTION_TOKEN_ANY_VALUE_RIGHT_PAREN_t: public PSEUDO_CLASS_SELECTOR_branch_t {

public:

  static std::shared_ptr<PSEUDO_CLASS_SELECTOR_from_COLON_FUNCTION_TOKEN_ANY_VALUE_RIGHT_PAREN_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 4);
    auto ptr = new PSEUDO_CLASS_SELECTOR_from_COLON_FUNCTION_TOKEN_ANY_VALUE_RIGHT_PAREN_t(children);
    std::shared_ptr<PSEUDO_CLASS_SELECTOR_from_COLON_FUNCTION_TOKEN_ANY_VALUE_RIGHT_PAREN_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 71;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  PSEUDO_CLASS_SELECTOR_from_COLON_FUNCTION_TOKEN_ANY_VALUE_RIGHT_PAREN_t(std::vector<std::shared_ptr<ast_t>> children): PSEUDO_CLASS_SELECTOR_branch_t(children) {}

};  // PSEUDO_CLASS_SELECTOR_from_COLON_FUNCTION_TOKEN_ANY_VALUE_RIGHT_PAREN_t

const std::vector<symbol_t::kind_t> PSEUDO_CLASS_SELECTOR_from_COLON_FUNCTION_TOKEN_ANY_VALUE_RIGHT_PAREN_t::pattern = { symbol_t::COLON, symbol_t::FUNCTION_TOKEN, symbol_t::ANY_VALUE, symbol_t::RIGHT_PAREN };



/* base class for AT_KEYWORD_TOKEN_branch */
class AT_KEYWORD_TOKEN_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 52;

protected:

  AT_KEYWORD_TOKEN_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // AT_KEYWORD_TOKEN_branch_t

class AT_KEYWORD_TOKEN_from_AT_IDENT_TOKEN_t: public AT_KEYWORD_TOKEN_branch_t {

public:

  static std::shared_ptr<AT_KEYWORD_TOKEN_from_AT_IDENT_TOKEN_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new AT_KEYWORD_TOKEN_from_AT_IDENT_TOKEN_t(children);
    std::shared_ptr<AT_KEYWORD_TOKEN_from_AT_IDENT_TOKEN_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 6;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  AT_KEYWORD_TOKEN_from_AT_IDENT_TOKEN_t(std::vector<std::shared_ptr<ast_t>> children): AT_KEYWORD_TOKEN_branch_t(children) {}

};  // AT_KEYWORD_TOKEN_from_AT_IDENT_TOKEN_t

const std::vector<symbol_t::kind_t> AT_KEYWORD_TOKEN_from_AT_IDENT_TOKEN_t::pattern = { symbol_t::AT, symbol_t::IDENT_TOKEN };



/* base class for PERCENTAGE_TOKEN_branch */
class PERCENTAGE_TOKEN_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 53;

protected:

  PERCENTAGE_TOKEN_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // PERCENTAGE_TOKEN_branch_t

class PERCENTAGE_TOKEN_from_NUMBER_TOKEN_PERCENT_t: public PERCENTAGE_TOKEN_branch_t {

public:

  static std::shared_ptr<PERCENTAGE_TOKEN_from_NUMBER_TOKEN_PERCENT_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new PERCENTAGE_TOKEN_from_NUMBER_TOKEN_PERCENT_t(children);
    std::shared_ptr<PERCENTAGE_TOKEN_from_NUMBER_TOKEN_PERCENT_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 8;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  PERCENTAGE_TOKEN_from_NUMBER_TOKEN_PERCENT_t(std::vector<std::shared_ptr<ast_t>> children): PERCENTAGE_TOKEN_branch_t(children) {}

};  // PERCENTAGE_TOKEN_from_NUMBER_TOKEN_PERCENT_t

const std::vector<symbol_t::kind_t> PERCENTAGE_TOKEN_from_NUMBER_TOKEN_PERCENT_t::pattern = { symbol_t::NUMBER_TOKEN, symbol_t::PERCENT };



/* base class for ID_SELECTOR_branch */
class ID_SELECTOR_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 54;

protected:

  ID_SELECTOR_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // ID_SELECTOR_branch_t

class ID_SELECTOR_from_HASH_TOKEN_t: public ID_SELECTOR_branch_t {

public:

  static std::shared_ptr<ID_SELECTOR_from_HASH_TOKEN_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new ID_SELECTOR_from_HASH_TOKEN_t(children);
    std::shared_ptr<ID_SELECTOR_from_HASH_TOKEN_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 56;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  ID_SELECTOR_from_HASH_TOKEN_t(std::vector<std::shared_ptr<ast_t>> children): ID_SELECTOR_branch_t(children) {}

};  // ID_SELECTOR_from_HASH_TOKEN_t

const std::vector<symbol_t::kind_t> ID_SELECTOR_from_HASH_TOKEN_t::pattern = { symbol_t::HASH_TOKEN };



/* base class for SUBCLASS_SELECTOR_branch */
class SUBCLASS_SELECTOR_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 55;

protected:

  SUBCLASS_SELECTOR_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // SUBCLASS_SELECTOR_branch_t

class SUBCLASS_SELECTOR_from_ID_SELECTOR_t: public SUBCLASS_SELECTOR_branch_t {

public:

  static std::shared_ptr<SUBCLASS_SELECTOR_from_ID_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new SUBCLASS_SELECTOR_from_ID_SELECTOR_t(children);
    std::shared_ptr<SUBCLASS_SELECTOR_from_ID_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 52;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  SUBCLASS_SELECTOR_from_ID_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): SUBCLASS_SELECTOR_branch_t(children) {}

};  // SUBCLASS_SELECTOR_from_ID_SELECTOR_t

const std::vector<symbol_t::kind_t> SUBCLASS_SELECTOR_from_ID_SELECTOR_t::pattern = { symbol_t::ID_SELECTOR };


class SUBCLASS_SELECTOR_from_CLASS_SELECTOR_t: public SUBCLASS_SELECTOR_branch_t {

public:

  static std::shared_ptr<SUBCLASS_SELECTOR_from_CLASS_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new SUBCLASS_SELECTOR_from_CLASS_SELECTOR_t(children);
    std::shared_ptr<SUBCLASS_SELECTOR_from_CLASS_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 53;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  SUBCLASS_SELECTOR_from_CLASS_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): SUBCLASS_SELECTOR_branch_t(children) {}

};  // SUBCLASS_SELECTOR_from_CLASS_SELECTOR_t

const std::vector<symbol_t::kind_t> SUBCLASS_SELECTOR_from_CLASS_SELECTOR_t::pattern = { symbol_t::CLASS_SELECTOR };


class SUBCLASS_SELECTOR_from_ATTRIBUTE_SELECTOR_t: public SUBCLASS_SELECTOR_branch_t {

public:

  static std::shared_ptr<SUBCLASS_SELECTOR_from_ATTRIBUTE_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new SUBCLASS_SELECTOR_from_ATTRIBUTE_SELECTOR_t(children);
    std::shared_ptr<SUBCLASS_SELECTOR_from_ATTRIBUTE_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 54;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  SUBCLASS_SELECTOR_from_ATTRIBUTE_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): SUBCLASS_SELECTOR_branch_t(children) {}

};  // SUBCLASS_SELECTOR_from_ATTRIBUTE_SELECTOR_t

const std::vector<symbol_t::kind_t> SUBCLASS_SELECTOR_from_ATTRIBUTE_SELECTOR_t::pattern = { symbol_t::ATTRIBUTE_SELECTOR };


class SUBCLASS_SELECTOR_from_PSEUDO_CLASS_SELECTOR_t: public SUBCLASS_SELECTOR_branch_t {

public:

  static std::shared_ptr<SUBCLASS_SELECTOR_from_PSEUDO_CLASS_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new SUBCLASS_SELECTOR_from_PSEUDO_CLASS_SELECTOR_t(children);
    std::shared_ptr<SUBCLASS_SELECTOR_from_PSEUDO_CLASS_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 55;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  SUBCLASS_SELECTOR_from_PSEUDO_CLASS_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): SUBCLASS_SELECTOR_branch_t(children) {}

};  // SUBCLASS_SELECTOR_from_PSEUDO_CLASS_SELECTOR_t

const std::vector<symbol_t::kind_t> SUBCLASS_SELECTOR_from_PSEUDO_CLASS_SELECTOR_t::pattern = { symbol_t::PSEUDO_CLASS_SELECTOR };



/* base class for COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_branch */
class COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 56;

protected:

  COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_branch_t

class COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_SUBCLASS_SELECTOR_t: public COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_branch_t {

public:

  static std::shared_ptr<COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_SUBCLASS_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_SUBCLASS_SELECTOR_t(children);
    std::shared_ptr<COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_SUBCLASS_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 22;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_SUBCLASS_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_branch_t(children) {}

};  // COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_SUBCLASS_SELECTOR_t

const std::vector<symbol_t::kind_t> COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_SUBCLASS_SELECTOR_t::pattern = { symbol_t::SUBCLASS_SELECTOR };


class COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_SUBCLASS_SELECTOR_t: public COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_branch_t {

public:

  static std::shared_ptr<COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_SUBCLASS_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_SUBCLASS_SELECTOR_t(children);
    std::shared_ptr<COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_SUBCLASS_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 23;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_SUBCLASS_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_branch_t(children) {}

};  // COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_SUBCLASS_SELECTOR_t

const std::vector<symbol_t::kind_t> COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_SUBCLASS_SELECTOR_t::pattern = { symbol_t::COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST, symbol_t::SUBCLASS_SELECTOR };



/* base class for PSEUDO_ELEMENT_SELECTOR_branch */
class PSEUDO_ELEMENT_SELECTOR_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 57;

protected:

  PSEUDO_ELEMENT_SELECTOR_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // PSEUDO_ELEMENT_SELECTOR_branch_t

class PSEUDO_ELEMENT_SELECTOR_from_COLON_PSEUDO_CLASS_SELECTOR_t: public PSEUDO_ELEMENT_SELECTOR_branch_t {

public:

  static std::shared_ptr<PSEUDO_ELEMENT_SELECTOR_from_COLON_PSEUDO_CLASS_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new PSEUDO_ELEMENT_SELECTOR_from_COLON_PSEUDO_CLASS_SELECTOR_t(children);
    std::shared_ptr<PSEUDO_ELEMENT_SELECTOR_from_COLON_PSEUDO_CLASS_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 72;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  PSEUDO_ELEMENT_SELECTOR_from_COLON_PSEUDO_CLASS_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): PSEUDO_ELEMENT_SELECTOR_branch_t(children) {}

};  // PSEUDO_ELEMENT_SELECTOR_from_COLON_PSEUDO_CLASS_SELECTOR_t

const std::vector<symbol_t::kind_t> PSEUDO_ELEMENT_SELECTOR_from_COLON_PSEUDO_CLASS_SELECTOR_t::pattern = { symbol_t::COLON, symbol_t::PSEUDO_CLASS_SELECTOR };



/* base class for COMPOUND_SELECTOR_LIST_branch */
class COMPOUND_SELECTOR_LIST_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 58;

protected:

  COMPOUND_SELECTOR_LIST_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // COMPOUND_SELECTOR_LIST_branch_t

class COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_t: public COMPOUND_SELECTOR_LIST_branch_t {

public:

  static std::shared_ptr<COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_t(children);
    std::shared_ptr<COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 11;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): COMPOUND_SELECTOR_LIST_branch_t(children) {}

};  // COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_t

const std::vector<symbol_t::kind_t> COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_t::pattern = { symbol_t::COMPOUND_SELECTOR };


class COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_LIST_COMMA_COMPOUND_SELECTOR_t: public COMPOUND_SELECTOR_LIST_branch_t {

public:

  static std::shared_ptr<COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_LIST_COMMA_COMPOUND_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 3);
    auto ptr = new COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_LIST_COMMA_COMPOUND_SELECTOR_t(children);
    std::shared_ptr<COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_LIST_COMMA_COMPOUND_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 12;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_LIST_COMMA_COMPOUND_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): COMPOUND_SELECTOR_LIST_branch_t(children) {}

};  // COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_LIST_COMMA_COMPOUND_SELECTOR_t

const std::vector<symbol_t::kind_t> COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_LIST_COMMA_COMPOUND_SELECTOR_t::pattern = { symbol_t::COMPOUND_SELECTOR_LIST, symbol_t::COMMA, symbol_t::COMPOUND_SELECTOR };



/* base class for FUNCTION_TOKEN_branch */
class FUNCTION_TOKEN_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 59;

protected:

  FUNCTION_TOKEN_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // FUNCTION_TOKEN_branch_t

class FUNCTION_TOKEN_from_IDENT_TOKEN_LEFT_PAREN_t: public FUNCTION_TOKEN_branch_t {

public:

  static std::shared_ptr<FUNCTION_TOKEN_from_IDENT_TOKEN_LEFT_PAREN_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new FUNCTION_TOKEN_from_IDENT_TOKEN_LEFT_PAREN_t(children);
    std::shared_ptr<FUNCTION_TOKEN_from_IDENT_TOKEN_LEFT_PAREN_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 5;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  FUNCTION_TOKEN_from_IDENT_TOKEN_LEFT_PAREN_t(std::vector<std::shared_ptr<ast_t>> children): FUNCTION_TOKEN_branch_t(children) {}

};  // FUNCTION_TOKEN_from_IDENT_TOKEN_LEFT_PAREN_t

const std::vector<symbol_t::kind_t> FUNCTION_TOKEN_from_IDENT_TOKEN_LEFT_PAREN_t::pattern = { symbol_t::IDENT_TOKEN, symbol_t::LEFT_PAREN };



/* base class for WHITESPACE_TOKEN_branch */
class WHITESPACE_TOKEN_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 60;

protected:

  WHITESPACE_TOKEN_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // WHITESPACE_TOKEN_branch_t

class WHITESPACE_TOKEN_from_WHITESPACE_t: public WHITESPACE_TOKEN_branch_t {

public:

  static std::shared_ptr<WHITESPACE_TOKEN_from_WHITESPACE_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new WHITESPACE_TOKEN_from_WHITESPACE_t(children);
    std::shared_ptr<WHITESPACE_TOKEN_from_WHITESPACE_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 3;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  WHITESPACE_TOKEN_from_WHITESPACE_t(std::vector<std::shared_ptr<ast_t>> children): WHITESPACE_TOKEN_branch_t(children) {}

};  // WHITESPACE_TOKEN_from_WHITESPACE_t

const std::vector<symbol_t::kind_t> WHITESPACE_TOKEN_from_WHITESPACE_t::pattern = { symbol_t::WHITESPACE };


class WHITESPACE_TOKEN_from_WHITESPACE_TOKEN_WHITESPACE_t: public WHITESPACE_TOKEN_branch_t {

public:

  static std::shared_ptr<WHITESPACE_TOKEN_from_WHITESPACE_TOKEN_WHITESPACE_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new WHITESPACE_TOKEN_from_WHITESPACE_TOKEN_WHITESPACE_t(children);
    std::shared_ptr<WHITESPACE_TOKEN_from_WHITESPACE_TOKEN_WHITESPACE_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 4;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  WHITESPACE_TOKEN_from_WHITESPACE_TOKEN_WHITESPACE_t(std::vector<std::shared_ptr<ast_t>> children): WHITESPACE_TOKEN_branch_t(children) {}

};  // WHITESPACE_TOKEN_from_WHITESPACE_TOKEN_WHITESPACE_t

const std::vector<symbol_t::kind_t> WHITESPACE_TOKEN_from_WHITESPACE_TOKEN_WHITESPACE_t::pattern = { symbol_t::WHITESPACE_TOKEN, symbol_t::WHITESPACE };



/* base class for COMPLEX_SELECTOR_LIST_branch */
class COMPLEX_SELECTOR_LIST_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 61;

protected:

  COMPLEX_SELECTOR_LIST_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // COMPLEX_SELECTOR_LIST_branch_t

class COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_t: public COMPLEX_SELECTOR_LIST_branch_t {

public:

  static std::shared_ptr<COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_t(children);
    std::shared_ptr<COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 9;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): COMPLEX_SELECTOR_LIST_branch_t(children) {}

};  // COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_t

const std::vector<symbol_t::kind_t> COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_t::pattern = { symbol_t::COMPLEX_SELECTOR };


class COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_COMMA_COMPLEX_SELECTOR_t: public COMPLEX_SELECTOR_LIST_branch_t {

public:

  static std::shared_ptr<COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_COMMA_COMPLEX_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 3);
    auto ptr = new COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_COMMA_COMPLEX_SELECTOR_t(children);
    std::shared_ptr<COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_COMMA_COMPLEX_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 10;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_COMMA_COMPLEX_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): COMPLEX_SELECTOR_LIST_branch_t(children) {}

};  // COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_COMMA_COMPLEX_SELECTOR_t

const std::vector<symbol_t::kind_t> COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_COMMA_COMPLEX_SELECTOR_t::pattern = { symbol_t::COMPLEX_SELECTOR_LIST, symbol_t::COMMA, symbol_t::COMPLEX_SELECTOR };



/* base class for COMPOUND_SELECTOR_branch */
class COMPOUND_SELECTOR_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 62;

protected:

  COMPOUND_SELECTOR_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // COMPOUND_SELECTOR_branch_t

class COMPOUND_SELECTOR_from_TYPE_SELECTOR_t: public COMPOUND_SELECTOR_branch_t {

public:

  static std::shared_ptr<COMPOUND_SELECTOR_from_TYPE_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new COMPOUND_SELECTOR_from_TYPE_SELECTOR_t(children);
    std::shared_ptr<COMPOUND_SELECTOR_from_TYPE_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 30;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPOUND_SELECTOR_from_TYPE_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): COMPOUND_SELECTOR_branch_t(children) {}

};  // COMPOUND_SELECTOR_from_TYPE_SELECTOR_t

const std::vector<symbol_t::kind_t> COMPOUND_SELECTOR_from_TYPE_SELECTOR_t::pattern = { symbol_t::TYPE_SELECTOR };


class COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t: public COMPOUND_SELECTOR_branch_t {

public:

  static std::shared_ptr<COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t(children);
    std::shared_ptr<COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 31;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t(std::vector<std::shared_ptr<ast_t>> children): COMPOUND_SELECTOR_branch_t(children) {}

};  // COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t

const std::vector<symbol_t::kind_t> COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t::pattern = { symbol_t::TYPE_SELECTOR, symbol_t::COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST };


class COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t: public COMPOUND_SELECTOR_branch_t {

public:

  static std::shared_ptr<COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t(children);
    std::shared_ptr<COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 32;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t(std::vector<std::shared_ptr<ast_t>> children): COMPOUND_SELECTOR_branch_t(children) {}

};  // COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t

const std::vector<symbol_t::kind_t> COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t::pattern = { symbol_t::TYPE_SELECTOR, symbol_t::COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST };


class COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t: public COMPOUND_SELECTOR_branch_t {

public:

  static std::shared_ptr<COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 3);
    auto ptr = new COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t(children);
    std::shared_ptr<COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 33;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t(std::vector<std::shared_ptr<ast_t>> children): COMPOUND_SELECTOR_branch_t(children) {}

};  // COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t

const std::vector<symbol_t::kind_t> COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t::pattern = { symbol_t::TYPE_SELECTOR, symbol_t::COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST, symbol_t::COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST };


class COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t: public COMPOUND_SELECTOR_branch_t {

public:

  static std::shared_ptr<COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t(children);
    std::shared_ptr<COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 34;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t(std::vector<std::shared_ptr<ast_t>> children): COMPOUND_SELECTOR_branch_t(children) {}

};  // COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t

const std::vector<symbol_t::kind_t> COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t::pattern = { symbol_t::COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST, symbol_t::COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST };


class COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t: public COMPOUND_SELECTOR_branch_t {

public:

  static std::shared_ptr<COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t(children);
    std::shared_ptr<COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 35;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t(std::vector<std::shared_ptr<ast_t>> children): COMPOUND_SELECTOR_branch_t(children) {}

};  // COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t

const std::vector<symbol_t::kind_t> COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t::pattern = { symbol_t::COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST };


class COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t: public COMPOUND_SELECTOR_branch_t {

public:

  static std::shared_ptr<COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t(children);
    std::shared_ptr<COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 36;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t(std::vector<std::shared_ptr<ast_t>> children): COMPOUND_SELECTOR_branch_t(children) {}

};  // COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t

const std::vector<symbol_t::kind_t> COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t::pattern = { symbol_t::COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST };



/* base class for SIMPLE_SELECTOR_LIST_branch */
class SIMPLE_SELECTOR_LIST_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 63;

protected:

  SIMPLE_SELECTOR_LIST_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // SIMPLE_SELECTOR_LIST_branch_t

class SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_t: public SIMPLE_SELECTOR_LIST_branch_t {

public:

  static std::shared_ptr<SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_t(children);
    std::shared_ptr<SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 13;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): SIMPLE_SELECTOR_LIST_branch_t(children) {}

};  // SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_t

const std::vector<symbol_t::kind_t> SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_t::pattern = { symbol_t::SIMPLE_SELECTOR };


class SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_LIST_COMMA_SIMPLE_SELECTOR_t: public SIMPLE_SELECTOR_LIST_branch_t {

public:

  static std::shared_ptr<SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_LIST_COMMA_SIMPLE_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 3);
    auto ptr = new SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_LIST_COMMA_SIMPLE_SELECTOR_t(children);
    std::shared_ptr<SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_LIST_COMMA_SIMPLE_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 14;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_LIST_COMMA_SIMPLE_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): SIMPLE_SELECTOR_LIST_branch_t(children) {}

};  // SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_LIST_COMMA_SIMPLE_SELECTOR_t

const std::vector<symbol_t::kind_t> SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_LIST_COMMA_SIMPLE_SELECTOR_t::pattern = { symbol_t::SIMPLE_SELECTOR_LIST, symbol_t::COMMA, symbol_t::SIMPLE_SELECTOR };



/* base class for RELATIVE_SELECTOR_LIST_branch */
class RELATIVE_SELECTOR_LIST_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 64;

protected:

  RELATIVE_SELECTOR_LIST_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // RELATIVE_SELECTOR_LIST_branch_t

class RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_t: public RELATIVE_SELECTOR_LIST_branch_t {

public:

  static std::shared_ptr<RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_t(children);
    std::shared_ptr<RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 15;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): RELATIVE_SELECTOR_LIST_branch_t(children) {}

};  // RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_t

const std::vector<symbol_t::kind_t> RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_t::pattern = { symbol_t::RELATIVE_SELECTOR };


class RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_LIST_COMMA_RELATIVE_SELECTOR_t: public RELATIVE_SELECTOR_LIST_branch_t {

public:

  static std::shared_ptr<RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_LIST_COMMA_RELATIVE_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 3);
    auto ptr = new RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_LIST_COMMA_RELATIVE_SELECTOR_t(children);
    std::shared_ptr<RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_LIST_COMMA_RELATIVE_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 16;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_LIST_COMMA_RELATIVE_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): RELATIVE_SELECTOR_LIST_branch_t(children) {}

};  // RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_LIST_COMMA_RELATIVE_SELECTOR_t

const std::vector<symbol_t::kind_t> RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_LIST_COMMA_RELATIVE_SELECTOR_t::pattern = { symbol_t::RELATIVE_SELECTOR_LIST, symbol_t::COMMA, symbol_t::RELATIVE_SELECTOR };



/* base class for COMPLEX_SELECTOR_branch */
class COMPLEX_SELECTOR_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 65;

protected:

  COMPLEX_SELECTOR_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // COMPLEX_SELECTOR_branch_t

class COMPLEX_SELECTOR_from_COMPOUND_SELECTOR_t: public COMPLEX_SELECTOR_branch_t {

public:

  static std::shared_ptr<COMPLEX_SELECTOR_from_COMPOUND_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new COMPLEX_SELECTOR_from_COMPOUND_SELECTOR_t(children);
    std::shared_ptr<COMPLEX_SELECTOR_from_COMPOUND_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 17;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPLEX_SELECTOR_from_COMPOUND_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): COMPLEX_SELECTOR_branch_t(children) {}

};  // COMPLEX_SELECTOR_from_COMPOUND_SELECTOR_t

const std::vector<symbol_t::kind_t> COMPLEX_SELECTOR_from_COMPOUND_SELECTOR_t::pattern = { symbol_t::COMPOUND_SELECTOR };


class COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMBINATOR_COMPOUND_SELECTOR_t: public COMPLEX_SELECTOR_branch_t {

public:

  static std::shared_ptr<COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMBINATOR_COMPOUND_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 3);
    auto ptr = new COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMBINATOR_COMPOUND_SELECTOR_t(children);
    std::shared_ptr<COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMBINATOR_COMPOUND_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 18;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMBINATOR_COMPOUND_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): COMPLEX_SELECTOR_branch_t(children) {}

};  // COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMBINATOR_COMPOUND_SELECTOR_t

const std::vector<symbol_t::kind_t> COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMBINATOR_COMPOUND_SELECTOR_t::pattern = { symbol_t::COMPLEX_SELECTOR, symbol_t::COMBINATOR, symbol_t::COMPOUND_SELECTOR };


class COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMPOUND_SELECTOR_t: public COMPLEX_SELECTOR_branch_t {

public:

  static std::shared_ptr<COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMPOUND_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMPOUND_SELECTOR_t(children);
    std::shared_ptr<COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMPOUND_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 19;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMPOUND_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): COMPLEX_SELECTOR_branch_t(children) {}

};  // COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMPOUND_SELECTOR_t

const std::vector<symbol_t::kind_t> COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMPOUND_SELECTOR_t::pattern = { symbol_t::COMPLEX_SELECTOR, symbol_t::COMPOUND_SELECTOR };



/* base class for RELATIVE_SELECTOR_branch */
class RELATIVE_SELECTOR_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 66;

protected:

  RELATIVE_SELECTOR_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // RELATIVE_SELECTOR_branch_t

class RELATIVE_SELECTOR_from_COMPLEX_SELECTOR_t: public RELATIVE_SELECTOR_branch_t {

public:

  static std::shared_ptr<RELATIVE_SELECTOR_from_COMPLEX_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new RELATIVE_SELECTOR_from_COMPLEX_SELECTOR_t(children);
    std::shared_ptr<RELATIVE_SELECTOR_from_COMPLEX_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 20;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  RELATIVE_SELECTOR_from_COMPLEX_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): RELATIVE_SELECTOR_branch_t(children) {}

};  // RELATIVE_SELECTOR_from_COMPLEX_SELECTOR_t

const std::vector<symbol_t::kind_t> RELATIVE_SELECTOR_from_COMPLEX_SELECTOR_t::pattern = { symbol_t::COMPLEX_SELECTOR };


class RELATIVE_SELECTOR_from_COMBINATOR_COMPLEX_SELECTOR_t: public RELATIVE_SELECTOR_branch_t {

public:

  static std::shared_ptr<RELATIVE_SELECTOR_from_COMBINATOR_COMPLEX_SELECTOR_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 2);
    auto ptr = new RELATIVE_SELECTOR_from_COMBINATOR_COMPLEX_SELECTOR_t(children);
    std::shared_ptr<RELATIVE_SELECTOR_from_COMBINATOR_COMPLEX_SELECTOR_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 21;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  RELATIVE_SELECTOR_from_COMBINATOR_COMPLEX_SELECTOR_t(std::vector<std::shared_ptr<ast_t>> children): RELATIVE_SELECTOR_branch_t(children) {}

};  // RELATIVE_SELECTOR_from_COMBINATOR_COMPLEX_SELECTOR_t

const std::vector<symbol_t::kind_t> RELATIVE_SELECTOR_from_COMBINATOR_COMPLEX_SELECTOR_t::pattern = { symbol_t::COMBINATOR, symbol_t::COMPLEX_SELECTOR };



/* base class for SELECTOR_LIST_branch */
class SELECTOR_LIST_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 67;

protected:

  SELECTOR_LIST_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // SELECTOR_LIST_branch_t

class SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_t: public SELECTOR_LIST_branch_t {

public:

  static std::shared_ptr<SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_t(children);
    std::shared_ptr<SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 2;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_t(std::vector<std::shared_ptr<ast_t>> children): SELECTOR_LIST_branch_t(children) {}

};  // SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_t

const std::vector<symbol_t::kind_t> SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_t::pattern = { symbol_t::COMPLEX_SELECTOR_LIST };



/* base class for COMBINATOR_branch */
class COMBINATOR_branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 68;

protected:

  COMBINATOR_branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // COMBINATOR_branch_t

class COMBINATOR_from_GREATER_THAN_t: public COMBINATOR_branch_t {

public:

  static std::shared_ptr<COMBINATOR_from_GREATER_THAN_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new COMBINATOR_from_GREATER_THAN_t(children);
    std::shared_ptr<COMBINATOR_from_GREATER_THAN_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 39;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMBINATOR_from_GREATER_THAN_t(std::vector<std::shared_ptr<ast_t>> children): COMBINATOR_branch_t(children) {}

};  // COMBINATOR_from_GREATER_THAN_t

const std::vector<symbol_t::kind_t> COMBINATOR_from_GREATER_THAN_t::pattern = { symbol_t::GREATER_THAN };


class COMBINATOR_from_PLUS_t: public COMBINATOR_branch_t {

public:

  static std::shared_ptr<COMBINATOR_from_PLUS_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new COMBINATOR_from_PLUS_t(children);
    std::shared_ptr<COMBINATOR_from_PLUS_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 40;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMBINATOR_from_PLUS_t(std::vector<std::shared_ptr<ast_t>> children): COMBINATOR_branch_t(children) {}

};  // COMBINATOR_from_PLUS_t

const std::vector<symbol_t::kind_t> COMBINATOR_from_PLUS_t::pattern = { symbol_t::PLUS };


class COMBINATOR_from_TILDE_t: public COMBINATOR_branch_t {

public:

  static std::shared_ptr<COMBINATOR_from_TILDE_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new COMBINATOR_from_TILDE_t(children);
    std::shared_ptr<COMBINATOR_from_TILDE_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 41;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMBINATOR_from_TILDE_t(std::vector<std::shared_ptr<ast_t>> children): COMBINATOR_branch_t(children) {}

};  // COMBINATOR_from_TILDE_t

const std::vector<symbol_t::kind_t> COMBINATOR_from_TILDE_t::pattern = { symbol_t::TILDE };


class COMBINATOR_from_COLUMN_TOKEN_t: public COMBINATOR_branch_t {

public:

  static std::shared_ptr<COMBINATOR_from_COLUMN_TOKEN_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new COMBINATOR_from_COLUMN_TOKEN_t(children);
    std::shared_ptr<COMBINATOR_from_COLUMN_TOKEN_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 42;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  COMBINATOR_from_COLUMN_TOKEN_t(std::vector<std::shared_ptr<ast_t>> children): COMBINATOR_branch_t(children) {}

};  // COMBINATOR_from_COLUMN_TOKEN_t

const std::vector<symbol_t::kind_t> COMBINATOR_from_COLUMN_TOKEN_t::pattern = { symbol_t::COLUMN_TOKEN };



/* base class for __omega___branch */
class __omega___branch_t: public ast_t {

public:

  virtual symbol_t::kind_t get_symbol_id() const override {
    return static_cast<symbol_t::kind_t>(symbol_id);
  }

  static constexpr int symbol_id = 69;

protected:

  __omega___branch_t(std::vector<std::shared_ptr<ast_t>> children): ast_t(children) {}

};  // __omega___branch_t

class __omega___from_SELECTOR_LIST_t: public __omega___branch_t {

public:

  static std::shared_ptr<__omega___from_SELECTOR_LIST_t> make(std::vector<std::shared_ptr<ast_t>> children) {
    assert(children.size() == 1);
    auto ptr = new __omega___from_SELECTOR_LIST_t(children);
    std::shared_ptr<__omega___from_SELECTOR_LIST_t> result(ptr);
    return result;
  }

  virtual void accept(const visitor_t &visitor) const override {
    visitor(this);
  }

  static constexpr int rule_id = 1;

  static const std::vector<symbol_t::kind_t> pattern;

protected:

  __omega___from_SELECTOR_LIST_t(std::vector<std::shared_ptr<ast_t>> children): __omega___branch_t(children) {}

};  // __omega___from_SELECTOR_LIST_t

const std::vector<symbol_t::kind_t> __omega___from_SELECTOR_LIST_t::pattern = { symbol_t::SELECTOR_LIST };




enum action_kind_t {
  restart = 1, // unused
  reduce = 2,
  shift = 3,
  transition = 4
};

// state == actions[(state_id * num_tokens) + token_id];
// if (state == 0) accept
// if (state < 0) { reduce(state * -1); }
// if (state > 0 && state != INT16_MAX) { shift and go to (state-1) }
// if (state == INT16_MAX) { error }

// transition layout
// {
//   { reduction_id, state_id },
//   ...
// }

const int16_t num_tokens = 40;

const int16_t num_reductions = 29;

const int16_t num_symbols = 69;

const int16_t actions[69 * 89] = {

  /* s0 */ 32767 /* -- */, 2 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 3 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 4 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 5 /* PIPE */, 32767 /* ESCAPE */, 6 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 7 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 8 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 9 /* CLASS_SELECTOR */, 10 /* NS_PREFIX */, 11 /* TYPE_SELECTOR */, 12 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 13 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 14 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 15 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 16 /* ID_SELECTOR */, 17 /* SUBCLASS_SELECTOR */, 18 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 19 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 20 /* COMPLEX_SELECTOR_LIST */, 21 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 22 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 23 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s1 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 78 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s2 */ -56 /* -- */, -56 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -56 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -56 /* COMMA */, 32767 /* TAB */, -56 /* PLUS */, -56 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -56 /* GREATER_THAN */, -56 /* COLUMN_TOKEN */, -56 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -56 /* PIPE */, 32767 /* ESCAPE */, -56 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -56 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -56 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s3 */ -51 /* -- */, -51 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -51 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -51 /* COMMA */, 32767 /* TAB */, -51 /* PLUS */, -51 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -51 /* GREATER_THAN */, -51 /* COLUMN_TOKEN */, -51 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -51 /* PIPE */, 32767 /* ESCAPE */, -51 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -51 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -51 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s4 */ -46 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, -46 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, -46 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s5 */ -44 /* -- */, -44 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -44 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -44 /* COMMA */, 32767 /* TAB */, -44 /* PLUS */, -44 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -44 /* GREATER_THAN */, -44 /* COLUMN_TOKEN */, -44 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -44 /* PIPE */, 32767 /* ESCAPE */, -44 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -44 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -44 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s6 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 36 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 37 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 38 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 39 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s7 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 46 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 47 /* PIPE */, 32767 /* ESCAPE */, 48 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 49 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 50 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s8 */ -53 /* -- */, -53 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -53 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -53 /* COMMA */, 32767 /* TAB */, -53 /* PLUS */, -53 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -53 /* GREATER_THAN */, -53 /* COLUMN_TOKEN */, -53 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -53 /* PIPE */, 32767 /* ESCAPE */, -53 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -53 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -53 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s9 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 82 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 83 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s10 */ -30 /* -- */, -30 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -30 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -30 /* COMMA */, 32767 /* TAB */, -30 /* PLUS */, -30 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -30 /* GREATER_THAN */, -30 /* COLUMN_TOKEN */, -30 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -30 /* PIPE */, 32767 /* ESCAPE */, -30 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -30 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -30 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 9 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 79 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 13 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 44 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 16 /* ID_SELECTOR */, 17 /* SUBCLASS_SELECTOR */, 80 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s11 */ -35 /* -- */, -35 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -35 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -35 /* COMMA */, 32767 /* TAB */, -35 /* PLUS */, -35 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -35 /* GREATER_THAN */, -35 /* COLUMN_TOKEN */, -35 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -35 /* PIPE */, 32767 /* ESCAPE */, -35 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -35 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -35 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s12 */ -54 /* -- */, -54 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -54 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -54 /* COMMA */, 32767 /* TAB */, -54 /* PLUS */, -54 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -54 /* GREATER_THAN */, -54 /* COLUMN_TOKEN */, -54 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -54 /* PIPE */, 32767 /* ESCAPE */, -54 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -54 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -54 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s13 */ -43 /* -- */, -43 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -43 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -43 /* COMMA */, 32767 /* TAB */, -43 /* PLUS */, -43 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -43 /* GREATER_THAN */, -43 /* COLUMN_TOKEN */, -43 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -43 /* PIPE */, 32767 /* ESCAPE */, -43 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -43 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -43 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s14 */ -55 /* -- */, -55 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -55 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -55 /* COMMA */, 32767 /* TAB */, -55 /* PLUS */, -55 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -55 /* GREATER_THAN */, -55 /* COLUMN_TOKEN */, -55 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -55 /* PIPE */, 32767 /* ESCAPE */, -55 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -55 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -55 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s15 */ -52 /* -- */, -52 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -52 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -52 /* COMMA */, 32767 /* TAB */, -52 /* PLUS */, -52 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -52 /* GREATER_THAN */, -52 /* COLUMN_TOKEN */, -52 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -52 /* PIPE */, 32767 /* ESCAPE */, -52 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -52 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -52 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s16 */ -22 /* -- */, -22 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -22 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -22 /* COMMA */, 32767 /* TAB */, -22 /* PLUS */, -22 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -22 /* GREATER_THAN */, -22 /* COLUMN_TOKEN */, -22 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -22 /* PIPE */, 32767 /* ESCAPE */, -22 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -22 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -22 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s17 */ -36 /* -- */, -36 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -36 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -36 /* COMMA */, 32767 /* TAB */, -36 /* PLUS */, -36 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -36 /* GREATER_THAN */, -36 /* COLUMN_TOKEN */, -36 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -36 /* PIPE */, 32767 /* ESCAPE */, -36 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -36 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -36 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 9 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 43 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 13 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 44 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 16 /* ID_SELECTOR */, 45 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s18 */ -26 /* -- */, -26 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -26 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -26 /* COMMA */, 32767 /* TAB */, -26 /* PLUS */, -26 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -26 /* GREATER_THAN */, -26 /* COLUMN_TOKEN */, -26 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -26 /* PIPE */, 32767 /* ESCAPE */, -26 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -26 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -26 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 31 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 33 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 19 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s19 */ -2 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 88 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s20 */ -17 /* -- */, -17 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -17 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -17 /* COMMA */, 32767 /* TAB */, -17 /* PLUS */, -17 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -17 /* GREATER_THAN */, -17 /* COLUMN_TOKEN */, -17 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -17 /* PIPE */, 32767 /* ESCAPE */, -17 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -17 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -17 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s21 */ -9 /* -- */, 2 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 3 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -9 /* COMMA */, 32767 /* TAB */, 24 /* PLUS */, 4 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 25 /* GREATER_THAN */, 26 /* COLUMN_TOKEN */, 27 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 5 /* PIPE */, 32767 /* ESCAPE */, 6 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 7 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 8 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 9 /* CLASS_SELECTOR */, 10 /* NS_PREFIX */, 11 /* TYPE_SELECTOR */, 12 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 13 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 14 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 15 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 16 /* ID_SELECTOR */, 17 /* SUBCLASS_SELECTOR */, 18 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 19 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 28 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 29 /* COMBINATOR */,
  /* s22 */ 0 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s23 */ -40 /* -- */, -40 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -40 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, -40 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -40 /* PIPE */, 32767 /* ESCAPE */, -40 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -40 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -40 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s24 */ -39 /* -- */, -39 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -39 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, -39 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -39 /* PIPE */, 32767 /* ESCAPE */, -39 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -39 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -39 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s25 */ -42 /* -- */, -42 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -42 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, -42 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -42 /* PIPE */, 32767 /* ESCAPE */, -42 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -42 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -42 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s26 */ -41 /* -- */, -41 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -41 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, -41 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -41 /* PIPE */, 32767 /* ESCAPE */, -41 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -41 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -41 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s27 */ -19 /* -- */, -19 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -19 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -19 /* COMMA */, 32767 /* TAB */, -19 /* PLUS */, -19 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -19 /* GREATER_THAN */, -19 /* COLUMN_TOKEN */, -19 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -19 /* PIPE */, 32767 /* ESCAPE */, -19 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -19 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -19 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s28 */ 32767 /* -- */, 2 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 3 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 4 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 5 /* PIPE */, 32767 /* ESCAPE */, 6 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 7 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 8 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 9 /* CLASS_SELECTOR */, 10 /* NS_PREFIX */, 11 /* TYPE_SELECTOR */, 12 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 13 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 14 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 15 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 16 /* ID_SELECTOR */, 17 /* SUBCLASS_SELECTOR */, 18 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 19 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 30 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s29 */ -18 /* -- */, -18 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -18 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -18 /* COMMA */, 32767 /* TAB */, -18 /* PLUS */, -18 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -18 /* GREATER_THAN */, -18 /* COLUMN_TOKEN */, -18 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -18 /* PIPE */, 32767 /* ESCAPE */, -18 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -18 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -18 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s30 */ -28 /* -- */, -28 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -28 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -28 /* COMMA */, 32767 /* TAB */, -28 /* PLUS */, -28 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -28 /* GREATER_THAN */, -28 /* COLUMN_TOKEN */, -28 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -28 /* PIPE */, 32767 /* ESCAPE */, -28 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -28 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -28 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s31 */ -27 /* -- */, -27 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -27 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -27 /* COMMA */, 32767 /* TAB */, -27 /* PLUS */, -27 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -27 /* GREATER_THAN */, -27 /* COLUMN_TOKEN */, -27 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -27 /* PIPE */, 32767 /* ESCAPE */, -27 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -27 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -27 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 34 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 35 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 19 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s32 */ -24 /* -- */, -24 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -24 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -24 /* COMMA */, 32767 /* TAB */, -24 /* PLUS */, -24 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -24 /* GREATER_THAN */, -24 /* COLUMN_TOKEN */, -24 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -24 /* PIPE */, 32767 /* ESCAPE */, -24 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -24 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -24 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s33 */ -29 /* -- */, -29 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -29 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -29 /* COMMA */, 32767 /* TAB */, -29 /* PLUS */, -29 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -29 /* GREATER_THAN */, -29 /* COLUMN_TOKEN */, -29 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -29 /* PIPE */, 32767 /* ESCAPE */, -29 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -29 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -29 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s34 */ -25 /* -- */, -25 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -25 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -25 /* COMMA */, 32767 /* TAB */, -25 /* PLUS */, -25 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -25 /* GREATER_THAN */, -25 /* COLUMN_TOKEN */, -25 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -25 /* PIPE */, 32767 /* ESCAPE */, -25 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -25 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -25 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s35 */ -70 /* -- */, -70 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -70 /* HASH_TOKEN */, 32767 /* COMMENT */, 42 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -70 /* COMMA */, 32767 /* TAB */, -70 /* PLUS */, -70 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -70 /* GREATER_THAN */, -70 /* COLUMN_TOKEN */, -70 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -70 /* PIPE */, 32767 /* ESCAPE */, -70 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -70 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -70 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s36 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 36 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 39 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s37 */ -72 /* -- */, -72 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -72 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -72 /* COMMA */, 32767 /* TAB */, -72 /* PLUS */, -72 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -72 /* GREATER_THAN */, -72 /* COLUMN_TOKEN */, -72 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -72 /* PIPE */, 32767 /* ESCAPE */, -72 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -72 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -72 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s38 */ 32767 /* -- */, 32767 /* PERIOD */, 40 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s39 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 41 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s40 */ -71 /* -- */, -71 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -71 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -71 /* COMMA */, 32767 /* TAB */, -71 /* PLUS */, -71 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -71 /* GREATER_THAN */, -71 /* COLUMN_TOKEN */, -71 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -71 /* PIPE */, 32767 /* ESCAPE */, -71 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -71 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -71 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s41 */ -5 /* -- */, 32767 /* PERIOD */, -5 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s42 */ -34 /* -- */, -34 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -34 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -34 /* COMMA */, 32767 /* TAB */, -34 /* PLUS */, -34 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -34 /* GREATER_THAN */, -34 /* COLUMN_TOKEN */, -34 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -34 /* PIPE */, 32767 /* ESCAPE */, -34 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -34 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -34 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 35 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s43 */ -24 /* -- */, -24 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -24 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -24 /* COMMA */, 32767 /* TAB */, -24 /* PLUS */, -24 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -24 /* GREATER_THAN */, -24 /* COLUMN_TOKEN */, -24 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -24 /* PIPE */, 32767 /* ESCAPE */, -24 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -24 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -24 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s44 */ -23 /* -- */, -23 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -23 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -23 /* COMMA */, 32767 /* TAB */, -23 /* PLUS */, -23 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -23 /* GREATER_THAN */, -23 /* COLUMN_TOKEN */, -23 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -23 /* PIPE */, 32767 /* ESCAPE */, -23 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -23 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -23 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s45 */ -51 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, -51 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, -51 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, -51 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, -51 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -51 /* PIPE */, 32767 /* ESCAPE */, -51 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, -51 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s46 */ -46 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, -46 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s47 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 74 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s48 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 73 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s49 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 51 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 52 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, 53 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 54 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 55 /* PIPE */, 32767 /* ESCAPE */, 56 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 57 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 58 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s50 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 72 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s51 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 71 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s52 */ -58 /* -- */, -58 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -58 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -58 /* COMMA */, 32767 /* TAB */, -58 /* PLUS */, -58 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -58 /* GREATER_THAN */, -58 /* COLUMN_TOKEN */, -58 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -58 /* PIPE */, 32767 /* ESCAPE */, -58 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -58 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -58 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s53 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 70 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s54 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 69 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s55 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 68 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s56 */ -68 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, -68 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, -68 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s57 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 59 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 60 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s58 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, 65 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 62 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 66 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s59 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, 61 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 62 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 63 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s60 */ -62 /* -- */, -62 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -62 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -62 /* COMMA */, 32767 /* TAB */, -62 /* PLUS */, -62 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -62 /* GREATER_THAN */, -62 /* COLUMN_TOKEN */, -62 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -62 /* PIPE */, 32767 /* ESCAPE */, -62 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -62 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -62 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s61 */ -69 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, -69 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s62 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, 64 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s63 */ -60 /* -- */, -60 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -60 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -60 /* COMMA */, 32767 /* TAB */, -60 /* PLUS */, -60 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -60 /* GREATER_THAN */, -60 /* COLUMN_TOKEN */, -60 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -60 /* PIPE */, 32767 /* ESCAPE */, -60 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -60 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -60 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s64 */ -61 /* -- */, -61 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -61 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -61 /* COMMA */, 32767 /* TAB */, -61 /* PLUS */, -61 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -61 /* GREATER_THAN */, -61 /* COLUMN_TOKEN */, -61 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -61 /* PIPE */, 32767 /* ESCAPE */, -61 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -61 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -61 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s65 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, 67 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s66 */ -59 /* -- */, -59 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -59 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -59 /* COMMA */, 32767 /* TAB */, -59 /* PLUS */, -59 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -59 /* GREATER_THAN */, -59 /* COLUMN_TOKEN */, -59 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -59 /* PIPE */, 32767 /* ESCAPE */, -59 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -59 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -59 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s67 */ -63 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, -63 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, -63 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s68 */ -66 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, -66 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, -66 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s69 */ -67 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, -67 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, -67 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s70 */ -65 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, -65 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, -65 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s71 */ -64 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, -64 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, -64 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s72 */ -50 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, -50 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, -50 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, -50 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, -50 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -50 /* PIPE */, 32767 /* ESCAPE */, -50 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, -50 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s73 */ -49 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, -49 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s74 */ -48 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, -48 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s75 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 77 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s76 */ -47 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, -47 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s77 */ -57 /* -- */, -57 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -57 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -57 /* COMMA */, 32767 /* TAB */, -57 /* PLUS */, -57 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -57 /* GREATER_THAN */, -57 /* COLUMN_TOKEN */, -57 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -57 /* PIPE */, 32767 /* ESCAPE */, -57 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -57 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -57 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s78 */ -32 /* -- */, -32 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -32 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -32 /* COMMA */, 32767 /* TAB */, -32 /* PLUS */, -32 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -32 /* GREATER_THAN */, -32 /* COLUMN_TOKEN */, -32 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -32 /* PIPE */, 32767 /* ESCAPE */, -32 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -32 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -32 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 35 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s79 */ -31 /* -- */, -31 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -31 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -31 /* COMMA */, 32767 /* TAB */, -31 /* PLUS */, -31 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -31 /* GREATER_THAN */, -31 /* COLUMN_TOKEN */, -31 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -31 /* PIPE */, 32767 /* ESCAPE */, -31 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -31 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -31 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 9 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 81 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 13 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 44 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 16 /* ID_SELECTOR */, 45 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s80 */ -33 /* -- */, -33 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -33 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -33 /* COMMA */, 32767 /* TAB */, -33 /* PLUS */, -33 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -33 /* GREATER_THAN */, -33 /* COLUMN_TOKEN */, -33 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -33 /* PIPE */, 32767 /* ESCAPE */, -33 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -33 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -33 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 35 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s81 */ -50 /* -- */, -50 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -50 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -50 /* COMMA */, 32767 /* TAB */, -50 /* PLUS */, -50 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -50 /* GREATER_THAN */, -50 /* COLUMN_TOKEN */, -50 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -50 /* PIPE */, 32767 /* ESCAPE */, -50 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -50 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -50 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s82 */ -45 /* -- */, -45 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, -45 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -45 /* COMMA */, 32767 /* TAB */, -45 /* PLUS */, -45 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, -45 /* GREATER_THAN */, -45 /* COLUMN_TOKEN */, -45 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, -45 /* PIPE */, 32767 /* ESCAPE */, -45 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, -45 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, -45 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s83 */ -49 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, -49 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, -49 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s84 */ -48 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, -48 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, -48 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s85 */ 32767 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 32767 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 87 /* PIPE */, 32767 /* ESCAPE */, 32767 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s86 */ -47 /* -- */, 32767 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 32767 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, -47 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 32767 /* PIPE */, 32767 /* ESCAPE */, -47 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 32767 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 32767 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 32767 /* CLASS_SELECTOR */, 32767 /* NS_PREFIX */, 32767 /* TYPE_SELECTOR */, 32767 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 32767 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 32767 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 32767 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 32767 /* ID_SELECTOR */, 32767 /* SUBCLASS_SELECTOR */, 32767 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 32767 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 32767 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s87 */ 32767 /* -- */, 2 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 3 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, 32767 /* COMMA */, 32767 /* TAB */, 32767 /* PLUS */, 4 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 32767 /* GREATER_THAN */, 32767 /* COLUMN_TOKEN */, 32767 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 5 /* PIPE */, 32767 /* ESCAPE */, 6 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 7 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 8 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 9 /* CLASS_SELECTOR */, 10 /* NS_PREFIX */, 11 /* TYPE_SELECTOR */, 12 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 13 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 14 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 15 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 16 /* ID_SELECTOR */, 17 /* SUBCLASS_SELECTOR */, 18 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 19 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 21 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 89 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 32767 /* COMBINATOR */,
  /* s88 */ -10 /* -- */, 2 /* PERIOD */, 32767 /* ANY_VALUE */, 32767 /* WHITESPACE */, 32767 /* DOLLAR */, 3 /* HASH_TOKEN */, 32767 /* COMMENT */, 32767 /* LEFT_PAREN */, 32767 /* CARET */, 32767 /* LESSER_THEN */, 32767 /* NEWLINE */, -10 /* COMMA */, 32767 /* TAB */, 24 /* PLUS */, 4 /* IDENT_TOKEN */, 32767 /* RIGHT_BRACKET */, 32767 /* RIGHT_PAREN */, 25 /* GREATER_THAN */, 26 /* COLUMN_TOKEN */, 27 /* TILDE */, 32767 /* HEX_DIGIT */, 32767 /* CDC_TOKEN */, 5 /* PIPE */, 32767 /* ESCAPE */, 6 /* ASTERISK */, 32767 /* STRING_TOKEN */, 32767 /* NUMBER_TOKEN */, 32767 /* UNICODE_RANGE_TOKEN */, 32767 /* INCLUDE_MATCH_TOKEN */, 32767 /* PREFIX_MATCH_TOKEN */, 7 /* COLON */, 32767 /* DASH_MATCH_TOKEN */, 32767 /* PERCENT */, 32767 /* LETTER_I */, 32767 /* SUFFIX_MATCH_TOKEN */, 8 /* LEFT_BRACKET */, 32767 /* EQUALS */, 32767 /* CDO_TOKEN */, 32767 /* SUBSTRING_MATCH_TOKEN */, 32767 /* AT */, /* END TOKENS */ 32767 /* ATTR_MATCHER */, 9 /* CLASS_SELECTOR */, 10 /* NS_PREFIX */, 11 /* TYPE_SELECTOR */, 12 /* COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST */, 32767 /* ATTR_MODIFIER */, 32767 /* COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST */, 13 /* ATTRIBUTE_SELECTOR */, 32767 /* DIMENSION_TOKEN */, 14 /* WQ_NAME */, 32767 /* SIMPLE_SELECTOR */, 15 /* PSEUDO_CLASS_SELECTOR */, 32767 /* AT_KEYWORD_TOKEN */, 32767 /* PERCENTAGE_TOKEN */, 16 /* ID_SELECTOR */, 17 /* SUBCLASS_SELECTOR */, 18 /* COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST */, 19 /* PSEUDO_ELEMENT_SELECTOR */, 32767 /* COMPOUND_SELECTOR_LIST */, 32767 /* FUNCTION_TOKEN */, 32767 /* WHITESPACE_TOKEN */, 32767 /* COMPLEX_SELECTOR_LIST */, 28 /* COMPOUND_SELECTOR */, 32767 /* SIMPLE_SELECTOR_LIST */, 32767 /* RELATIVE_SELECTOR_LIST */, 32767 /* COMPLEX_SELECTOR */, 32767 /* RELATIVE_SELECTOR */, 32767 /* SELECTOR_LIST */, 29 /* COMBINATOR */

};   // actions
  /* rule ids start at one */
const int rule_lengths[72] = {
  1, // #1 __omega___from_SELECTOR_LIST
  1, // #2 SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST
  1, // #3 WHITESPACE_TOKEN_from_WHITESPACE
  2, // #4 WHITESPACE_TOKEN_from_WHITESPACE_TOKEN_WHITESPACE
  2, // #5 FUNCTION_TOKEN_from_IDENT_TOKEN_LEFT_PAREN
  2, // #6 AT_KEYWORD_TOKEN_from_AT_IDENT_TOKEN
  2, // #7 DIMENSION_TOKEN_from_NUMBER_TOKEN_IDENT_TOKEN
  2, // #8 PERCENTAGE_TOKEN_from_NUMBER_TOKEN_PERCENT
  1, // #9 COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR
  3, // #10 COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_COMMA_COMPLEX_SELECTOR
  1, // #11 COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR
  3, // #12 COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_LIST_COMMA_COMPOUND_SELECTOR
  1, // #13 SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR
  3, // #14 SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_LIST_COMMA_SIMPLE_SELECTOR
  1, // #15 RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR
  3, // #16 RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_LIST_COMMA_RELATIVE_SELECTOR
  1, // #17 COMPLEX_SELECTOR_from_COMPOUND_SELECTOR
  3, // #18 COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMBINATOR_COMPOUND_SELECTOR
  2, // #19 COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMPOUND_SELECTOR
  1, // #20 RELATIVE_SELECTOR_from_COMPLEX_SELECTOR
  2, // #21 RELATIVE_SELECTOR_from_COMBINATOR_COMPLEX_SELECTOR
  1, // #22 COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_SUBCLASS_SELECTOR
  2, // #23 COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_SUBCLASS_SELECTOR
  1, // #24 COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_PSEUDO_CLASS_SELECTOR
  2, // #25 COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_PSEUDO_CLASS_SELECTOR
  1, // #26 COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR
  2, // #27 COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST
  2, // #28 COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST
  3, // #29 COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST
  1, // #30 COMPOUND_SELECTOR_from_TYPE_SELECTOR
  2, // #31 COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST
  2, // #32 COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST
  3, // #33 COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST
  2, // #34 COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST
  1, // #35 COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST
  1, // #36 COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST
  1, // #37 SIMPLE_SELECTOR_from_TYPE_SELECTOR
  1, // #38 SIMPLE_SELECTOR_from_SUBCLASS_SELECTOR
  1, // #39 COMBINATOR_from_GREATER_THAN
  1, // #40 COMBINATOR_from_PLUS
  1, // #41 COMBINATOR_from_TILDE
  1, // #42 COMBINATOR_from_COLUMN_TOKEN
  1, // #43 TYPE_SELECTOR_from_WQ_NAME
  1, // #44 TYPE_SELECTOR_from_ASTERISK
  2, // #45 TYPE_SELECTOR_from_NS_PREFIX_ASTERISK
  1, // #46 NS_PREFIX_from_PIPE
  3, // #47 NS_PREFIX_from_IDENT_TOKEN_ASTERISK_PIPE
  2, // #48 NS_PREFIX_from_IDENT_TOKEN_PIPE
  2, // #49 NS_PREFIX_from_ASTERISK_PIPE
  2, // #50 WQ_NAME_from_NS_PREFIX_IDENT_TOKEN
  1, // #51 WQ_NAME_from_IDENT_TOKEN
  1, // #52 SUBCLASS_SELECTOR_from_ID_SELECTOR
  1, // #53 SUBCLASS_SELECTOR_from_CLASS_SELECTOR
  1, // #54 SUBCLASS_SELECTOR_from_ATTRIBUTE_SELECTOR
  1, // #55 SUBCLASS_SELECTOR_from_PSEUDO_CLASS_SELECTOR
  1, // #56 ID_SELECTOR_from_HASH_TOKEN
  2, // #57 CLASS_SELECTOR_from_PERIOD_IDENT_TOKEN
  3, // #58 ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_RIGHT_BRACKET
  6, // #59 ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET
  6, // #60 ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET
  5, // #61 ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_RIGHT_BRACKET
  5, // #62 ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_RIGHT_BRACKET
  2, // #63 ATTR_MATCHER_from_ASTERISK_EQUALS
  2, // #64 ATTR_MATCHER_from_DOLLAR_EQUALS
  2, // #65 ATTR_MATCHER_from_CARET_EQUALS
  2, // #66 ATTR_MATCHER_from_PIPE_EQUALS
  2, // #67 ATTR_MATCHER_from_TILDE_EQUALS
  1, // #68 ATTR_MATCHER_from_EQUALS
  1, // #69 ATTR_MODIFIER_from_LETTER_I
  2, // #70 PSEUDO_CLASS_SELECTOR_from_COLON_IDENT_TOKEN
  4, // #71 PSEUDO_CLASS_SELECTOR_from_COLON_FUNCTION_TOKEN_ANY_VALUE_RIGHT_PAREN
  2 // #72 PSEUDO_ELEMENT_SELECTOR_from_COLON_PSEUDO_CLASS_SELECTOR
}; // rule_lengths 


using action_t = std::pair<action_kind_t, int>;

std::shared_ptr<ast_t> default_reduce_by_id(int id, std::vector<std::shared_ptr<ast_t>> &children) {
  switch (id) {
  case 1:
    return __omega___from_SELECTOR_LIST_t::make(children);
  case 2:
    return SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_t::make(children);
  case 3:
    return WHITESPACE_TOKEN_from_WHITESPACE_t::make(children);
  case 4:
    return WHITESPACE_TOKEN_from_WHITESPACE_TOKEN_WHITESPACE_t::make(children);
  case 5:
    return FUNCTION_TOKEN_from_IDENT_TOKEN_LEFT_PAREN_t::make(children);
  case 6:
    return AT_KEYWORD_TOKEN_from_AT_IDENT_TOKEN_t::make(children);
  case 7:
    return DIMENSION_TOKEN_from_NUMBER_TOKEN_IDENT_TOKEN_t::make(children);
  case 8:
    return PERCENTAGE_TOKEN_from_NUMBER_TOKEN_PERCENT_t::make(children);
  case 9:
    return COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_t::make(children);
  case 10:
    return COMPLEX_SELECTOR_LIST_from_COMPLEX_SELECTOR_LIST_COMMA_COMPLEX_SELECTOR_t::make(children);
  case 11:
    return COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_t::make(children);
  case 12:
    return COMPOUND_SELECTOR_LIST_from_COMPOUND_SELECTOR_LIST_COMMA_COMPOUND_SELECTOR_t::make(children);
  case 13:
    return SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_t::make(children);
  case 14:
    return SIMPLE_SELECTOR_LIST_from_SIMPLE_SELECTOR_LIST_COMMA_SIMPLE_SELECTOR_t::make(children);
  case 15:
    return RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_t::make(children);
  case 16:
    return RELATIVE_SELECTOR_LIST_from_RELATIVE_SELECTOR_LIST_COMMA_RELATIVE_SELECTOR_t::make(children);
  case 17:
    return COMPLEX_SELECTOR_from_COMPOUND_SELECTOR_t::make(children);
  case 18:
    return COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMBINATOR_COMPOUND_SELECTOR_t::make(children);
  case 19:
    return COMPLEX_SELECTOR_from_COMPLEX_SELECTOR_COMPOUND_SELECTOR_t::make(children);
  case 20:
    return RELATIVE_SELECTOR_from_COMPLEX_SELECTOR_t::make(children);
  case 21:
    return RELATIVE_SELECTOR_from_COMBINATOR_COMPLEX_SELECTOR_t::make(children);
  case 22:
    return COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_SUBCLASS_SELECTOR_t::make(children);
  case 23:
    return COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_SUBCLASS_SELECTOR_t::make(children);
  case 24:
    return COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_PSEUDO_CLASS_SELECTOR_t::make(children);
  case 25:
    return COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_from_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_PSEUDO_CLASS_SELECTOR_t::make(children);
  case 26:
    return COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_t::make(children);
  case 27:
    return COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t::make(children);
  case 28:
    return COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t::make(children);
  case 29:
    return COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_from_PSEUDO_ELEMENT_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t::make(children);
  case 30:
    return COMPOUND_SELECTOR_from_TYPE_SELECTOR_t::make(children);
  case 31:
    return COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t::make(children);
  case 32:
    return COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t::make(children);
  case 33:
    return COMPOUND_SELECTOR_from_TYPE_SELECTOR_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t::make(children);
  case 34:
    return COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_COMPOUND_SELECTOR_PSUEDO_CLASS_SELECTOR_LIST_t::make(children);
  case 35:
    return COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_PSEUDO_SELECTOR_LIST_t::make(children);
  case 36:
    return COMPOUND_SELECTOR_from_COMPOUND_SELECTOR_SUBCLASS_SELECTOR_LIST_t::make(children);
  case 37:
    return SIMPLE_SELECTOR_from_TYPE_SELECTOR_t::make(children);
  case 38:
    return SIMPLE_SELECTOR_from_SUBCLASS_SELECTOR_t::make(children);
  case 39:
    return COMBINATOR_from_GREATER_THAN_t::make(children);
  case 40:
    return COMBINATOR_from_PLUS_t::make(children);
  case 41:
    return COMBINATOR_from_TILDE_t::make(children);
  case 42:
    return COMBINATOR_from_COLUMN_TOKEN_t::make(children);
  case 43:
    return TYPE_SELECTOR_from_WQ_NAME_t::make(children);
  case 44:
    return TYPE_SELECTOR_from_ASTERISK_t::make(children);
  case 45:
    return TYPE_SELECTOR_from_NS_PREFIX_ASTERISK_t::make(children);
  case 46:
    return NS_PREFIX_from_PIPE_t::make(children);
  case 47:
    return NS_PREFIX_from_IDENT_TOKEN_ASTERISK_PIPE_t::make(children);
  case 48:
    return NS_PREFIX_from_IDENT_TOKEN_PIPE_t::make(children);
  case 49:
    return NS_PREFIX_from_ASTERISK_PIPE_t::make(children);
  case 50:
    return WQ_NAME_from_NS_PREFIX_IDENT_TOKEN_t::make(children);
  case 51:
    return WQ_NAME_from_IDENT_TOKEN_t::make(children);
  case 52:
    return SUBCLASS_SELECTOR_from_ID_SELECTOR_t::make(children);
  case 53:
    return SUBCLASS_SELECTOR_from_CLASS_SELECTOR_t::make(children);
  case 54:
    return SUBCLASS_SELECTOR_from_ATTRIBUTE_SELECTOR_t::make(children);
  case 55:
    return SUBCLASS_SELECTOR_from_PSEUDO_CLASS_SELECTOR_t::make(children);
  case 56:
    return ID_SELECTOR_from_HASH_TOKEN_t::make(children);
  case 57:
    return CLASS_SELECTOR_from_PERIOD_IDENT_TOKEN_t::make(children);
  case 58:
    return ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_RIGHT_BRACKET_t::make(children);
  case 59:
    return ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t::make(children);
  case 60:
    return ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_ATTR_MODIFIER_RIGHT_BRACKET_t::make(children);
  case 61:
    return ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_IDENT_TOKEN_RIGHT_BRACKET_t::make(children);
  case 62:
    return ATTRIBUTE_SELECTOR_from_LEFT_BRACKET_WQ_NAME_ATTR_MATCHER_STRING_TOKEN_RIGHT_BRACKET_t::make(children);
  case 63:
    return ATTR_MATCHER_from_ASTERISK_EQUALS_t::make(children);
  case 64:
    return ATTR_MATCHER_from_DOLLAR_EQUALS_t::make(children);
  case 65:
    return ATTR_MATCHER_from_CARET_EQUALS_t::make(children);
  case 66:
    return ATTR_MATCHER_from_PIPE_EQUALS_t::make(children);
  case 67:
    return ATTR_MATCHER_from_TILDE_EQUALS_t::make(children);
  case 68:
    return ATTR_MATCHER_from_EQUALS_t::make(children);
  case 69:
    return ATTR_MODIFIER_from_LETTER_I_t::make(children);
  case 70:
    return PSEUDO_CLASS_SELECTOR_from_COLON_IDENT_TOKEN_t::make(children);
  case 71:
    return PSEUDO_CLASS_SELECTOR_from_COLON_FUNCTION_TOKEN_ANY_VALUE_RIGHT_PAREN_t::make(children);
  case 72:
    return PSEUDO_ELEMENT_SELECTOR_from_COLON_PSEUDO_CLASS_SELECTOR_t::make(children);

  } // switch
  throw std::runtime_error("rule id unknown");
}

class parser_t {

public:

  parser_t(): action_stack({ {action_kind_t::transition, 0} }), go(false) {}

  virtual ~parser_t() = default;

  using output_stack_t = std::vector<std::shared_ptr<ast_t>>;

  using input_queue_t = std::vector<std::shared_ptr<token_t>>;

  void write_states(std::ostream &strm) {
    strm << "states: ";

    for (auto it = states.begin(); it != states.end(); ++it) {
      strm << (*it);
      if (std::next(it) != states.end()) {
        strm << ", ";
      }
    }
  }

  void write_output(std::ostream &strm) {
    strm << "ast: ";

    for (auto it = output.begin(); it != output.end(); ++it) {
      strm << (*it)->get_name();
      if (std::next(it) != output.end()) {
        strm << ", ";
      }
    }
  }

  void write_input(std::ostream &strm) {
    strm << "input: ";

    for (auto it = input.begin(); it != input.end(); ++it) {
      strm << (*it)->get_name();
      if (std::next(it) != input.end()) {
        strm << ", ";
      }
    }
  }

  using cb_action_t = std::function<void(const action_t &)>;
  using cb_reduce_t = std::function<void(std::shared_ptr<ast_t>)>;

  std::vector<cb_action_t> on_step_cbs;
  std::vector<cb_action_t> on_shift_cbs;
  std::vector<cb_action_t> on_accept_cbs;
  std::vector<cb_action_t> on_transition_cbs;
  std::unordered_map<int, cb_reduce_t> on_reduce_cbs;

  void on_step(const cb_action_t &cb) {
    on_step_cbs.push_back(cb);
  }

  void on_reduce(int rule_id, const cb_reduce_t &cb) {
    on_reduce_cbs[rule_id] = cb;
  }

  void on_accept(const cb_action_t &cb) {
    on_accept_cbs.push_back(cb);
  }

  void on_shift(const cb_action_t &cb) {
    on_shift_cbs.push_back(cb);
  }

  void on_transition(const cb_action_t &cb) {
    on_transition_cbs.push_back(cb);
  }

  void emit_on_step(const action_t &data) {
    for (const auto &cb: on_step_cbs) {
      cb(data);
    }
  }

  void emit_on_reduce(int rule_id, std::shared_ptr<ast_t> reduction) {
    if (on_reduce_cbs.find(rule_id) != on_reduce_cbs.end()) {
      on_reduce_cbs[rule_id](reduction);
    }
  }

  void emit_on_shift(const action_t &data) {
    for (const auto &cb: on_shift_cbs) {
      cb(data);
    }
  }

  void emit_on_accept(const action_t &data) {
    for (const auto &cb: on_accept_cbs) {
      cb(data);
    }
  }

  void emit_on_transition(const action_t &data) {
    for (const auto &cb: on_transition_cbs) {
      cb(data);
    }
  }

  std::vector<std::shared_ptr<token_t>> get_remaining_input() const {
    return input;
  }

  std::vector<std::shared_ptr<ast_t>> get_output() const {
    return output;
  }

  std::vector<std::shared_ptr<ast_t>> parse(input_queue_t tokens) {
    input = tokens;
    go = true;

    while(go) {
      auto action = action_stack.back();
      emit_on_step(action);
      switch (action.first) {
        case restart:
          // accept
          on_restart_action();
          break;
        case reduce:
          // get the rule associated with this action,
          // identify size of rule, pop n tokens
          // from output stack, create reduction, push
          // output. Push transition state on to state stack
          on_reduce_action();
          break;
        case shift:
          // shift the token and goto next state
          emit_on_shift(action);
          on_shift_action();
          break;
        case transition:
          // push the state identified in goto table
          emit_on_transition(action);
          on_transition_action();
          break;
      }
    }

    return output;
  }

  static std::shared_ptr<parser_t> make() {
    return std::make_shared<parser_t>();
  }

protected:

  /* scan token accepts the next token, and may return the same token, or a different
   * token. The token returned is used. */
  virtual std::shared_ptr<token_t> scan_token(std::shared_ptr<token_t> token) const {
    return token;
  }

  virtual std::shared_ptr<ast_t> reduce_by_id(int id, std::vector<std::shared_ptr<ast_t>> &children) {
    return default_reduce_by_id(id, children);
  }

  std::shared_ptr<token_t> get_next_token() {
    if (!last_token_scanned || last_token_scanned != input.front()) {
      last_token_scanned = scan_token(input.front());

      if (last_token_scanned != input.front()) {
        input.front() = last_token_scanned;
      }
    }
    return last_token_scanned;
  }

  std::vector<std::shared_ptr<ast_t>> pop_reduction(int id) {
    int len = rule_lengths[id - 1];
    assert(int(output.size()) >= len);
    std::vector<std::shared_ptr<ast_t>> children;
    for (int i = 0; i < len; ++i) {
      states.pop_back();
      children.push_back(output.back());
      output.pop_back();
    }
    std::reverse(children.begin(), children.end());
    return children;
  }

  void on_restart_action() {
    if (input.size() == 0) {
      go = false;
      emit_on_accept(action_stack.back());
    }
  }

  void on_reduce_action() {
    // lookup the reduction by rule id
    assert(action_stack.back().first == reduce);
    assert(action_stack.back().second >= 0);
    int rule_id = action_stack.back().second;
    std::vector<std::shared_ptr<ast_t>> children = pop_reduction(rule_id);
    auto reduction = reduce_by_id(rule_id, children);
    emit_on_reduce(rule_id, reduction);
    output.push_back(reduction);

    int last_state = states.back();
    action_stack.push_back(get_transition(reduction->get_symbol_id(), last_state));
  }

  void on_shift_action() {
    assert(action_stack.back().first == shift);
    assert(action_stack.back().second >= 0);

    if (input.empty()) {
      throw_unexpected_eof();
      throw std::runtime_error("unexpected end of program");
    }

    auto shifted_token = ast_token_t::make(get_next_token());
    input.erase(input.begin());
    output.push_back(shifted_token);
    int next_state = action_stack.back().second;

    if (input.empty()) {
      int token_id = static_cast<int>(symbol_t::__break__);
      action_stack.push_back(get_action(token_id, next_state));
    } else {
      int token_id = static_cast<int>(get_next_token()->get_kind());
      action_stack.push_back(get_action(token_id, next_state));
    }

    states.push_back(next_state);
  }

  void on_transition_action() {
    assert(action_stack.back().first == transition);
    assert(action_stack.back().second >= 0 && action_stack.back().second < INT16_MAX);
    int transition_to = action_stack.back().second;
    states.push_back(transition_to);

    if (input.empty()) {
      int token_id = static_cast<int>(symbol_t::__break__);
      action_stack.push_back(get_action(token_id, transition_to));
    } else {
      int token_id = static_cast<int>(get_next_token()->get_kind());
      action_stack.push_back(get_action(token_id, transition_to));
    }
  }

  /* get transition from table */
  action_t get_transition(int reduction_id, int state_id) {
    assert(((state_id * num_symbols) + reduction_id) < int(sizeof(actions)));
    auto action = actions[(state_id * num_symbols) + reduction_id];

    if (action < INT16_MAX) {
      return {action_kind_t::transition, action - 1};
    }

    throw_unexpected_token();
    throw std::runtime_error("unexpected token");
  }

  /* get action from table */
  action_t get_action(int token_id, int state_id) {
    assert(((state_id * num_symbols) + token_id) < int(sizeof(actions)));
    auto action = actions[(state_id * num_symbols) + token_id];

    if (action < 0) {
      // reduce
      return {action_kind_t::reduce, action * -1};
    } else if (action == 0) {
      // accept
      return {action_kind_t::restart, 0};
    } else if (action < INT16_MAX) {
      // shift
      return {action_kind_t::shift, action - 1};
    }

    throw_unexpected_token();
    throw std::runtime_error("unexpected token");
  }

  virtual void throw_unexpected_token() {}

  virtual void throw_unexpected_eof() {}

  /* temporary input queue */
  input_queue_t input;

  /* state stack */
  std::vector<int> states;

  /* action stack */
  std::vector<action_t> action_stack;

  /* output stack */
  output_stack_t output;

  std::shared_ptr<token_t> last_token_scanned;

  bool go;

};  // parser_t

}   // css
