#include <lick/lick.h>
#include <big-lalr/state.h>

using namespace biglr;

FIXTURE(constructs) {
  state_t::item_list_t items;
  items.push_back(item_t::make(
    rule_t::make(reduction_t::make("red1"), {
      token_t::make("a"),
      token_t::make("b")
    }),
    0,
    token_t::make("a")
  ));
  items.push_back(item_t::make(
    rule_t::make(reduction_t::make("red1"), {
      token_t::make("a"),
      token_t::make("b")
    }),
    1,
    token_t::make("a")
  ));
  items.push_back(item_t::make(
    rule_t::make(reduction_t::make("red2"), {
      token_t::make("b"),
      token_t::make("a")
    }),
    0,
    token_t::make("c")
  ));
  auto state = state_t::make(items);
}

FIXTURE(constructs_once) {
  state_t::item_list_t items1;
  items1.push_back(item_t::make(
    rule_t::make(reduction_t::make("red1"), {
      token_t::make("a"),
      token_t::make("b")
    }),
    0,
    token_t::make("a")
  ));
  items1.push_back(item_t::make(
    rule_t::make(reduction_t::make("red1"), {
      token_t::make("a"),
      token_t::make("b")
    }),
    1,
    token_t::make("a")
  ));
  items1.push_back(item_t::make(
    rule_t::make(reduction_t::make("red2"), {
      token_t::make("b"),
      token_t::make("a")
    }),
    0,
    token_t::make("c")
  ));

  // different order
  state_t::item_list_t items2;
  items2.push_back(item_t::make(
    rule_t::make(reduction_t::make("red2"), {
      token_t::make("b"),
      token_t::make("a")
    }),
    0,
    token_t::make("c")
  ));
  items2.push_back(item_t::make(
    rule_t::make(reduction_t::make("red1"), {
      token_t::make("a"),
      token_t::make("b")
    }),
    1,
    token_t::make("a")
  ));
  items2.push_back(item_t::make(
    rule_t::make(reduction_t::make("red1"), {
      token_t::make("a"),
      token_t::make("b")
    }),
    0,
    token_t::make("a")
  ));

  auto state1 = state_t::make(items1);
  auto state2 = state_t::make(items2);
  auto state3 = state_t::make({items1[0], items1[1]});
  EXPECT_EQ(state1, state2);
  EXPECT_NE(state2, state3);
  EXPECT_NE(state1, state3);
}
