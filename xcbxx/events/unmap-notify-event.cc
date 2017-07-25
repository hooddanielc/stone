#include <xcbxx/events/unmap-notify-event.h>

namespace xcbxx {

std::shared_ptr<unmap_notify_event_t>
unmap_notify_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<unmap_notify_event_t>(e, XCB_UNMAP_NOTIFY);
}

}
