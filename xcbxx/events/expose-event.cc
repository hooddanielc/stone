#include <xcbxx/events/expose-event.h>

namespace xcbxx {

std::shared_ptr<expose_event_t>
expose_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<expose_event_t>(e, XCB_EXPOSE);
}

}
