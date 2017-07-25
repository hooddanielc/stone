#include <xcbxx/events/selection-request-event.h>

namespace xcbxx {

std::shared_ptr<selection_request_event_t>
selection_request_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<selection_request_event_t>(e, XCB_SELECTION_REQUEST);
}

}
