#pragma once

#include <iostream>
#include <tuple>
#include "rule.h"

namespace biglr {
  
class item_t {

public:

  using data_t = std::tuple<std::shared_ptr<rule_t>, int, std::shared_ptr<symbol_t>>;

  static std::shared_ptr<item_t> make(
    std::shared_ptr<rule_t> rule,
    int dot,
    std::shared_ptr<symbol_t> peek
  ) {
    data_t data(rule, dot, peek);
    if (auto cached_ptr = store[data].lock()) {
      return cached_ptr;
    }
    auto item = new item_t(data);
    std::shared_ptr<item_t> ptr(item);
    store[data] = ptr;
    return ptr;
  }

  std::shared_ptr<rule_t> get_rule() const {
    return std::get<0>(data);
  }

  int get_dot() const {
    return std::get<1>(data);
  }

  std::shared_ptr<symbol_t> get_peek() const {
    return std::get<2>(data);
  }

  bool is_complete() {
    return size_t(get_dot()) == get_rule()->get_rhs().size();
  }

  std::shared_ptr<item_t> get_next() {
    if (is_complete()) {
      std::shared_ptr<item_t> ptr;
      return ptr;
    }

    return item_t::make(get_rule(), get_dot() + 1, get_peek());
  }

  std::shared_ptr<symbol_t> get_corner() {
    if (is_complete()) {
      std::shared_ptr<symbol_t> ptr;
      return ptr;
    }

    return get_rule()->get_rhs()[get_dot()];
  }

  static void flush() {
    store.clear();
  }

  bool operator==(const item_t &other) const { return data == other.data; }

  bool operator!=(const item_t &other) const { return data != other.data; }

protected:

  data_t data;

  struct store_key_hash_t : public std::unary_function<data_t, std::size_t> {
    std::size_t operator()(const data_t &k) const {
      std::hash<std::shared_ptr<rule_t>> hash_rule;
      std::hash<std::shared_ptr<symbol_t>> hash_symbol;
      std::hash<int> hash_dot;
      size_t result = 0;
      result ^= hash_rule(std::get<0>(k));
      result ^= hash_dot(std::get<1>(k));
      result ^= hash_symbol(std::get<2>(k));
      return result;
    }
  };

  using store_t = std::unordered_map<data_t, std::weak_ptr<item_t>, store_key_hash_t>;

  static store_t store;

  item_t(data_t data_): data(data_) {}

};  // item_t

item_t::store_t item_t::store;

std::ostream &operator<<(std::ostream &strm, const item_t &item) {
  strm << "Item(" << *(item.get_rule()) << " ";
  strm << "dot: " << item.get_dot() << " ";
  strm << "peek: " << item.get_peek() << ")";
  return strm;
}

}   // biglr
