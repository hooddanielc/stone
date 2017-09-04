#include <lick/lick.h>
#include <big-lalr/item.h>

using namespace biglr;

FIXTURE(item_construction) {
  auto lhs = reduction_t::make("REDUCTION");
  rule_t::rhs_t rhs;
  auto a = token_t::make("a");
  auto b = token_t::make("b");
  rhs.push_back(a);
  rhs.push_back(b);
  auto rule = rule_t::make(lhs, rhs);
  auto item1 = item_t::make(rule, 0, a);
  auto item2 = item_t::make(rule, 1, b);
  EXPECT_EQ(item1->get_rule(), rule);
  EXPECT_EQ(item1->get_dot(), 0);
  EXPECT_EQ(item1->get_peek(), a);
  EXPECT_NE(*item1, *item2);
  EXPECT_EQ(*item1, *item1);
}

FIXTURE(constructs_only_once) {
  auto item1 = item_t::make(
    rule_t::make(reduction_t::make("red"), {
      token_t::make("a"),
      token_t::make("b")
    }),
    0,
    token_t::make("a")
  );
  auto item2 = item_t::make(
    rule_t::make(reduction_t::make("red"), {
      token_t::make("a"),
      token_t::make("b")
    }),
    0,
    token_t::make("a")
  );
  auto item3 = item_t::make(
    rule_t::make(reduction_t::make("red"), {
      token_t::make("b"),
      token_t::make("a")
    }),
    0,
    token_t::make("a")
  );
  auto item4 = item_t::make(
    rule_t::make(reduction_t::make("red"), {
      token_t::make("a"),
      token_t::make("b")
    }),
    1,
    token_t::make("a")
  );
  auto item5 = item_t::make(
    rule_t::make(reduction_t::make("der"), {
      token_t::make("a"),
      token_t::make("b")
    }),
    0,
    token_t::make("a")
  );
  EXPECT_EQ(item1, item2);
  EXPECT_NE(item2, item3);
  EXPECT_NE(item2, item4);
  EXPECT_NE(item2, item5);
}

FIXTURE(is_complete) {
  auto item1 = item_t::make(
    rule_t::make(reduction_t::make("der"), {
      token_t::make("a"),
      token_t::make("b")
    }),
    1,
    token_t::make("a")
  );
  auto item2 = item_t::make(
    rule_t::make(reduction_t::make("der"), {
      token_t::make("a"),
      token_t::make("b")
    }),
    2,
    token_t::make("a")
  );
  EXPECT_FALSE(item1->is_complete());
  EXPECT_TRUE(item2->is_complete());
}

FIXTURE(get_corner) {
  auto item1 = item_t::make(
    rule_t::make(reduction_t::make("der"), {
      token_t::make("a"),
      token_t::make("b")
    }),
    1,
    token_t::make("a")
  );
  auto item2 = item_t::make(
    rule_t::make(reduction_t::make("der"), {
      token_t::make("a"),
      token_t::make("b")
    }),
    0,
    token_t::make("a")
  );
  auto item3 = item_t::make(
    rule_t::make(reduction_t::make("der"), {
      token_t::make("a"),
      token_t::make("b")
    }),
    2,
    token_t::make("a")
  );
  EXPECT_EQ(item1->get_corner(), token_t::make("b"));
  EXPECT_EQ(item2->get_corner(), token_t::make("a"));
  EXPECT_FALSE(item3->get_corner());
}

FIXTURE(get_next) {
  auto item1 = item_t::make(
    rule_t::make(reduction_t::make("der"), {
      token_t::make("a"),
      token_t::make("b")
    }),
    0,
    token_t::make("a")
  );
  auto item2 = item1->get_next();
  auto item3 = item2->get_next();
  auto item4 = item3->get_next();

  auto item2_expected = item_t::make(
    rule_t::make(reduction_t::make("der"), {
      token_t::make("a"),
      token_t::make("b")
    }),
    1,
    token_t::make("a")
  );

  auto item3_expected = item_t::make(
    rule_t::make(reduction_t::make("der"), {
      token_t::make("a"),
      token_t::make("b")
    }),
    2,
    token_t::make("a")
  );

  EXPECT_EQ(item2, item2_expected);
  EXPECT_EQ(item3, item3_expected);
  EXPECT_FALSE(item4);
}
