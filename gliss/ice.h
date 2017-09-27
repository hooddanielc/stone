#pragma once

#include "error.h"
#include "glsl-lang.h"

namespace gliss {

/* The dreaded internal compiler error. */
class ice_t final: public error_t {

public:

  using pos_t = glsl::pos_t;

  /* Report the file and line at which we iced. */
  ice_t(const pos_t &pos, const char *file, int line_number): error_t(pos) {
    get_strm() << "internal compiler error";
    end_section();
    get_strm() << file << ", " << line_number;
  }

};  // ice_t

}  // gliss
