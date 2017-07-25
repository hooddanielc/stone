#include <xcbxx/events/motion-notify-event.h>

namespace xcbxx {

std::shared_ptr<motion_notify_event_t>
motion_notify_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<motion_notify_event_t>(e, XCB_MOTION_NOTIFY);
}

}
