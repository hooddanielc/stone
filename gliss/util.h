#pragma once

#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <memory>

namespace gliss {

#define PASTE(name) PASTE_2(name)
#define PASTE_2(name) #name

inline std::string get_src_root() noexcept {
  return PASTE(IB_SRC_ROOT);
}

inline std::string get_project_path(const std::string &relative) noexcept {
  std::stringstream ss;
  ss << get_src_root();
  if (relative.at(0) != '/') {
    ss << "/";
  }
  ss << relative;
  return ss.str();
}

inline std::string get_out_root() noexcept {
  return PASTE(IB_OUT_ROOT);
}

// Ok, magic time over.  Get back to work.
#undef PASTE_2
#undef PASTE

/* quick and dirty read file method */
inline const std::string get_file_contents(const std::string &path) {
  std::ifstream t(path.c_str());

  if (!t.good()) {
    std::stringstream ss;
    ss << "file doesn't exist: " << path;
    throw std::runtime_error(ss.str());
  }

  std::string str;
  t.seekg(0, std::ios::end);
  str.reserve(t.tellg());
  t.seekg(0, std::ios::beg);
  str.assign((std::istreambuf_iterator<char>(t)),
              std::istreambuf_iterator<char>());
  return str;
}

/* quick and dirty write file method */
inline void write_file_contents(const std::string &path, const std::string &src) {
  std::ofstream ofs(path.c_str(), std::ofstream::out);
  if (!ofs.good()) {
    std::stringstream ss;
    ss << "error opening file for write: " << path;
    throw std::runtime_error(ss.str());
  }
  ofs << src;
  ofs.close();
}

/* check if a file exists */
inline bool file_exists(const std::string &path) {
  std::ifstream f(path.c_str());
  auto result = f.good();
  f.close();
  return result;
}

/* get a random string */
std::string get_random_str(const int len) {
  std::string result;
  static const char alphanum[] =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

  for (int i = 0; i < len; ++i) {
    result += alphanum[rand() % (sizeof(alphanum) - 1)];
  }

  return result;
}

/* get a random file path */
std::string get_tmp_path(const std::string &prefix = "tmp-file-", const std::string &ext = "", const int len = 10) {
  std::string result;

  do {
    result = "/tmp/";
    result += prefix;
    result += get_random_str(len);
    result += ext;
  } while(file_exists(result));

  return result;
}

}   // gliss
