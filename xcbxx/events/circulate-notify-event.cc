#include <xcbxx/events/circulate-notify-event.h>

namespace xcbxx {

std::shared_ptr<circulate_notify_event_t>
circulate_notify_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<circulate_notify_event_t>(e, XCB_CIRCULATE_NOTIFY);
}

}