#include <xcbxx/events/property-notify-event.h>

namespace xcbxx {

std::shared_ptr<property_notify_event_t>
property_notify_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<property_notify_event_t>(e, XCB_PROPERTY_NOTIFY);
}

}
