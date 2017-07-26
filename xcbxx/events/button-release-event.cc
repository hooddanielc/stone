#include <xcbxx/events/button-release-event.h>

namespace xcbxx {

std::shared_ptr<button_release_event_t>
button_release_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<button_release_event_t>(e, XCB_BUTTON_RELEASE);
}

}
