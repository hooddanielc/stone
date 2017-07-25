#include <xcbxx/events/focus-in-event.h>

namespace xcbxx {

std::shared_ptr<focus_in_event_t>
focus_in_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<focus_in_event_t>(e, XCB_FOCUS_IN);
}

}
