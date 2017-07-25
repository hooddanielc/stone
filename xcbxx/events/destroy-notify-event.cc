#include <xcbxx/events/destroy-notify-event.h>

namespace xcbxx {

std::shared_ptr<destroy_notify_event_t>
destroy_notify_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<destroy_notify_event_t>(e, XCB_DESTROY_NOTIFY);
}

}
