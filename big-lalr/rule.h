#pragma once

#include <memory>
#include <vector>
#include <tuple>
#include <functional>
#include "symbol.h"

namespace biglr {

class rule_t {

public:

  using lhs_t = std::shared_ptr<reduction_t>;

  using rhs_t = std::vector<std::shared_ptr<symbol_t>>;

  using data_t = std::tuple<lhs_t, rhs_t>;

  static std::shared_ptr<rule_t> make(lhs_t lhs, rhs_t rhs) {
    data_t data(lhs, rhs);
    if (auto cached_ptr = store[data].lock()) {
      return cached_ptr;
    }
    auto rule = new rule_t(data);
    std::shared_ptr<rule_t> ptr(rule);
    store[data] = ptr;
    return ptr;
  }

  lhs_t get_lhs() const {
    return std::get<0>(data);
  }

  rhs_t get_rhs() const {
    return std::get<1>(data);
  }

  static void flush() {
    store.clear();
  }

protected:

  struct store_key_hash_t : public std::unary_function<data_t, std::size_t> {
    std::size_t operator()(const data_t &k) const {
      std::hash<std::shared_ptr<reduction_t>> hash_reduction;
      std::hash<std::shared_ptr<symbol_t>> hash_symbol;
      size_t result = 0;
      result ^= hash_reduction(std::get<0>(k));
      for (auto rhs: std::get<1>(k)) {
        result ^= hash_symbol(rhs);
      }
      return result;
    }
  };

  using store_t = std::unordered_map<data_t, std::weak_ptr<rule_t>, store_key_hash_t>;

  static store_t store;

  data_t data;

  rule_t(data_t data_): data(data_) {}

};  // rule_t

rule_t::store_t rule_t::store;

std::ostream &operator<<(std::ostream &strm, const rule_t &rule) {
  strm << "Rule(" << rule.get_lhs() << " ->";
  for (std::shared_ptr<symbol_t> symbol: rule.get_rhs()) {
    strm << " " << symbol;
  }
  strm << ")";
  return strm;
}

}   // biglr
