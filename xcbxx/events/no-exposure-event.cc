#include <xcbxx/events/no-exposure-event.h>

namespace xcbxx {

std::shared_ptr<no_exposure_event_t>
no_exposure_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<no_exposure_event_t>(e, XCB_NO_EXPOSURE);
}

}
