#pragma once

namespace biglr {

class pos_t final {

public:

  pos_t() noexcept: line_number(1), col_number(1) {}

  void next_col() {
    ++col_number;
  }

  void next_line() {
    ++line_number;
    col_number = 1;
  }

  friend std::ostream &operator<<(std::ostream &strm, const pos_t &that) {
    return strm
        << "line " << that.line_number
        << ", col " << that.col_number;
  }

private:

  int line_number, col_number;

};  // pos_t

}   // biglr
