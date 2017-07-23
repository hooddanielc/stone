#pragma once

#include <xcb/xcb.h>
#include <xcbxx/connection.h>

namespace xcbxx {

class window_t {

public:

  friend class connection_t;

  void show();

private:

  std::shared_ptr<connection_t> connection;

  xcb_window_t window;

  xcb_void_cookie_t cookie;

  xcb_connection_t *get_connection();

  window_t(
    std::shared_ptr<connection_t> connection_,
    int16_t x,
    int16_t y,
    uint16_t width,
    uint16_t height,
    uint16_t border_width,
    xcb_window_t parent,
    xcb_visualid_t visual,
    uint8_t depth = XCB_COPY_FROM_PARENT,
    uint16_t _class = XCB_WINDOW_CLASS_INPUT_OUTPUT,
    uint32_t value_mask = 0,
    const uint32_t *value_list = nullptr
  ) :
    connection(connection_),
    window(xcb_generate_id(get_connection())),
    cookie(xcb_create_window(
      get_connection(),
      depth,
      window,
      parent,
      x,
      y,
      width,
      height,
      border_width,
      _class,
      visual,
      value_mask,
      value_list
    )) {}

};  // window_t

}   // xcbxx