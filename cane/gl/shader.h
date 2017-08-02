#pragma once

#include <string>
#include <sstream>
#include "util.h"

namespace cane {

namespace gl {

class shader_t {

private:

  unsigned int id;

  GLenum type;

public:

  // delete copy and move
  shader_t(shader_t const&) = delete;
  shader_t& operator=(shader_t const&) = delete;

  shader_t(GLenum type_): type(type_) {
    id = glCreateShader(type);
    throw_gl_err();
  }

  void set_src(const std::string &src) {
    auto *c_str = src.c_str();
    glShaderSource(id, 1, &c_str, nullptr);
    throw_gl_err();
  }

  void compile() {
    glCompileShader(id);
    int success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success) {
      char info[512];
      glGetShaderInfoLog(id, 512, nullptr, info);
      std::stringstream ss;
      ss << "shader compilation failed" << std::endl << std::endl;
      ss << std::string(info) << std::endl;
      throw std::runtime_error(ss.str());
    }
    throw_gl_err();
  }

  unsigned int get_id() {
    return id;
  }

  bool is_deleted() {
    GLint deleted = 0;
    glGetShaderiv(id, GL_DELETE_STATUS, &deleted);
    return !!deleted;
  }

  void delete_id() {
    if (!is_deleted()) {
      glDeleteShader(id);
    }
  }

  ~shader_t() {
    delete_id();
  }

};  // shader_t

}

}