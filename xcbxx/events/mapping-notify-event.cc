#include <xcbxx/events/mapping-notify-event.h>

namespace xcbxx {

std::shared_ptr<mapping_notify_event_t>
mapping_notify_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<mapping_notify_event_t>(e, XCB_MAPPING_NOTIFY);
}

}
