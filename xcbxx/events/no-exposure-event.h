#pragma once

#include <xcbxx/events/event.h>

namespace xcbxx {

class no_exposure_event_t: public event_t {

protected:

  friend class event_t;

  static constexpr const char* name = "no_exposure_event_t";

  xcb_no_exposure_event_t *event;

  no_exposure_event_t(xcb_generic_event_t *event_):
    event_t(event_),
    event((xcb_no_exposure_event_t *) event_) {}

  static std::shared_ptr<no_exposure_event_t> make(xcb_generic_event_t *);

};  // event_t

}