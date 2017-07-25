#include <xcbxx/events/keymap-notify-event.h>

namespace xcbxx {

std::shared_ptr<keymap_notify_event_t>
keymap_notify_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<keymap_notify_event_t>(e, XCB_KEYMAP_NOTIFY);
}

}
