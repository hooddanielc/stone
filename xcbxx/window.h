#pragma once

#include <sstream>
#include <xcb/xcb.h>
#include <xcbxx/graphic-ctx.h>
#include <xcbxx/screen.h>
#include <xcbxx/events.h>
#include <iostream>
#include <unordered_map>

namespace xcbxx {

class graphic_ctx_t;

class connection_t;

class window_t {

public:

  friend class connection_t;

  friend class screen_t;

  window_t(
    std::shared_ptr<connection_t> connection_,
    xcb_window_t window_
  ) :
    connection(connection_),
    window(window_),
    delete_cookie_reply(fetch_delete_cookie()) {}

  void show();

  std::string get_name();

  void set_name(const std::string &name);

  void change_property(
    uint8_t mode, xcb_atom_t property, xcb_atom_t type,
    uint8_t format, uint32_t data_len, const void *data
  );

  void replace_property(
    xcb_atom_t property, xcb_atom_t type,
    uint8_t format, uint32_t data_len, const void *data
  );

  void prepend_property(
    xcb_atom_t property, xcb_atom_t type,
    uint8_t format, uint32_t data_len, const void *data
  );

  void append_property(
    xcb_atom_t property, xcb_atom_t type,
    uint8_t format, uint32_t data_len, const void *data
  );

  void change_attributes(uint32_t value_mask, const uint32_t *value_list);

  void configure_window(uint16_t value_mask, const uint32_t *value_list);

  std::shared_ptr<graphic_ctx_t> make_graphic_ctx(
    uint32_t value_mask,
    const uint32_t *value_list
  );

  xcb_atom_t get_delete_reply();

  virtual ~window_t();

  int get_window_id();

  void on_key_press(const std::function<void(std::shared_ptr<key_press_event_t>)> &);

  void on_focus_in(const std::function<void(std::shared_ptr<focus_in_event_t>)> &);

  void on_expose(const std::function<void(std::shared_ptr<expose_event_t>)> &);

protected:

  // std::unordered_map<unsigned int, std::vector<std::shared_ptr<event_t>>> window_events;

  // master_event_register_t events;

  std::shared_ptr<connection_t> connection;

  xcb_window_t window;

  xcb_connection_t *get_connection();

  xcb_atom_t fetch_delete_cookie();

  xcb_atom_t delete_cookie_reply;

};  // window_t

}   // xcbxx
