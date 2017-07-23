#pragma once

#include <map>
#include <iostream>
#include <memory>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <xcb/xcb.h>
#include <xcbxx/screen.h>
#include <xcbxx/window.h>

namespace xcbxx {

class window_t;

class connection_t {

public:

  friend class screen_t;

  friend class window_t;

  static std::shared_ptr<connection_t> make(const char *display = nullptr, int *screen_num = new int());

  ~connection_t();

  const char *get_display();

  int *get_screen_num();

  int get_screen_count();

  void pause();

  void flush();

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
