#include <xcbxx/events/configure-request-event.h>

namespace xcbxx {

std::shared_ptr<configure_request_event_t>
configure_request_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<configure_request_event_t>(e, XCB_CONFIGURE_REQUEST);
}

}
