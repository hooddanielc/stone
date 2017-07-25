#include <xcbxx/events/resize-request-event.h>

namespace xcbxx {

std::shared_ptr<resize_request_event_t>
resize_request_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<resize_request_event_t>(e, XCB_RESIZE_REQUEST);
}

}
