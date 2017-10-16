#include <lick/lick.h>
#include <iostream>

FIXTURE(test) {
  std::cout << "this is a test" << std::endl;
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  return lick::main(argc, argv);
}
