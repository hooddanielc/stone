#include <iostream>
#include <lick/lick.h>
#include <big-lalr/rule.h>

using namespace biglr;

FIXTURE(rule_consructor) {
  auto lhs = reduction_t::make("REDUCTION");
  rule_t::rhs_t rhs;
  rhs.push_back(token_t::make("a"));
  rhs.push_back(token_t::make("b"));
  auto rule = rule_t::make(lhs, rhs);

  auto lhs_test = rule->get_lhs();
  auto rhs_test = rule->get_rhs();
  EXPECT_EQ(lhs, lhs_test);
  EXPECT_EQ(rhs_test.size(), size_t(2));
  EXPECT_EQ(rhs_test[0], rhs[0]);
  EXPECT_EQ(rhs_test[1], rhs[1]);
}

FIXTURE(constructs_only_once) {
  auto rule1 = rule_t::make(reduction_t::make("REDUCTION"), {
    token_t::make("a"),
    token_t::make("b")
  });

  auto rule2 = rule_t::make(reduction_t::make("REDUCTION"), {
    token_t::make("a"),
    token_t::make("b")
  });

  auto rule3 = rule_t::make(reduction_t::make("REDUCTION"), {
    token_t::make("b"),
    token_t::make("a")
  });

  EXPECT_EQ(rule1, rule2);
  EXPECT_NE(rule2, rule3);
}
