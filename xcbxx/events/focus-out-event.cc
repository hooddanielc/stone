#include <xcbxx/events/focus-out-event.h>

namespace xcbxx {

std::shared_ptr<focus_out_event_t>
focus_out_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<focus_out_event_t>(e, XCB_FOCUS_OUT);
}

}
