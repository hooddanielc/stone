#pragma once

namespace gliss {

 /* The base of all kinds of expressions. */
class expr_t {

  public:

  /* Do-little. */
  virtual ~expr_t() {}

  /* Override to pretty-print the expression as source script. */
  // virtual void pretty_print(std::ostream &strm) const = 0;

};  // expr_t

}   // gliss