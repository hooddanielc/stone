#include <xcbxx/events/enter-notify-event.h>

namespace xcbxx {

std::shared_ptr<enter_notify_event_t>
enter_notify_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<enter_notify_event_t>(e, XCB_ENTER_NOTIFY);
}

}
