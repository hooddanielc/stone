#pragma once

#include <xcbxx/events/event.h>

namespace xcbxx {

class focus_in_event_t: public event_t {

public:

  xcb_window_t get_window() {
    return event->event;
  }

protected:

  friend class event_t;

  static constexpr const char* name = "focus_in_event_t";

  std::shared_ptr<connection_t> connection;

  xcb_focus_in_event_t *event;

  focus_in_event_t(std::shared_ptr<connection_t> connection_, xcb_generic_event_t *event_):
    event_t(event_),
    connection(connection_),
    event((xcb_focus_in_event_t *) event_) {}

};  // event_t

}
