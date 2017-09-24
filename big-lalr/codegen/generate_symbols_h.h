#pragma once

#include <sstream>

namespace biglr {

inline std::string generate_symbols_h(std::vector<std::shared_ptr<symbol_t>> symbols) {
  std::stringstream ss;
  ss << "enum symbol_t {" << std::endl;
  for (auto it = symbols.begin(); it != symbols.end(); ++it) {
    ss << "    " << (*it)->get_cpp_identifier() << " = " << (*it)->get_id();
    if (it + 1 != symbols.end()) {
      ss << ",";
    }
    ss << std::endl;
  }
  ss << "};   // symbol_t" << std::endl;

  for (auto symbol: symbols) {}

  ss << R"(

template <symbol_t type>
struct symbol_description_t {

  static std::string get_name();

  static bool is_terminal();

};   // symbol_description_t<symbol_t>

)";

  for (auto it = symbols.begin(); it != symbols.end(); ++it) {
    auto id = (*it)->get_cpp_identifier();
    ss << R"(

template <>
struct symbol_description_t<)" << id << R"(> {

  static std::string get_name() {
    return ")" << id << R"(";
  }

  static bool is_terminal() {
    return )" << ((*it)->is_reduction() ? "false" : "true") << R"(;
  }

};   // symbol_description_t<symbol_t>

)";

  }

  ss << R"(

template <int id>
struct reduction_lookup_t {};

)";

  return ss.str();
}

}   // biglr