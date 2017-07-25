#include <xcbxx/events/visibility-notify-event.h>

namespace xcbxx {

std::shared_ptr<visibility_notify_event_t>
visibility_notify_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<visibility_notify_event_t>(e, XCB_VISIBILITY_NOTIFY);
}

}
