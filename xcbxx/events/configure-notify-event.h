#pragma once

#include <xcbxx/events/event.h>

namespace xcbxx {

class configure_notify_event_t: public event_t {

protected:

  friend class event_t;

  static constexpr const char* name = "configure_notify_event_t";

  xcb_configure_notify_event_t *event;

  configure_notify_event_t(xcb_generic_event_t *event_):
    event_t(event_),
    event((xcb_configure_notify_event_t *) event_) {}

  static std::shared_ptr<configure_notify_event_t> make(xcb_generic_event_t *);

};  // event_t

}