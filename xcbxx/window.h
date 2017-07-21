#pragma once

#include <xcbxx/connection.h>

namespace xcbxx {
  
class window_t {

public:

  friend connection_t;

private:

  // TODO
  window_t(std::shared_ptr<connection_t> connection, int *screen_num = nullptr);

};  // window_t

}   // xcbxx