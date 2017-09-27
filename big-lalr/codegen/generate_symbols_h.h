#pragma once

#include <sstream>

namespace biglr {

inline std::string generate_symbols_h(std::vector<std::shared_ptr<symbol_t>> symbols) {
  std::sort(symbols.begin(), symbols.end(), [](auto a, auto b) {
    return a->get_id() < b->get_id();
  });

  std::stringstream ss;
  ss << "class symbol_t {" << std::endl;
  ss << std::endl;
  ss << "public:" << std::endl;
  ss << std::endl;
  ss << "  enum kind_t {" << std::endl;
  for (auto it = symbols.begin(); it != symbols.end(); ++it) {
    ss << "      " << (*it)->get_cpp_identifier() << " = " << (*it)->get_id();
    if (it + 1 != symbols.end()) {
      ss << ",";
    }
    ss << std::endl;
  }
  ss << "  };   // symbol_t" << std::endl;
  ss << std::endl;
  ss << "  static std::string get_name(const kind_t &kind) {" << std::endl;
  ss << "    switch(kind) {" << std::endl;
  for (auto it = symbols.begin(); it != symbols.end(); ++it) {
    auto symbol = *it;
    ss << "      case " << symbol->get_cpp_identifier() << ":";
    ss << " return \"" << symbol->get_cpp_identifier() << "\";" << std::endl;
  }
  ss << "    }" << std::endl;
  ss << "    return \"unknown\";" << std::endl;
  ss << "  }" << std::endl;
  ss << "};" << std::endl;

  for (auto symbol: symbols) {}

  ss << R"(

template <int id>
struct reduction_lookup_t {};

)";

  return ss.str();
}

}   // biglr