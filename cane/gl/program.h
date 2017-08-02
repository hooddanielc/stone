#pragma once

#include <vector>
#include <memory>
#include "shader.h"
#include "util.h"

namespace cane {

namespace gl {

class program_t {

private:

  std::vector<std::shared_ptr<shader_t>> shaders;

public:

  // delete copy and move
  program_t(program_t const&) = delete;
  program_t& operator=(program_t const&) = delete;

  unsigned int id;

  program_t() {
    id = glCreateProgram();
    throw_gl_err();
  }

  unsigned int get_id() {
    return id;
  }

  void attach(std::shared_ptr<shader_t> shader) {
    glAttachShader(id, shader->get_id());
    shader->delete_id();
    throw_gl_err();
  }

  void link() {
    glLinkProgram(id);
    int success;
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) {
      char info[512];
      glGetProgramInfoLog(id, 512, nullptr, info);
      std::stringstream ss;
      ss << "shader compilation failed" << std::endl << std::endl;
      ss << info << std::endl;
      throw std::runtime_error(ss.str());
    }
    throw_gl_err();
  }

  void use() {
    glUseProgram(id);
  }

  ~program_t() {
    glDeleteProgram(id);
    throw_gl_err();
  }

};

}

}
