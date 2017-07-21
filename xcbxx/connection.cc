#include <xcbxx/connection.h>

namespace xcbxx {

std::shared_ptr<connection_t> connection_t::make(const char *display, int *screen_num) {
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

  auto result = std::shared_ptr<connection_t>(new connection_t(connection, display, screen_num));
  result->weak_ref = result;
  return result;
}

int connection_t::get_screen_count() {
  return xcb_setup_roots_length(xcb_get_setup(connection));
}

connection_t::~connection_t() {
  xcb_disconnect(connection);
}

const char *connection_t::get_display() {
  return display ? display : std::getenv("DISPLAY");
}

int *connection_t::get_screen_num() {
  return screen_num;
}

void connection_t::pause() {
  ::pause(); // hold client until Ctrl-C
}

std::shared_ptr<screen_t> connection_t::get_screen(int *num) {
  return std::shared_ptr<screen_t>(new screen_t(weak_ref.lock(), num));
}

};  // xcbxx
