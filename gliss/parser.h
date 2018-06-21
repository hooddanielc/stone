#pragma once

#include "glsl-lang.h"
#include "lexer.h"
#include "ast.h"

namespace gliss {

class parser_t: public glsl::parser_t {

public:

  parser_t(): global_scope(symbol_table_t::make(std::shared_ptr<glsl::ast_t>(), scope)) {}

  virtual ~parser_t() = default;

  static std::shared_ptr<ast_t> parse_string(const char *src) {
    auto parser = parser_t::make();
    auto output = parser->parse(lexer_t::lex(src)).front();
    return ast_t::make(output);
  }

  static std::shared_ptr<parser_t> make() {
    auto ptr = new parser_t();
    std::shared_ptr<parser_t> result(ptr);
    return result;
  }

  void print_current_state(std::ostream &strm = std::cout) {
    write_states(strm); strm << std::endl;
    write_output(strm); strm << std::endl;
    write_input(strm); strm << std::endl;
    strm << "=================================" << std::endl;
  }

  virtual void throw_unexpected_token() override {
    std::stringstream ss;
    ss << "unexpected token ";
    ss << input.front();
    throw std::runtime_error(ss.str());

    write_states(std::cout); std::cout << std::endl;
    write_output(std::cout); std::cout << std::endl;
    write_input(std::cout); std::cout << std::endl;
    std::cout << "=================================" << std::endl;
  }

  enum symbol_type_t {
    scope,
    structure,
    variable,
    func_header,
    func_param,
    none
  };

  class symbol_table_t {

  public:

    static std::shared_ptr<symbol_table_t> make(std::shared_ptr<glsl::ast_t> node, symbol_type_t kind) {
      auto ptr = new symbol_table_t(node, kind);
      std::shared_ptr<symbol_table_t> result(ptr);
      return result;
    }

    static std::shared_ptr<symbol_table_t> make(std::shared_ptr<glsl::ast_t> node, std::vector<std::shared_ptr<symbol_table_t>> children) {
      auto ptr = new symbol_table_t(node, children);
      std::shared_ptr<symbol_table_t> result(ptr);
      return result;
    }

    symbol_type_t get_kind() {
      return kind;
    }

    std::vector<std::shared_ptr<symbol_table_t>> get_children() {
      return children;
    }

    std::shared_ptr<glsl::ast_t> get_node() {
      return node;
    }

    /* add a child to this scope */
    void add(std::shared_ptr<symbol_table_t> child) {
      children.push_back(child);
    }

    void get_identifiers(std::shared_ptr<glsl::ast_t> parent, std::vector<std::shared_ptr<glsl::ast_t>> &result) {
      for (auto child: parent->get_children()) {
        if (child->get_symbol_id() == glsl::symbol_t::IDENTIFIER) {
          auto found = std::find_if(children.begin(), children.end(), [&](auto item) {
            return item->get_node() == child;
          });
          if (found != children.end()) {
            result.push_back(child);
          }
        }
        get_identifiers(child, result);
      }
    }

    std::vector<std::shared_ptr<glsl::ast_t>> get_identifiers(std::shared_ptr<glsl::ast_t> parent) {
      std::vector<std::shared_ptr<glsl::ast_t>> result;
      get_identifiers(parent, result);
      return result;
    }

    /*
     * reduce identifier's found in the provided ast node. Any reduction
     * that forms a new scope will hide all included declarators
     */
    void reduce(std::shared_ptr<glsl::ast_t> ast) {
      auto filtered = get_identifiers(ast);

      if (filtered.size() > 0) {
        auto range_start = std::find_if(children.begin(), children.end(), [&](auto item) {
          return item->get_node() == filtered.front();
        });
        auto range_end = std::find_if(children.begin(), children.end(), [&](auto item) {
          return item->get_node() == filtered.back();
        });
        assert(std::distance(range_start, range_end) >= 0);
        std::vector<std::shared_ptr<symbol_table_t>> reduced_children(range_start, std::next(range_end));
        children.erase(range_start, std::next(range_end));
        children.insert(range_start, symbol_table_t::make(ast, reduced_children));
      }
    }

  private:

    /* type of symbol */
    symbol_type_t kind;

    /* position in AST */
    std::shared_ptr<glsl::ast_t> node;

    /* if kind is scope, all children in it's scope */
    std::vector<std::shared_ptr<symbol_table_t>> children;

    symbol_table_t(std::shared_ptr<glsl::ast_t> node_, symbol_type_t kind_): kind(kind_), node(node_) {}

    symbol_table_t(std::shared_ptr<glsl::ast_t> node_, std::vector<std::shared_ptr<symbol_table_t>> children_): kind(scope), node(node_), children(children_) {}

  };  // symbol_table_t

  static std::shared_ptr<symbol_table_t> get_symbol_identifier(std::shared_ptr<glsl::ast_t> reduction) {
    std::shared_ptr<symbol_table_t> result;
    if (reduction->get_symbol_id() == glsl::symbol_t::struct_specifier) {
      if (reduction->get_children()[1]->get_symbol_id() == glsl::symbol_t::IDENTIFIER) {
        return symbol_table_t::make(reduction->get_children()[1], structure);
      }
    }
    if (reduction->get_symbol_id() == glsl::symbol_t::single_declaration) {
      if (reduction->get_children().size() > 1) {
        return symbol_table_t::make(reduction->get_children()[1], variable);
      }
    }
    if (reduction->get_symbol_id() == glsl::symbol_t::init_declarator_list) {
      if (reduction->get_children()[0]->get_symbol_id() != glsl::symbol_t::single_declaration) {
        return symbol_table_t::make(reduction->get_children()[2], variable);
      }
    }
    if (reduction->get_symbol_id() == glsl::symbol_t::function_header) {
      return symbol_table_t::make(reduction->get_children()[1], func_header);
    }
    if (reduction->get_symbol_id() == glsl::symbol_t::parameter_declarator) {
      return symbol_table_t::make(reduction->get_children()[1], func_param);
    }
    return result;
  }

protected:

  std::shared_ptr<symbol_table_t> global_scope;

  /*
   * glsl requires a scanner to identify if an identifier is a TYPE_NAME or a regular
   * IDENTIFIER. If a token is incorrectly identified as not being a TYPE_NAME or
   * an IDENTIFIER, this will throw off the grammar and cause a compiler error
   * during parsing. Also all type specifiers that occur before a LEFT_PAREN are
   * rewritten as IDENTIFIER */
  virtual std::shared_ptr<token_t> scan_token(std::shared_ptr<glsl::token_t> token) const override {
    if (is_global_type(token->get_kind())) {
      if (input.size() > 1 && input[1]->get_kind() == glsl::token_t::LEFT_PAREN) {
        auto text = token->get_text();
        return glsl::token_t::make(token->get_pos(), token_t::IDENTIFIER, std::move(text));
      }
    }

    if (token->get_kind() == glsl::token_t::IDENTIFIER) {
      if (output.size() && output.back()->get_symbol_id() == glsl::symbol_t::DOT) {
        auto text = token->get_text();
        return glsl::token_t::make(token->get_pos(), token_t::FIELD_SELECTION, std::move(text));
      }
      if (input.size() > 1 && input[1]->get_kind() == glsl::token_t::IDENTIFIER) {
        auto text = token->get_text();
        return glsl::token_t::make(token->get_pos(), token_t::TYPE_NAME, std::move(text));
      }
    }
    return token;
  }

  virtual std::shared_ptr<glsl::ast_t> reduce_by_id(int id, std::vector<std::shared_ptr<glsl::ast_t>> &children) override {
    auto reduction = glsl::default_reduce_by_id(id, children);
    if (reduction->get_symbol_id() == glsl::symbol_t::function_definition) {
      global_scope->reduce(reduction);
    }
    if (reduction->get_symbol_id() == glsl::symbol_t::compound_statement) {
      global_scope->reduce(reduction);
    }
    if (reduction->get_symbol_id() == glsl::symbol_t::iteration_statement) {
      global_scope->reduce(reduction);
    }
    if (auto symbol_identifier = parser_t::get_symbol_identifier(reduction)) {
      global_scope->add(symbol_identifier);
    }
    return glsl::default_reduce_by_id(id, children);
  }

};   // parser_t

}   // gliss
