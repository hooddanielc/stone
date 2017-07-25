#include <xcbxx/events/client-message-event.h>

namespace xcbxx {

std::shared_ptr<client_message_event_t>
client_message_event_t::make(xcb_generic_event_t *e) {
  return event_t::make<client_message_event_t>(e, XCB_CLIENT_MESSAGE);
}

}