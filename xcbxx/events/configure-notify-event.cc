#include <xcbxx/events/configure-notify-event.h>

namespace xcbxx {

std::shared_ptr<configure_notify_event_t>
configure_notify_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<configure_notify_event_t>(e, XCB_CONFIGURE_NOTIFY);
}

}