#include "parser.h"
#include <emscripten/bind.h>
using namespace emscripten;

std::string parse_glsl(const std::string &src) {
  std::stringstream ss;
  try {
    auto ast = gliss::parser_t::parse_string(src.c_str());
    auto json = ast->to_json();
    ss << json;
    return ss.str();
  } catch (const std::exception &e) {
    nlohmann::json json;
    json["error"] = e.what();
    ss << json;
    return ss.str();
  }
}

EMSCRIPTEN_BINDINGS(glsl_parser) {
  function("parse_glsl", &parse_glsl);
}