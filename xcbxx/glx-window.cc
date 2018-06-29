#include <xcbxx/glx-window.h>
#include <xcbxx/connection.h>

namespace xcbxx {

void glx_window_t::swap_buffers() {
  glXSwapBuffers(connection->display, glx_drawable);
}

glx_window_t::~glx_window_t() {
  glXDestroyWindow(connection->display, glx_window);
  xcb_destroy_window(connection->connection, window_t::window);
  glXDestroyContext(connection->display, glx_context);
}

bool glx_window_t::make_current() {
  return glXMakeCurrent(connection->display, glx_drawable, glx_context);
}

}
