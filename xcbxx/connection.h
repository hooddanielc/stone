#pragma once

#include <map>
#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <cstdlib>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <xcb/xcb.h>
#include <xkbcommon/xkbcommon.h>
#include <xkbcommon/xkbcommon-x11.h>
#include <xcb/xinput.h>
#include <X11/Xlib.h>
#include <X11/Xlib-xcb.h>
#include "screen.h"
#include "window.h"
#include "graphic-ctx.h"
#include "events.h"
#include "glx-window.h"

namespace xcbxx {

class window_t;

class connection_t {

public:

  friend class glx_window_t;

  friend class screen_t;

  friend class window_t;

  friend class graphic_ctx_t;

  connection_t(
    xcb_connection_t *connection_,
    Display *display_,
    const char *display_name_,
    int *screen_num_
  ) :
    connection(connection_),
    display(display_),
    display_name(display_name_),
    screen_num(screen_num_),
    xkb_ctx(nullptr),
    xkb_km(nullptr),
    xkb_st(nullptr) {

    xkb_ctx = xkb_context_new(XKB_CONTEXT_NO_FLAGS);
    if (!xkb_ctx) {
      throw std::runtime_error("xkb context creation failed");
    }
    int32_t device_id = xkb_x11_get_core_keyboard_device_id(connection);
    if (device_id == -1) {
      throw std::runtime_error("xkb_x11_get_core_keyboard_device_id: error");
    }
    xkb_km = xkb_x11_keymap_new_from_device(
      xkb_ctx,
      connection,
      device_id,
      XKB_KEYMAP_COMPILE_NO_FLAGS
    );
    if (!xkb_km) {
      throw std::runtime_error("xkb_x11_keymap_new_from_device: error");
    }
    xkb_st = xkb_x11_state_new_from_device(xkb_km, connection, device_id);
    if (!xkb_st) {
      throw std::runtime_error("xkb_x11_state_new_from_device: error");
    }
  }

  xkb_keysym_t get_keysym(xkb_keycode_t keycode) {
    return xkb_state_key_get_one_sym(xkb_st, keycode);
  }

  std::string get_keysym_str(xkb_keycode_t keycode) {
    char keysym_name[64];
    auto keysym = get_keysym(keycode);
    xkb_keysym_get_name(keysym, keysym_name, sizeof(keysym_name));
    return std::string(keysym_name);
  }

  void print_keyboard_mapping();

  using cb_event_t = std::function<void(std::shared_ptr<event_t>)>;

  [[noreturn]] void throw_xcb_generic_error(xcb_generic_error_t *error) {
    throw std::runtime_error("xcb error " + std::to_string(error->error_code));
  }

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

  xkb_context *xkb_ctx;

  xkb_keymap *xkb_km;

  xkb_state *xkb_st;

};  // connection_t

}   // xcbxx
