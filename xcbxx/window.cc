#include <xcbxx/window.h>

namespace xcbxx {

xcb_connection_t *window_t::get_connection() {
  return connection->connection;
}

void window_t::show()  {
  xcb_map_window(connection->connection, window);
}

}