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

    auto output = parser->parse(lexer_t::lex(src)).front();
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

  enum symbol_type_t {
    structure,
    reference,
    function,
    if_stmt,
    do_stmt,
    while_stmt,
    for_stmt
  };

protected:

  int scope;

  parser_t(): scope(0) {}

  void insert_symbol(std::shared_ptr<glsl::ast_t> ast, symbol_type_t type) {
    if (auto token = std::dynamic_pointer_cast<glsl::ast_token_t>(ast)) {
      std::cout << "SCOPE adding " << token->get_token()->get_text() << std::endl;
    } else {
      std::cout << "SCOPE ERROR YOU DIDNT PASS A TOKEN" << std::endl;
    }
  }

  void reduce_symbols(symbol_type_t type) {

  }

  virtual std::shared_ptr<token_t> scan_token(std::shared_ptr<glsl::token_t> token) const override {
    if (token->get_kind() == glsl::token_t::IDENTIFIER) {
      // do a lookup in symbol table
    }
    std::cout << token->get_name() << std::endl;

    return token;
  }

  virtual std::shared_ptr<glsl::ast_t> reduce_by_id(int id, std::vector<std::shared_ptr<glsl::ast_t>> &children) {
    auto reduction = glsl::default_reduce_by_id(id, children);
    if (reduction->get_symbol_id() == glsl::symbol_t::function_definition) {
      std::cout << "SCOPE reduce function def ends a scope" << std::endl;
    }
    if (reduction->get_symbol_id() == glsl::symbol_t::compound_statement) {
      std::cout << "SCOPE reduce compound_statement" << std::endl;
    }
    if (reduction->get_symbol_id() == glsl::symbol_t::iteration_statement) {
      std::cout << "SCOPE reduce iteration_statement" << std::endl;
    }
    if (reduction->get_symbol_id() == glsl::symbol_t::struct_specifier) {
      std::cout << "SCOPE struct adds a typename onto symbol table" << std::endl;
    }
    if (reduction->get_symbol_id() == glsl::symbol_t::single_declaration) {
      if (reduction->get_children().size() > 1) {
        insert_symbol(reduction->get_children()[1], reference);
      }
    }
    if (reduction->get_symbol_id() == glsl::symbol_t::function_prototype) {
      auto function_declarator = reduction->get_children()[0];
      auto function_header = function_declarator->get_children()[0];
      auto function_header_params = function_declarator->get_children()[1];
      insert_symbol(function_header->get_children()[1], function);
    }
    return glsl::default_reduce_by_id(id, children);
  }

};   // parser_t

}   // gliss
