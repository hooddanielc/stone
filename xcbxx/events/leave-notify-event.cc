#include <xcbxx/events/leave-notify-event.h>

namespace xcbxx {

std::shared_ptr<leave_notify_event_t>
leave_notify_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<leave_notify_event_t>(e, XCB_LEAVE_NOTIFY);
}

}
