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

  std::vector<std::shared_ptr<symbol_t>> get_beta(int dot) {
    std::vector<std::shared_ptr<symbol_t>> result;
    for (size_t i = dot + 1; i < get_rhs().size(); ++i) {
      result.push_back(get_rhs()[i]);
    }
    return result;
  }

  static void flush() {
    store.clear();
  }

  static std::vector<std::shared_ptr<rule_t>> get_store() {
    std::vector<std::shared_ptr<rule_t>> rules;
    for (auto it = store.begin(); it != store.end(); ++it) {
      if (auto ptr = it->second.lock()) {
        rules.push_back(ptr);
      }
    }
    return rules;
  }

  virtual bool operator<(const rule_t &other) {
    if (*(get_lhs()) < *(other.get_lhs())) {
      return true;
    } else if (*(get_lhs()) > *(other.get_lhs())) {
      return false;
    }

    size_t size_a = get_rhs().size();
    size_t size_b = other.get_rhs().size();
    size_t len = size_a < size_b ? size_b : size_a;

    for (size_t i = 0; i < len; ++i) {
      if (i < size_a && i < size_b) {
        if (*(get_rhs()[i]) < *(other.get_rhs()[i])) {
          return true;
        } else if (*(get_rhs()[i]) > *(other.get_rhs()[i])) {
          return false;
        }
      } else {
        return size_a < size_b;
      }
    }

    return false;
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
