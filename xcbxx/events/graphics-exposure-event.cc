#include <xcbxx/events/graphics-exposure-event.h>

namespace xcbxx {

std::shared_ptr<graphics_exposure_event_t>
graphics_exposure_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<graphics_exposure_event_t>(e, XCB_GRAPHICS_EXPOSURE);
}

}
