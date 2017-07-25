#pragma once

#include <xcbxx/events/event.h>

namespace xcbxx {

class client_message_event_t: public event_t {

protected:

  friend class event_t;

  static constexpr const char* name = "client_message_event_t";

  xcb_client_message_event_t *event;

  client_message_event_t(xcb_generic_event_t *event_):
    event_t(event_),
    event((xcb_client_message_event_t *) event_) {}

  static std::shared_ptr<client_message_event_t> make(xcb_generic_event_t *);

};  // event_t

}