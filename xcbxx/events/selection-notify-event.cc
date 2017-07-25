#include <xcbxx/events/selection-notify-event.h>

namespace xcbxx {

std::shared_ptr<selection_notify_event_t>
selection_notify_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<selection_notify_event_t>(e, XCB_SELECTION_NOTIFY);
}

}
