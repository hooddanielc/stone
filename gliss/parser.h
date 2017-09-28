#pragma once

#include "glsl-lang.h"
#include "lexer.h"

namespace gliss {

class parser_t: public glsl::parser_t {

public:

  using struct_rule = glsl::struct_specifier_from_STRUCT_IDENTIFIER_LEFT_BRACE_struct_declaration_list_RIGHT_BRACE_t;

  using statement_rule = glsl::statement_list_from_statement_t;

  using statement_list_rule = glsl::statement_list_from_statement_list_statement_t;

  static std::shared_ptr<glsl::ast_t> parse_string(const char *src) {
    auto parser = parser_t::make();

    parser->on_reduce(struct_rule::rule_id, [](auto reduction) {
      std::cout << "I just reduced " << reduction->get_name() << std::endl;
    });
    parser->on_reduce(statement_rule::rule_id, [](auto reduction) {
      std::cout << "I just reduced" << reduction->get_name() << std::endl;
    });
    parser->on_reduce(statement_list_rule::rule_id, [](auto reduction) {
      std::cout << "I just reduced" << reduction->get_name() << std::endl;
    });
    parser->push_symbol_table();
    auto output = parser->parse(lexer_t::lex(src)).front();
    parser->pop_symbol_table();
    return output;
  }

  static std::shared_ptr<parser_t> make() {
    auto ptr = new parser_t();
    std::shared_ptr<parser_t> result(ptr);
    return result;
  }

protected:

  void push_symbol_table() {

  }

  void pop_symbol_table() {

  }

  virtual std::shared_ptr<token_t> scan_token(std::shared_ptr<glsl::token_t> token) const override {
    if (token->get_kind() == glsl::token_t::IDENTIFIER) {
      std::cout << "found an identifier token" << std::endl;
    }
    std::cout << token->get_name() << std::endl;
    return token;
  }

};   // parser_t

}   // gliss
