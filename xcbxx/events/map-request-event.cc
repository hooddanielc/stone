#include <xcbxx/events/map-request-event.h>
#include <xcbxx/connection.h>

namespace xcbxx {

std::shared_ptr<window_t> map_request_event_t::get_window() {
  return connection->create_window(event->window);
}

}
