#pragma once

#include <sstream>

namespace biglr {

inline std::vector<std::string> get_tokens_deps() {
  return { "string", "memory" };
}

inline std::string generate_tokens_h(std::vector<std::shared_ptr<token_t>> tokens) {
  std::stringstream ss;

  std::sort(tokens.begin(), tokens.end(), [](auto a, auto b) {
    return a->get_id() < b->get_id();
  });

ss <<

R"(
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

  friend std::ostream &operator<<(std::ostream &strm, const pos_t &that) {
    return strm
        << "line " << that.line_number
        << ", col " << that.col_number;
  }

private:

  int line_number, col_number;

};  // pos_t

)";

  ss << "class token_t {" << std::endl;
  ss << std::endl;
  ss << "public:" << std::endl;
  ss << std::endl;
  ss << "  enum kind_t {" << std::endl;
  for (auto it = tokens.begin(); it != tokens.end(); ++it) {
    auto token = *it;

    if (!token->is_break() && !token->is_epsilon()) {
      ss << "    " << token->get_cpp_identifier() << " = " << token->get_id();

      if ((it + 1) != tokens.end()) {
        ss << "," << std::endl;
      } else {
        ss << std::endl;
      }
    }
  }
  ss << "  };   // kind_t" << std::endl;
  ss << std::endl;
  ss << "  kind_t get_kind() {" << std::endl;
  ss << "    return kind;" << std::endl;
  ss << "  }" << std::endl;
  ss << std::endl;
  ss << "  std::string get_name() {" << std::endl;
  ss << "    return token_t::get_desc(kind);" << std::endl;
  ss << "  }" << std::endl;
  ss << std::endl;
  ss << "  static std::string get_desc(kind_t kind) {" << std::endl;
  ss << "    switch(kind) {" << std::endl;
  for (auto it = tokens.begin(); it != tokens.end(); ++it) {
    auto token = *it;

    if (!token->is_break() && !token->is_epsilon()) {
      ss << "      case " << token->get_cpp_identifier() << ":";
      ss << " return \"" << token->get_cpp_identifier() << "\";" << std::endl;
    }
  }
  ss << "    }" << std::endl;
  ss << "    return \"unknown\";" << std::endl;
  ss << "  }" << std::endl;
  ss << std::endl;
  ss << "  static std::shared_ptr<token_t> make(kind_t kind) {" << std::endl;
  ss << "    auto ptr = new token_t(kind);" << std::endl;
  ss << "    std::shared_ptr<token_t> result(ptr);" << std::endl;
  ss << "    return result;" << std::endl;
  ss << "  }" << std::endl;
  ss << std::endl;
  ss << "protected:" << std::endl;

  ss <<
R"(
  /* Cache the kind. */
  token_t(kind_t kind): kind(kind) {}

  /* Cache the position and kind and set the text to the empty string. */
  token_t(const pos_t &pos, kind_t kind): pos(pos), kind(kind) {}

  /* Cache the position and kind and the text. */
  token_t(const pos_t &pos, kind_t kind, std::string &&text):
    pos(pos),
    kind(kind),
    text(std::move(text)) {}

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
)";

  ss << "};   // token_t" << std::endl;
  return ss.str();
}

}   // biglr