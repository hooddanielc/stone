#include <xcbxx/events/map-request-event.h>

namespace xcbxx {

std::shared_ptr<map_request_event_t>
map_request_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<map_request_event_t>(e, XCB_MAP_REQUEST);
}

}
