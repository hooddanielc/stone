#pragma once

#include "glsl-lang.h"
#include "lexer.h"
#include "ast.h"

namespace gliss {

class parser_t: public glsl::parser_t {

public:

  using statement_one = glsl::statement_from_compound_statement_t;

  using statement_two = glsl::statement_from_simple_statement_t;

  using struct_rule = glsl::struct_specifier_from_STRUCT_IDENTIFIER_LEFT_BRACE_struct_declaration_list_RIGHT_BRACE_t;

  using statement_rule = glsl::statement_list_from_statement_t;

  using statement_list_rule = glsl::statement_list_from_statement_list_statement_t;

  static std::shared_ptr<ast_t> parse_string(const char *src) {
    auto parser = parser_t::make();

    parser->on_shift([&](auto a) {
      parser->write_states(std::cout); std::cout << std::endl;
      parser->write_output(std::cout); std::cout << std::endl;
      parser->write_input(std::cout); std::cout << std::endl;
      std::cout << "=================================" << std::endl;
    });

    // declare variable in current scope
    std::vector<int> init_declarator_list_ids({
      glsl::init_declarator_list_from_single_declaration_t::rule_id,
      glsl::init_declarator_list_from_init_declarator_list_COMMA_IDENTIFIER_t::rule_id,
      glsl::init_declarator_list_from_init_declarator_list_COMMA_IDENTIFIER_array_specifier_t::rule_id,
      glsl::init_declarator_list_from_init_declarator_list_COMMA_IDENTIFIER_array_specifier_EQUAL_initializer_t::rule_id,
      glsl::init_declarator_list_from_init_declarator_list_COMMA_IDENTIFIER_EQUAL_initializer_t::rule_id
    });

    for (auto id: init_declarator_list_ids) {
      parser->on_reduce(id, [](auto reduction) {
        //std::cout << "I just reduced " << reduction->get_name() << std::endl;
        //std::cout << ast_t::make(reduction)->to_json() << std::endl;
      });
    }

    // function header inserts a new scope
    parser->on_reduce(glsl::function_header_from_fully_specified_type_IDENTIFIER_LEFT_PAREN_t::rule_id, [](auto reduction) {

    });

    // function definition closes scope
    parser->on_reduce(glsl::function_definition_from_function_prototype_compound_statement_no_new_scope_t::rule_id, [](auto reduction) {

    });

    // function declaration closes function scope
    parser->on_reduce(glsl::declaration_from_function_prototype_SEMICOLON_t::rule_id, [](auto reduction) {

    });

    parser->push_symbol_table();
    auto output = parser->parse(lexer_t::lex(src)).front();
    parser->pop_symbol_table();
    return ast_t::make(output);
  }

  static std::shared_ptr<parser_t> make() {
    auto ptr = new parser_t();
    std::shared_ptr<parser_t> result(ptr);
    return result;
  }

  virtual void throw_unexpected_token() const override {
    std::stringstream ss;
    ss << "unexpected token ";
    ss << input.front();
    throw std::runtime_error(ss.str());
  }

protected:

  void push_symbol_table() {

  }

  void pop_symbol_table() {

  }

  virtual std::shared_ptr<token_t> scan_token(std::shared_ptr<glsl::token_t> token) const override {
    if (token->get_kind() == glsl::token_t::IDENTIFIER) {
      //std::cout << "found an identifier token" << std::endl;
    }
    std::cout << token->get_name() << std::endl;

    return token;
  }

};   // parser_t

}   // gliss
