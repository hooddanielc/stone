#pragma once

#include <xcbxx/events/event.h>

namespace xcbxx {

class enter_notify_event_t: public event_t {

public:

  xcb_window_t get_window() {
    return event->event;
  }

  int16_t get_root_x() {
    return event->root_x;
  }

  int16_t get_root_y() {
    return event->root_y;
  }

  int16_t get_event_x() {
    return event->event_x;
  }

  int16_t get_event_y() {
    return event->event_y;
  }

protected:

  friend class event_t;

  static constexpr const char* name = "enter_notify_event_t";

  std::shared_ptr<connection_t> connection;

  xcb_enter_notify_event_t *event;

  enter_notify_event_t(std::shared_ptr<connection_t> connection_, xcb_generic_event_t *event_):
    event_t(event_),
    connection(connection_),
    event((xcb_enter_notify_event_t *) event_) {}

};  // event_t

}
