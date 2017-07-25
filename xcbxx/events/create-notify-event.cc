#include <xcbxx/events/create-notify-event.h>

namespace xcbxx {

std::shared_ptr<create_notify_event_t>
create_notify_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<create_notify_event_t>(e, XCB_CREATE_NOTIFY);
}

}
