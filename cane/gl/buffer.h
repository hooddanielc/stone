#pragma once

#include "util.h"

namespace cane {

namespace gl {

class buffer_t {

private:

  unsigned int id;

  GLenum type;

  GLenum usage;

public:

  // delete copy and move
  buffer_t(buffer_t const&) = delete;
  buffer_t& operator=(buffer_t const&) = delete;

  buffer_t(GLenum type_, GLenum usage_): type(type_), usage(usage_) {
    glGenBuffers(1, &id);
    throw_gl_err();
  }

  unsigned int get_id() {
    return id;
  }

  void set(GLsizeiptr size, const GLvoid *data) {
    glBindBuffer(type, id);
    glBufferData(type, size, data, usage);
    throw_gl_err();
  }

};

}

}