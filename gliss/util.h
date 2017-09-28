#pragma once

namespace gliss {

  auto output = parser_t::parse_string(R"(
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aNormal;
    out vec3 FragPos;
    out vec3 Normal;
    in vec3 FragPos;
    uniform mat4 viewMatrix, projMatrix;

    in vec4 position;
    in vec3 color;
    out vec3 Color;

    struct Light {
      vec3 eyePosOrDir;
      bool isDirectional;
      vec3 intensity;
      float attenuation;
    } variableName;

    int ok = 1;

    void main() {
      Color = color;
      gl_Position = projMatrix * viewMatrix * position;
    }
  )");

  output->to_json();

};
