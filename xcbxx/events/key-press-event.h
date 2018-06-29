#pragma once

#include <string>
#define XK_LATIN1
#include <iostream>
#include <X11/keysymdef.h>
#include <xcbxx/events/event.h>

namespace xcbxx {

class key_press_event_t: public event_t {

public:

  xcb_window_t get_window() {
    return event->event;
  }

  xcb_keycode_t get_keycode();

  std::string get_name();

protected:

  friend class event_t;

  static constexpr const char* name = "key_press_event_t";

  std::shared_ptr<connection_t> connection;

  xcb_key_press_event_t *event;

  key_press_event_t(std::shared_ptr<connection_t> connection_, xcb_generic_event_t *event_):
    event_t(event_),
    connection(connection_),
    event((xcb_key_press_event_t *) event_) {}

};  // event_t

}
