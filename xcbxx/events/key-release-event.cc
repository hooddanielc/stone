#include <xcbxx/events/key-release-event.h>

namespace xcbxx {

std::shared_ptr<key_release_event_t>
key_release_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<key_release_event_t>(e, XCB_KEY_RELEASE);
}

}
