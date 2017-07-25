#pragma once

#include <map>
#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <xcb/xcb.h>
#include <xcb/xcb_aux.h>
#include <xcbxx/screen.h>
#include <xcbxx/window.h>
#include <xcbxx/graphic-ctx.h>
#include <xcbxx/events.h>

namespace xcbxx {

class window_t;

class connection_t {

public:

  friend class screen_t;

  friend class window_t;

  friend class graphic_ctx_t;

  using cb_event_t = std::function<void(std::shared_ptr<event_t>)>;

  using cb_map_request_event_t = std::function<void(std::shared_ptr<map_request_event_t>)>;

  std::vector<cb_event_t> cb_events;

  std::vector<cb_map_request_event_t> cb_map_request_events;

  void on(const cb_event_t &fn);

  void on(const cb_map_request_event_t &fn);

  static std::shared_ptr<connection_t> make(const char *display = nullptr, int *screen_num = new int());

  ~connection_t();

  const char *get_display();

  int *get_screen_num();

  int get_screen_count();

  void pause();

  int flush();

  void aux_sync();

  void throw_bad_cookie(const std::string &name, xcb_void_cookie_t cookie);

  xcb_generic_event_t *wait_for_event();

  xcb_generic_event_t *poll_for_event();

  std::shared_ptr<screen_t> get_screen(int *num = nullptr);

  std::shared_ptr<window_t> create_window(
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
  );

private:

  std::weak_ptr<connection_t> weak_ref;

  xcb_connection_t *connection;

  const char *display;

  int *screen_num;

  connection_t(
    xcb_connection_t *connection_,
    const char *display_,
    int *screen_num_
  ) :
    connection(connection_),
    display(display_),
    screen_num(screen_num_) {};

};  // connection_t

}   // xcbxx
