#pragma once

#include <sstream>

namespace cane {

namespace gl {

void throw_gl_err() {
  bool found_errors = false;
  GLenum err;
  std::stringstream ss;

  while ((err = glGetError()) != GL_NO_ERROR) {
    ss << "gl error #" << err << std::endl;
    found_errors = true;
  }

  if (found_errors) {
    throw std::runtime_error(ss.str());
  }
}

}

}
