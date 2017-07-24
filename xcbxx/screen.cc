#include <xcbxx/connection.h>

namespace xcbxx {

std::shared_ptr<window_t> screen_t::get_root_window() {
  return std::shared_ptr<window_t>(new window_t(connection, screen->root));
}

uint16_t screen_t::get_width_in_pixels() {
  return screen->width_in_pixels;
}

uint16_t screen_t::get_height_in_pixels() {
  return screen->height_in_pixels;
}

uint32_t screen_t::get_white_pixel() {
  return screen->white_pixel;
}

uint32_t screen_t::get_black_pixel() {
  return screen->black_pixel;
}

xcb_colormap_t screen_t::get_default_colormap() {
  return screen->default_colormap;
}

uint32_t screen_t::get_current_input_masks() {
  return screen->current_input_masks;
}

uint16_t screen_t::get_width_in_millimeters() {
  return screen->width_in_millimeters;
}

uint16_t screen_t::get_height_in_millimeters() {
  return screen->height_in_millimeters;
}

uint16_t screen_t::get_min_installed_maps() {
  return screen->min_installed_maps;
}

uint16_t screen_t::get_max_installed_maps() {
  return screen->max_installed_maps;
}

xcb_visualid_t screen_t::get_root_visual() {
  return screen->root_visual;
}

uint8_t screen_t::get_backing_stores() {
  return screen->backing_stores;
}

uint8_t screen_t::get_save_unders() {
  return screen->save_unders;
}

uint8_t screen_t::get_root_depth() {
  return screen->root_depth;
}

uint8_t screen_t::get_allowed_depths_len() {
  return screen->allowed_depths_len;
}

uint32_t screen_t::get_root() {
  return screen->root;
}

void screen_t::print() {
  std::cout << "  display               : " << connection->get_display() << std::endl;
  std::cout << "  root window           : " << get_root() << std::endl;
  std::cout << "  width                 : " << get_width_in_pixels() << std::endl;
  std::cout << "  height                : " << get_height_in_pixels() << std::endl;
  std::cout << "  white pixel           : " << get_white_pixel() << std::endl;
  std::cout << "  black pixel           : " << get_black_pixel() << std::endl;
  std::cout << "  default_colormap      : " << get_default_colormap() << std::endl;
  std::cout << "  current_input_masks   : " << get_current_input_masks() << std::endl;
  std::cout << "  width_in_millimeters  : " << get_width_in_millimeters() << std::endl;
  std::cout << "  height_in_millimeters : " << get_height_in_millimeters() << std::endl;
  std::cout << "  min_installed_maps    : " << get_min_installed_maps() << std::endl;
  std::cout << "  max_installed_maps    : " << get_max_installed_maps() << std::endl;
  std::cout << "  root_visual           : " << get_root_visual() << std::endl;
  std::cout << "  backing_stores        : " << unsigned(get_backing_stores()) << std::endl;
  std::cout << "  save_unders           : " << unsigned(get_save_unders()) << std::endl;
  std::cout << "  root_depth            : " << unsigned(get_root_depth()) << std::endl;
  std::cout << "  allowed_depths_len    : " << unsigned(get_allowed_depths_len()) << std::endl;
}

xcb_screen_t *screen_t::construct_screen()  {
  const xcb_setup_t *setup = xcb_get_setup(connection.get()->connection);
  xcb_screen_iterator_t iter = xcb_setup_roots_iterator(setup);  

  if (screen_num) {
    for (int i = 0; i < *screen_num; ++i) {
        xcb_screen_next(&iter);
    }
  }

  return iter.data;
}

}   // xcbxx
