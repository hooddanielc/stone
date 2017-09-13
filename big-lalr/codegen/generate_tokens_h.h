#pragma once

#include <sstream>

namespace biglr {

inline std::string generate_tokens_h(const std::vector<std::shared_ptr<token_t>> &tokens) {
  std::stringstream ss;
  ss << "class token_t {" << std::endl;
  ss << std::endl;
  ss << "public:" << std::endl;
  ss << std::endl;
  ss << "  enum kind_t {" << std::endl;
  for (auto it = tokens.begin(); it != tokens.end(); ++it) {
    auto token = *it;

    if (!token->is_break() && !token->is_epsilon()) {
      ss << "    " << token->get_cpp_identifier();

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
  ss << "  /* Cache the kind. */" << std::endl;
  ss << "  token_t(kind_t kind): kind(kind) {}" << std::endl;
  ss << std::endl;
  ss << "protected:" << std::endl;
  ss << std::endl;
  ss << "  kind_t kind;" << std::endl;
  ss << std::endl;
  ss << "};   // token_t" << std::endl;
  return ss.str();
}

}   // biglr