#include <xcbxx/events/gravity-notify-event.h>

namespace xcbxx {

std::shared_ptr<gravity_notify_event_t>
gravity_notify_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<gravity_notify_event_t>(e, XCB_GRAVITY_NOTIFY);
}

}
