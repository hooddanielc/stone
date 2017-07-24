#include <xcbxx/window.h>

namespace xcbxx {

xcb_connection_t *window_t::get_connection() {
  return connection->connection;
}

std::shared_ptr<graphic_ctx_t> window_t::make_graphic_ctx(uint32_t value_mask, const uint32_t *value_list) {
  return std::shared_ptr<graphic_ctx_t>(new graphic_ctx_t(
    connection,
    window,
    value_mask,
    value_list
  ));
}

void window_t::show()  {
  auto cookie = xcb_map_window(get_connection(), window);
  connection->throw_bad_cookie("xcb_map_window", cookie);
}

void window_t::change_attributes(uint32_t value_mask, const uint32_t *value_list) {
  auto cookie = xcb_change_window_attributes(get_connection(), window, value_mask, value_list);
  connection->throw_bad_cookie("xcb_change_window_attributes", cookie);
}

}