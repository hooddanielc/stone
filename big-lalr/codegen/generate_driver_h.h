#pragma once

#include <sstream>
#include <memory>
#include <map>
#include "../symbol.h"
#include "../action.h"

namespace biglr {

inline std::string generate_driver_h() {
  ss << R"(

struct parser_t {

};

};  // transition
)";

  return ss.str();
}

}   // biglr