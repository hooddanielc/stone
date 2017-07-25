#pragma once

#include <xcbxx/events/event.h>

namespace xcbxx {

class button_press_event_t: public event_t {

protected:

  friend class event_t;

  static constexpr const char* name = "button_press_event_t";

  xcb_button_press_event_t *event;

  button_press_event_t(xcb_generic_event_t *event_):
    event_t(event_),
    event((xcb_button_press_event_t *) event_) {}

  static std::shared_ptr<button_press_event_t> make(xcb_generic_event_t *);

};  // event_t

}