#pragma once

#include <xcbxx/events/event.h>

namespace xcbxx {

class graphics_exposure_event_t: public event_t {

protected:

  friend class event_t;

  static constexpr const char* name = "graphics_exposure_event_t";

  std::shared_ptr<connection_t> connection;

  xcb_graphics_exposure_event_t *event;

  graphics_exposure_event_t(std::shared_ptr<connection_t> connection_, xcb_generic_event_t *event_):
    event_t(event_),
    connection(connection_),
    event((xcb_graphics_exposure_event_t *) event_) {}

};  // event_t

}
