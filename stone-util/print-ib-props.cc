#include <iostream>
#include <sstream>

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

#undef PASTE_2
#undef PASTE

int main(int, char*[]) {
  std::cout << "IB_SRC_ROOT = '" << get_src_root() << "'" << std::endl;
  std::cout << "IB_OUT_ROOT = '" << get_out_root() << "'" << std::endl; 
  return 0;
}
