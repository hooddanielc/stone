#pragma once

#include <xcbxx/events/event.h>

namespace xcbxx {

class expose_event_t: public event_t {

protected:

  friend class event_t;

  static constexpr const char* name = "expose_event_t";

  xcb_expose_event_t *event;

  expose_event_t(xcb_generic_event_t *event_):
    event_t(event_),
    event((xcb_expose_event_t *) event_) {}

  static std::shared_ptr<expose_event_t> make(xcb_generic_event_t *);

};  // event_t

}