#pragma once

#include <fstream>

namespace biglr {

const std::string get_file_contents(const std::string &path) {
  std::ifstream t(path.c_str());
  std::string str;
  t.seekg(0, std::ios::end);   
  str.reserve(t.tellg());
  t.seekg(0, std::ios::beg);
  str.assign((std::istreambuf_iterator<char>(t)),
              std::istreambuf_iterator<char>());
  return str;
}

}   // biglr
