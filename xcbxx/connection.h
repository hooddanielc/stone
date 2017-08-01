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
#include <X11/Xlib.h>
#include <X11/Xlib-xcb.h>
#include <xcbxx/screen.h>
#include <xcbxx/window.h>
#include <xcbxx/graphic-ctx.h>
#include <xcbxx/events.h>
#include <xcbxx/glx-window.h>

namespace xcbxx {

class window_t;

class connection_t {

public:

  friend class glx_window_t;

  friend class screen_t;

  friend class window_t;

  friend class graphic_ctx_t;

  using cb_event_t = std::function<void(std::shared_ptr<event_t>)>;

  master_event_register_t events;

  template <unsigned int xcb_event_enum, typename cb_t>
  void on(const cb_t &cb) {
    events.on<xcb_event_enum>(cb);
  }

  template <unsigned int xcb_event_enum, typename ev_t>
  void emit(const ev_t &ev) {
    events.emit<xcb_event_enum>(ev);
  }

  void emit_raw(xcb_generic_event_t *e) {
    events.emit_raw(weak_ref.lock(), e);
  }

  static std::shared_ptr<connection_t> make(const char *display_name = nullptr, int *screen_num = nullptr);

  ~connection_t();

  const char *get_display();

  int *get_screen_num();

  int get_screen_count();

  void pause();

  int flush();

  void throw_bad_cookie(const std::string &name, xcb_void_cookie_t cookie);

  xcb_generic_event_t *wait_for_event();

  xcb_generic_event_t *poll_for_event();

  std::shared_ptr<screen_t> get_screen(int *num = nullptr);

  std::shared_ptr<window_t> create_window(xcb_window_t window);

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

  std::shared_ptr<glx_window_t> create_glx_window(
    int16_t x,
    int16_t y,
    uint16_t width,
    uint16_t height,
    uint16_t border_width,
    xcb_window_t parent,
    int visual,
    uint8_t depth = XCB_COPY_FROM_PARENT,
    uint16_t _class = XCB_WINDOW_CLASS_INPUT_OUTPUT,
    uint32_t eventmask = XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_KEY_PRESS
  );

private:

  std::weak_ptr<connection_t> weak_ref;

  xcb_connection_t *connection;

  Display *display;

  const char *display_name;

  int *screen_num;

  connection_t(
    xcb_connection_t *connection_,
    Display *display_,
    const char *display_name_,
    int *screen_num_
  ) :
    connection(connection_),
    display(display_),
    display_name(display_name_),
    screen_num(screen_num_) {};

};  // connection_t

}   // xcbxx
