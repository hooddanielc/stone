#pragma once

#include "glsl-lang.h"
#include "lexer.h"

namespace gliss {

class parser_t {

public:

  static std::shared_ptr<glsl::ast_t> parse_string(const char *src) {
    auto parser = glsl::parser_t::make();
    return parser->parse(lexer_t::lex(src)).front();
  }

};   // parser_t

}   // gliss
