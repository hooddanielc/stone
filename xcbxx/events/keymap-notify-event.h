#pragma once

#include <xcbxx/events/event.h>

namespace xcbxx {

class keymap_notify_event_t: public event_t {

protected:

  friend class event_t;

  static constexpr const char* name = "keymap_notify_event_t";

  xcb_keymap_notify_event_t *event;

  keymap_notify_event_t(xcb_generic_event_t *event_):
    event_t(event_),
    event((xcb_keymap_notify_event_t *) event_) {}

  static std::shared_ptr<keymap_notify_event_t> make(xcb_generic_event_t *);

};  // event_t

}