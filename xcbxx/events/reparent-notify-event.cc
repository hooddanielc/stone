#include <xcbxx/events/reparent-notify-event.h>

namespace xcbxx {

std::shared_ptr<reparent_notify_event_t>
reparent_notify_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<reparent_notify_event_t>(e, XCB_REPARENT_NOTIFY);
}

}
