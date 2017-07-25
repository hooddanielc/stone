#include <xcbxx/events/colormap-notify-event.h>

namespace xcbxx {

std::shared_ptr<colormap_notify_event_t>
colormap_notify_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<colormap_notify_event_t>(e, XCB_COLORMAP_NOTIFY);
}

}