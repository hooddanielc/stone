#pragma once

#include <xcbxx/events/event.h>

namespace xcbxx {

class selection_request_event_t: public event_t {

protected:

  friend class event_t;

  static constexpr const char* name = "selection_request_event_t";

  xcb_selection_request_event_t *event;

  selection_request_event_t(xcb_generic_event_t *event_):
    event_t(event_),
    event((xcb_selection_request_event_t *) event_) {}

  static std::shared_ptr<selection_request_event_t> make(xcb_generic_event_t *);

};  // event_t

}