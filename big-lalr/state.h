#pragma once

#include <vector>
#include <algorithm>
#include <unordered_map>
#include "item.h"

namespace biglr {

class state_t {

public:

  using item_list_t = std::vector<std::shared_ptr<item_t>>;

  item_list_t get_items() const {
    return items;
  }

  static std::shared_ptr<state_t> make(item_list_t items) {
    std::sort(items.begin(), items.end());

    if (auto cached_ptr = store[items].lock()) {
      return cached_ptr;
    }

    auto state = new state_t(items);
    std::shared_ptr<state_t> ptr(state);
    store[items] = ptr;
    return ptr;
  }

protected:

  item_list_t items;

  struct store_key_hash_t : public std::unary_function<item_list_t, std::size_t> {
    std::size_t operator()(const item_list_t &k) const {
      size_t result = 0;
      std::hash<std::shared_ptr<item_t>> hash_item;
      for (auto item: k) {
        result ^= hash_item(item);
      }
      return result;
    }
  };

  using store_t = std::unordered_map<item_list_t, std::weak_ptr<state_t>, store_key_hash_t>;

  static store_t store;

  state_t(item_list_t items_): items(items_) {};

};  // state_t

state_t::store_t state_t::store;

std::ostream &operator<<(std::ostream &strm, const state_t &state) {
  auto items = state.get_items();

  std::sort(items.begin(), items.end(), [](auto a, auto b) {
    if (*(a->get_rule()) < *(b->get_rule())) return true;
    if (a->get_rule() != b->get_rule()) return false;
    if (a->get_dot() < b->get_dot()) return true;
    if (a->get_dot() != b->get_dot()) return false;
    if (*(a->get_peek()) < *(b->get_peek())) return true;
    if (a->get_peek() != b->get_peek()) return false;
    return true;
  });

  strm << "State(" << std::endl;
  for (auto item: items) {
    strm << "  " << item << std::endl;
  }
  strm << ")";
  return strm;
}

std::ostream &operator<<(std::ostream &strm, const state_t *state) {
  strm << *state;
  return strm;
}

}   // biglr