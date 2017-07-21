#pragma once

#include <memory>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <xcb/xcb.h>
#include <inttypes.h>

namespace xcbxx {

class connection_t {

public:

  static std::unique_ptr<connection_t> make(const char *display = nullptr, int *screen_num = new int()) {
    auto connection = xcb_connect(display, screen_num);
    auto err = xcb_connection_has_error(connection);

    switch(err) {
      case XCB_CONN_ERROR:
        throw std::runtime_error("XCB_CONN_ERROR");
      case XCB_CONN_CLOSED_EXT_NOTSUPPORTED:
        throw std::runtime_error("XCB_CONN_CLOSED_EXT_NOTSUPPORTED");
      case XCB_CONN_CLOSED_MEM_INSUFFICIENT:
        throw std::runtime_error("XCB_CONN_CLOSED_MEM_INSUFFICIENT");
      case XCB_CONN_CLOSED_REQ_LEN_EXCEED:
        throw std::runtime_error("XCB_CONN_CLOSED_REQ_LEN_EXCEED");
      case XCB_CONN_CLOSED_PARSE_ERR:
        throw std::runtime_error("XCB_CONN_CLOSED_PARSE_ERR");
      case XCB_CONN_CLOSED_INVALID_SCREEN:
        throw std::runtime_error("XCB_CONN_CLOSED_INVALID_SCREEN");
    }

    return std::unique_ptr<connection_t>(new connection_t(connection, display, screen_num));
  }

  ~connection_t() {
    xcb_disconnect(connection);
  }

  void pause() {
    ::pause(); // hold client until Ctrl-C
  }

  void print_screen_data() {
    /* Get the screen whose number is screenNum */
    const xcb_setup_t *setup = xcb_get_setup(connection);
    xcb_screen_iterator_t iter = xcb_setup_roots_iterator(setup);  

    if (screen_num) {
      for (int i = 0; i < *screen_num; ++i) {
          xcb_screen_next (&iter);
      }
    }

    xcb_screen_t *screen = iter.data;
    std::cout << "Screen Information For Root Window " << screen->root << std::endl;

    if (display) {
      std::cout << "  display:              : '" << display << "'" << std::endl;
    } else if(const char *display_env = std::getenv("DISPLAY")) {
      std::cout << "  display:              : '" << display_env << "'" << std::endl;
    }

    std::cout << "  width                 : " << screen->width_in_pixels << std::endl;
    std::cout << "  height                : " << screen->height_in_pixels << std::endl;
    std::cout << "  white pixel           : " << screen->white_pixel << std::endl;
    std::cout << "  black pixel           : " << screen->black_pixel << std::endl;
    std::cout << "  default_colormap      : " << screen->default_colormap << std::endl;
    std::cout << "  current_input_masks   : " << screen->current_input_masks << std::endl;
    std::cout << "  width_in_millimeters  : " << screen->width_in_millimeters << std::endl;
    std::cout << "  height_in_millimeters : " << screen->height_in_millimeters << std::endl;
    std::cout << "  min_installed_maps    : " << screen->min_installed_maps << std::endl;
    std::cout << "  max_installed_maps    : " << screen->max_installed_maps << std::endl;
    std::cout << "  root_visual           : " << screen->root_visual << std::endl;
    std::cout << "  backing_stores        : " << unsigned(screen->backing_stores) << std::endl;
    std::cout << "  save_unders           : " << unsigned(screen->save_unders) << std::endl;
    std::cout << "  root_depth            : " << unsigned(screen->root_depth) << std::endl;
    std::cout << "  allowed_depths_len    : " << unsigned(screen->allowed_depths_len) << std::endl;
  }

private:

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
