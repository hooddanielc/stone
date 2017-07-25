#include <xcbxx/events/key-press-event.h>

namespace xcbxx {

std::shared_ptr<key_press_event_t>
key_press_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<key_press_event_t>(e, XCB_KEY_PRESS);
}

}
