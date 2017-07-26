#include <xcbxx/events/circulate-request-event.h>

namespace xcbxx {

std::shared_ptr<circulate_request_event_t>
circulate_request_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<circulate_request_event_t>(e, XCB_CIRCULATE_REQUEST);
}

}
