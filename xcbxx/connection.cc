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

xcb_generic_event_t *connection_t::wait_for_event() {
  return xcb_wait_for_event(connection);
}

xcb_generic_event_t *connection_t::poll_for_event() {
  return xcb_poll_for_event(connection);
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

int connection_t::flush() {
  return xcb_flush(connection);
}

void connection_t::aux_sync() {
  xcb_aux_sync(connection);
}

std::shared_ptr<window_t> connection_t::create_window(
  int16_t x,
  int16_t y,
  uint16_t width,
  uint16_t height,
  uint16_t border_width,
  xcb_window_t parent,
  xcb_visualid_t visual,
  uint8_t depth,
  uint16_t _class,
  uint32_t value_mask,
  const uint32_t *value_list
) {
  auto ptr = new window_t(
    weak_ref.lock(),
    x,
    y,
    width,
    height,
    border_width,
    parent,
    visual,
    depth,
    _class,
    value_mask,
    value_list
  );

  throw_bad_cookie("xcb_create_window", ptr->cookie);
  return std::shared_ptr<window_t>(ptr);
}

};  // xcbxx
