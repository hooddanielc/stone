#include <xcbxx/window.h>
#include <xcbxx/connection.h>

namespace xcbxx {

int window_t::get_window_id() {
  return static_cast<int>(window);
}

window_t::~window_t() {
  xcb_destroy_window(get_connection(), window);
}

void window_t::set_name(const std::string &name) {
  replace_property(XCB_ATOM_WM_NAME, XCB_ATOM_STRING, 8, static_cast<uint32_t>(name.size()), name.c_str());
}

xcb_connection_t *window_t::get_connection() {
  return connection->connection;
}

std::shared_ptr<graphic_ctx_t> window_t::make_graphic_ctx(uint32_t value_mask, const uint32_t *value_list) {
  return std::make_shared<graphic_ctx_t>(
    connection,
    window,
    value_mask,
    value_list
  );
}

void window_t::show()  {
  auto cookie = xcb_map_window(get_connection(), window);
  connection->throw_bad_cookie("xcb_map_window", cookie);
}

void window_t::change_attributes(uint32_t value_mask, const uint32_t *value_list) {
  auto cookie = xcb_change_window_attributes(get_connection(), window, value_mask, value_list);
  connection->throw_bad_cookie("xcb_change_window_attributes", cookie);
}

void window_t::configure_window(uint16_t value_mask, const uint32_t *value_list) {
  auto cookie = xcb_configure_window(get_connection(), window, value_mask, value_list);
  connection->throw_bad_cookie("xcb_change_window_attributes", cookie);
}

void window_t::change_property(
  uint8_t mode, xcb_atom_t property, xcb_atom_t type,
  uint8_t format, uint32_t data_len, const void *data
) {
  auto cookie = xcb_change_property(
    get_connection(), mode, window, property,
    type, format, data_len, data
  );
  connection->throw_bad_cookie("change window property", cookie);
}

void window_t::replace_property(
  xcb_atom_t property, xcb_atom_t type,
  uint8_t format, uint32_t data_len, const void *data
) {
  change_property(XCB_PROP_MODE_REPLACE, property, type, format, data_len, data);
}

void window_t::prepend_property(
  xcb_atom_t property, xcb_atom_t type,
  uint8_t format, uint32_t data_len, const void *data
) {
  return change_property(XCB_PROP_MODE_PREPEND, property, type, format, data_len, data);
}

void window_t::append_property(
  xcb_atom_t property, xcb_atom_t type,
  uint8_t format, uint32_t data_len, const void *data
) {
  return change_property(XCB_PROP_MODE_APPEND, property, type, format, data_len, data);
}

xcb_atom_t window_t::get_delete_reply() {
  return delete_cookie_reply;
}

xcb_atom_t window_t::fetch_delete_cookie() {
  auto c = get_connection();
  auto proto_request = xcb_intern_atom(c, 0, 12, "WM_PROTOCOLS");
  auto delete_win_request = xcb_intern_atom(c, 0, 16, "WM_DELETE_WINDOW");
  xcb_intern_atom_reply_t *proto_reply = xcb_intern_atom_reply(c, proto_request, nullptr);
  xcb_intern_atom_reply_t *delete_win_reply = xcb_intern_atom_reply(c, delete_win_request, nullptr);
  if (!proto_reply || !delete_win_reply) {
    throw std::runtime_error("getting delete cookie failed");
  }
  replace_property(proto_reply->atom, 4, 32, 1, &delete_win_reply->atom);
  return delete_win_reply->atom;
}

void window_t::on_key_press(const std::function<void(std::shared_ptr<key_press_event_t>)> &fn) {
  connection->on<XCB_KEY_PRESS>([&](std::shared_ptr<key_press_event_t> e) {
    if (e->get_window() == window) {
      fn(e);
    }
  });
}

void window_t::on_focus_in(const std::function<void(std::shared_ptr<focus_in_event_t>)> &fn) {
  connection->on<XCB_FOCUS_IN>([&](std::shared_ptr<focus_in_event_t> e) {
    if (e->get_window() == window) {
      fn(e);
    }
  });
}

void window_t::on_expose(const std::function<void(std::shared_ptr<expose_event_t>)> &fn) {
  connection->on<XCB_EXPOSE>([&](std::shared_ptr<expose_event_t> e) {
    std::cout << "THE WINDOW IS " << e->get_window() << std::endl;
    if (e->get_window() == window) {
      fn(e);
    }
  });
}

}
