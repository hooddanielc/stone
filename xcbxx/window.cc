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
  xcb_map_window(connection->connection, window);
}

}