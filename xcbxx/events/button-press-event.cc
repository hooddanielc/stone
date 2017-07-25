#include <xcbxx/events/button-press-event.h>

namespace xcbxx {

std::shared_ptr<button_press_event_t>
button_press_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<button_press_event_t>(e, XCB_BUTTON_PRESS);
}

}