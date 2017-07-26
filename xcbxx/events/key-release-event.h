#pragma once

#include <xcbxx/events/event.h>

namespace xcbxx {

class key_release_event_t: public event_t {

protected:

  friend class event_t;

  static constexpr const char* name = "key_release_event_t";

  xcb_key_release_event_t *event;

  key_release_event_t(xcb_generic_event_t *event_):
    event_t(event_),
    event((xcb_key_release_event_t *) event_) {}

  static std::shared_ptr<key_release_event_t> make(xcb_generic_event_t *);

};  // event_t

}
