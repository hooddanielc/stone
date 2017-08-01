#pragma once

#include <sstream>
#include <xcb/xcb.h>
#include <xcbxx/graphic-ctx.h>
#include <xcbxx/screen.h>

namespace xcbxx {

class graphic_ctx_t;

class connection_t;

class window_t {

public:

  friend class connection_t;

  friend class screen_t;

  void show();

  void change_attributes(uint32_t value_mask, const uint32_t *value_list);

  void configure_window(uint16_t value_mask, const uint32_t *value_list);

  std::shared_ptr<graphic_ctx_t> make_graphic_ctx(
    uint32_t value_mask,
    const uint32_t *value_list
  );

  virtual ~window_t();

protected:

  std::shared_ptr<connection_t> connection;

  xcb_window_t window;

  xcb_connection_t *get_connection();

  window_t(
    std::shared_ptr<connection_t> connection_,
    xcb_window_t window_
  ): connection(connection_), window(window_) {}

};  // window_t

}   // xcbxx