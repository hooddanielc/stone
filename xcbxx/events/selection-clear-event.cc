#include <xcbxx/events/selection-clear-event.h>

namespace xcbxx {

std::shared_ptr<selection_clear_event_t>
selection_clear_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<selection_clear_event_t>(e, XCB_SELECTION_CLEAR);
}

}
