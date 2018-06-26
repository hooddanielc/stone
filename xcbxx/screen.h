#pragma once

namespace xcbxx {

class connection_t;

class window_t;

class screen_t {

public:

  friend connection_t;

  screen_t(
    std::shared_ptr<connection_t> connection_,
    int *screen_num_
  ) :
    connection(connection_),
    screen_num(screen_num_),
    screen(construct_screen()) {}

  std::shared_ptr<window_t> get_root_window();

  uint32_t get_root();

  uint16_t get_width_in_pixels();

  uint16_t get_height_in_pixels();

  uint32_t get_white_pixel();

  uint32_t get_black_pixel();

  xcb_colormap_t get_default_colormap();

  uint32_t get_current_input_masks();

  uint16_t get_width_in_millimeters();

  uint16_t get_height_in_millimeters();

  uint16_t get_min_installed_maps();

  uint16_t get_max_installed_maps();

  xcb_visualid_t get_root_visual();

  uint8_t get_backing_stores();

  uint8_t get_save_unders();

  uint8_t get_root_depth();

  uint8_t get_allowed_depths_len();

  void print();

private:

  std::shared_ptr<connection_t> connection;

  int *screen_num;

  xcb_screen_t *screen;

  xcb_screen_t *construct_screen();

};  // screen_t

}   // xcbxx
