#pragma once

#include "token.h"
#include "ast-nodes.h"

namespace gliss {

namespace ast {

class ast_t {

public:

  using visitor_t = default_visitor_t;

  virtual ~ast_t() = default;

  virtual void accept(const visitor_t &visitor) const = 0;

};  // ast_t

class any_pattern_item_t {};

template <typename node_t>
class pattern_item_t: public any_pattern_item_t {

public:

  static any_pattern_item_t get() {
    static_assert(!std::is_same<node_t, token_t>::value, "must use get(token_t::kind_t)");
    static pattern_item_t<node_t> singleton;
    return singleton;
  }

  static any_pattern_item_t get(const token_t::kind_t &) {
    static_assert(std::is_same<node_t, token_t>::value, "must use get()");
    static pattern_item_t<node_t> singleton;
    return singleton;
  }

};

}   // ast

}   // gliss


// expr -> primary ('+' expr)?

// expr -> primary expr_tail
// expr_tail -> '+' expr
// expr_tail -> '-' expr
// no_expr_tail -> nil
// primary -> INT

// ast.cc

// namespace ast {
//   class primary_t;
//   class expr_tail_t;
//   class no_expr_tail_t;
//   class expr_t;
// }  // ast

// class ast_t {
// public:

//   DELETE_COPY_AND_MOVE(ast_t)

//   struct visitor_t {
//     virtual ~visitor_t() = default;
//     virtual void operator()(const ast::primary_t *) const = 0;
//     virtual void operator()(const ast::expr_tail_t *) const = 0;
//     virtual void operator()(const ast::no_expr_tail_t *) const = 0;
//     virtual void operator()(const ast::expr_t *) const = 0;
//   };  // ast_t::visitor_t

//   virtual ~ast_t() = default;

//   virtual void accept(const visitor_t &visitor) const = 0;

// protected:

//   ast_t() = default;

// };  // ast_t

// namespace ast {

// class primary_t final
//     : public ast_t {
// public:

//   primary_t(const token_t *token_)
//       : token(token_) {}

//   virtual void accept(const visitor_t &visitor) const override {
//     visitor(this);
//   }

//   const token_t *token;

// };  // primary_t

// class expr_tail final
//     : public ast_t {
// public:

//   expr_tail(const token_t *token_, std::unique_ptr<ast_t> &&expr_)
//       : token(token_), expr(std::move(expr_)) {}

//   virtual void accept(const visitor_t &visitor) const override {
//     visitor(this);
//   }

//   const token_t *token;

//   std::unique_ptr<ast_t> expr;

// };  // expr_tail_t

// class no_expr_tail final
//     : public ast_t {
// public:

//   no_expr_tail() {}

//   virtual void accept(const visitor_t &visitor) const override {
//     visitor(this);
//   }

// };  // expr_tail_t

// class expr final
//     : public ast_t {
// public:

//   no_expr_tail(
//       std::unique_ptr<ast_t> &&primary_,
//       std::unique_ptr<ast_t> &&expr_tail_)
//       : primary(std::move(primary_)), expr_tail(std::move(expr_tail_)) {}

//   virtual void accept(const visitor_t &visitor) const override {
//     visitor(this);
//   }

//   std::unique_ptr<ast_t> primary, expr_tail;

// };  // expr_tail_t

// }  // ast

// // pretty_print.cc

// std::ostream &operator<<(std::ostream &strm, const ast_t &ast) {
//   class pretty_printer_t final
//       : public ast_t::visitor_t {
//   public:

//     pretty_printer(std::ostream &strm_)
//         : strm(strm_) {}

//     virtual void operator()(const ast::primary_t *primary) const override {
//       strm << "primary(" << primary->token->get_lexeme() << ')';
//     }

//     virtual void operator()(const ast::expr_tail_t *expr_tail) const override {
//       strm << "expr_tail(" << expr_tail->token->get_loc() << ", " << *expr_tail->expr << ')';
//     }

//     virtual void operator()(const ast::no_expr_tail_t *) const override {
//       strm << "no_expr_tail()";
//     }

//     virtual void operator()(const ast::expr_t *expr) const override {
//       strm << "expr(" << *expr->primary << ", " << *expr->expr_tail << ')';
//     }

//   private:

//     std::ostream &strm;

//   };  // pretty_printer_t
//   ast.accept(pretty_printer_t { strm });
//   return strm;
// }

// // grammar.cc

// std::unique_ptr<ast_t> make_expr(cursor_t &cursor) {
//   return std::make_unique<ast::expr_t>(
//     make_primary(cursor),
//     make_expr_tail(cursor)
//   );
// }

// std::unique_ptr<ast_t> make_expr_tail(cursor_t &cursor) {
//   auto *token = cursor.try_match({ token_t::plus, token_t::minus });
//   if (!token) {
//     return std::make_unique<ast::no_expr_tail_t>();
//   }
//   return std::make_unique<ast::expr_tail_t>(
//     token,
//     make_expr(cursor)
//   );
// }

// std::unique_ptr<ast_t> make_primary(cursor_t &cursor) {
//   auto *token = cursor.match(token_t::int_);
//   return std::make_unique<ast::primary_t>(token);
// }