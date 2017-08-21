#include <iostream>
#include <lick/lick.h>
#include <gliss/ast.h>
#include <gliss/ast-nodes/all.h>

using namespace gliss;
using namespace ast;

class fixture_node_t;

class fixture_visitor_t: public empty_visitor_t {

public:

  mutable bool visited;

  fixture_visitor_t(): visited(false) {}
  virtual ~fixture_visitor_t() = default;

  virtual void operator()(const fixture_node_t *) const {
    visited = true;
  }

};  // pretty_printer_t

class fixture_node_t: public ast_t {

public:

  static const std::vector<std::vector<std::shared_ptr<any_pattern_item_t>>> patterns;

  fixture_node_t(
    const token_t &,
    const token_t &
  ) {}

  virtual void accept(const default_visitor_t &) const override {}

  void accept(const fixture_visitor_t &visitor) const {
    visitor(this);
  }

};  // fixture_node_t

const std::vector<std::vector<std::shared_ptr<any_pattern_item_t>>> fixture_node_t::patterns = {
  {
    pattern_item_t<token_t>::get(token_t::left_bracket),
    pattern_item_t<token_t>::get(token_t::right_bracket)
  }
};

FIXTURE(visits) {
  pos_t pos;
  token_t left(pos, token_t::left_bracket);
  token_t right(pos, token_t::right_bracket);
  fixture_node_t node(left, right);
  fixture_visitor_t visitor;
  EXPECT_EQ(visitor.visited, false);
  node.accept(visitor);
  EXPECT_EQ(visitor.visited, true);
}
