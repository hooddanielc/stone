#include <xcbxx/connection.h>

namespace xcbxx {

void connection_t::throw_bad_cookie(const std::string &name, xcb_void_cookie_t cookie) {
  auto err = xcb_request_check(connection, cookie);

  if (err) {
    std::stringstream ss;
    ss << name << " threw error code " << err->error_code;
    throw std::runtime_error(ss.str());
  }
}

std::shared_ptr<connection_t> connection_t::make(const char *display_name, int *screen_num) {
  Display *display = XOpenDisplay(display_name);
  XSetEventQueueOwner(display, XCBOwnsEventQueue);

  if (!display) {
    throw std::runtime_error("Can't open display");
  }

  if (!screen_num) {
    screen_num = new int();
    *screen_num = DefaultScreen(display);
  }

  auto connection = XGetXCBConnection(display);

  if (!connection) {
    throw std::runtime_error("Can't get xcb connection from display");
  }

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

  auto result = std::shared_ptr<connection_t>(new connection_t(connection, display, display_name, screen_num));
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
  return display_name ? display_name : std::getenv("DISPLAY");
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

std::shared_ptr<window_t> connection_t::create_window(
  xcb_window_t window
) {
  auto ptr = new window_t(weak_ref.lock(), window);
  return std::shared_ptr<window_t>(ptr);
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
