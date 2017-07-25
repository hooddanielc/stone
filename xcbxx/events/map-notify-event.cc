#include <xcbxx/events/map-notify-event.h>

namespace xcbxx {

std::shared_ptr<map_notify_event_t>
map_notify_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<map_notify_event_t>(e, XCB_MAP_NOTIFY);
}

}
