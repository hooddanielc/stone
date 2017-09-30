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
    variable,
    function,
    if_stmt,
    do_stmt,
    while_stmt,
    for_stmt
  };

protected:

  int scope;

  parser_t(): scope(0) {}

  void insert_symbol(const std::string &name, symbol_type_t type) {

  }

  void reduce_symbols(symbol_type_t type) {

  }

  bool is_while_end() const {
    auto end = glsl::parser_t::input.end();
    auto begin = glsl::parser_t::input.begin() + 1;
    assert(glsl::parser_t::input.front()->get_kind() == token_t::WHILE);
    assert((*begin)->get_kind() == token_t::LEFT_PAREN);
    int test_scope = 0;

    for (auto it = begin; it != end; ++it) {
      auto token = (*it);
      if (token->get_kind() == token_t::LEFT_PAREN) test_scope += 1;
      if (token->get_kind() == token_t::RIGHT_PAREN) test_scope -= 1;
      if (test_scope > 0) continue;

      if (test_scope == 0 && std::next(it) != end) {
        auto term = *(std::next(it));
        if (term->get_kind() == token_t::SEMICOLON) {
          return true;
        }
        return false;
      }
    }

    return false;
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
      std::cout << "SCOPE add declaration" << std::endl;
    }
    if (reduction->get_symbol_id() == glsl::symbol_t::function_prototype) {
      std::cout << "SCOPE add function declaration to symbol table" << std::endl;
    }
    return glsl::default_reduce_by_id(id, children);
  }

};   // parser_t

}   // gliss
