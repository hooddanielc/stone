#pragma once

#include "token.h"
#include "ast-nodes.h"

namespace gliss {

namespace ast {

/* base class for all ast nodes */
class ast_t {

public:

  using visitor_t = default_visitor_t;

  virtual ~ast_t() = default;

  virtual void accept(const visitor_t &visitor) const = 0;

};  // ast_t

/* an ast node holding a single token */
class ast_token_t {

public:

  token_t token;

  ast_token_t(const token_t &token_): token(token_) {}

};  // ast_token_t

class any_pattern_item_t {

public:

  virtual ~any_pattern_item_t() = default;

  virtual bool is_leaf() = 0;

};

template <typename node_t>
class pattern_item_t: public any_pattern_item_t {

public:

  static std::shared_ptr<any_pattern_item_t> get() {
    static_assert(!std::is_same<node_t, token_t>::value, "must use get(token_t::kind_t)");
    static auto singleton = std::make_shared<pattern_item_t>(false);
    return singleton;
  }

  static std::shared_ptr<any_pattern_item_t> get(const token_t::kind_t &) {
    static_assert(std::is_same<node_t, token_t>::value, "must use get()");
    static auto singleton = std::make_shared<pattern_item_t>(true);
    return singleton;
  }

  virtual bool is_leaf() {
    return leaf;
  }

  pattern_item_t(bool leaf_): leaf(leaf_) {}

private:

  bool leaf;

};  // pattern_item_t

}   // ast

}   // gliss
