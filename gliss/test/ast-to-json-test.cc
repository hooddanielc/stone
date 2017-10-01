#include <iostream>
#include <lick/lick.h>
#include <gliss/parser.h>
#include <gliss/pretty-print.h>
#include <gliss/util.h>

using namespace gliss;

std::string get_src(const std::string &path) {
  return get_file_contents(get_project_path(path));
}

FIXTURE(robot_skin) {
  auto str = get_src("gliss/test/fixtures/animated_robot_skin.glsl");
  auto output = parser_t::parse_string(str.c_str());
  auto json = output->to_json();
  EXPECT_EQ(json["name"], "translation_unit");
}

FIXTURE(bees_eye_view) {
  auto str = get_src("gliss/test/fixtures/bees_eye_view.glsl");
  auto output = parser_t::parse_string(str.c_str());
  auto json = output->to_json();
  EXPECT_EQ(json["name"], "translation_unit");
}

FIXTURE(blinking_light) {
  auto str = get_src("gliss/test/fixtures/blinking_light.glsl");
  auto output = parser_t::parse_string(str.c_str());
  auto json = output->to_json();
  EXPECT_EQ(json["name"], "translation_unit");
}

FIXTURE(creeper_skin) {
  auto str = get_src("gliss/test/fixtures/creeper_skin.glsl");
  auto output = parser_t::parse_string(str.c_str());
  auto json = output->to_json();
  EXPECT_EQ(json["name"], "translation_unit");
}

FIXTURE(inner_space) {
  auto str = get_src("gliss/test/fixtures/inner_space.glsl");
  auto output = parser_t::parse_string(str.c_str());
  auto json = output->to_json();
  EXPECT_EQ(json["name"], "translation_unit");
}

FIXTURE(noise_sweep) {
  auto str = get_src("gliss/test/fixtures/noise_sweep.glsl");
  auto output = parser_t::parse_string(str.c_str());
  auto json = output->to_json();
  EXPECT_EQ(json["name"], "translation_unit");
}

FIXTURE(ska_triangles) {
  auto str = get_src("gliss/test/fixtures/ska_triangles.glsl");
  auto output = parser_t::parse_string(str.c_str());
  auto json = output->to_json();
  EXPECT_EQ(json["name"], "translation_unit");
}

FIXTURE(space_without_time) {
  auto str = get_src("gliss/test/fixtures/space_without_time.glsl");
  auto output = parser_t::parse_string(str.c_str());
  auto json = output->to_json();
  EXPECT_EQ(json["name"], "translation_unit");
}
