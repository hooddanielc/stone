#include <lick/lick.h>
#include <big-lalr/symbol.h>

using namespace biglr;

FIXTURE(token_constructor) {
  auto token = token_t::make("COOL");
  EXPECT_EQ(token->get_name(), "COOL");
}

FIXTURE(making_tokens_with_same_name) {
  auto token_original = token_t::make("a");
  auto token_copy = token_t::make("a");
  EXPECT_EQ(token_original, token_copy);
}

FIXTURE(reduction_constructor) {
  auto reduction = reduction_t::make("REDUCTION");
  EXPECT_EQ(reduction->get_name(), "REDUCTION");
}

FIXTURE(making_reductions_with_same_name) {
  auto red_original = token_t::make("b");
  auto red_copy = token_t::make("b");
  EXPECT_EQ(red_original, red_copy);
}

FIXTURE(top_constructor) {
  auto top = top_t::make();
  EXPECT_EQ(top->get_name(), "TOP");
}

FIXTURE(making_top_twice) {
  auto top_original = top_t::make();
  auto top_copy = top_t::make();
  EXPECT_EQ(top_original, top_copy);
}

FIXTURE(break_constructor) {
  auto break_ = break_t::make();
  EXPECT_EQ(break_->get_name(), "--");
}

FIXTURE(making_break_twice) {
  auto break_original = break_t::make();
  auto break_copy = break_t::make();
  EXPECT_EQ(break_original, break_copy);
}
