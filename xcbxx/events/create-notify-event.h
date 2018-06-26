#pragma once

#include <xcbxx/events/event.h>

namespace xcbxx {

class window_t;

class create_notify_event_t: public event_t {

protected:

  friend class event_t;

  static constexpr const char* name = "create_notify_event_t";

  std::shared_ptr<connection_t> connection;

  xcb_create_notify_event_t *event;

  create_notify_event_t(std::shared_ptr<connection_t> connection_, xcb_generic_event_t *event_):
    event_t(event_),
    connection(connection_),
    event((xcb_create_notify_event_t *) event_) {}

public:

  std::shared_ptr<window_t> get_window();

  std::shared_ptr<window_t> get_parent();

  int16_t get_x();

  int16_t get_y();

  uint16_t get_width();

  uint16_t get_height();

  uint16_t get_border_width();

};  // event_t

}
