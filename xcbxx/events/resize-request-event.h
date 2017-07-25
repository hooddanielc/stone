#pragma once

#include <xcbxx/events/event.h>

namespace xcbxx {

class resize_request_event_t: public event_t {

protected:

  friend class event_t;

  static constexpr const char* name = "resize_request_event_t";

  xcb_resize_request_event_t *event;

  resize_request_event_t(xcb_generic_event_t *event_):
    event_t(event_),
    event((xcb_resize_request_event_t *) event_) {}

  static std::shared_ptr<resize_request_event_t> make(xcb_generic_event_t *);

};  // event_t

}