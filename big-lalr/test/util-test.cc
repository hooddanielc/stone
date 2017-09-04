#include <cstdlib>
#include <iostream>
#include <lick/lick.h>
#include <big-lalr/util.h>

using namespace biglr;

FIXTURE(read_a_file) {
  std::string pwd(std::getenv("PWD"));
  std::string path = pwd + "/big-lalr/test/fixtures/pets.tfr";
  auto str = get_file_contents(path);
  EXPECT_EQ(str.size(), size_t(133));
}
