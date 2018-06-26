#include <xcbxx/events/client-message-event.h>
#include <xcbxx/connection.h>

namespace xcbxx {

std::shared_ptr<window_t> client_message_event_t::get_window() {
  return connection->create_window(event->window);
}

uint8_t client_message_event_t::get_response_type() {
  return event->response_type;
}

uint8_t client_message_event_t::get_format() {
  return event->format;
}

uint16_t client_message_event_t::get_sequence() {
  return event->sequence;
}

xcb_atom_t client_message_event_t::get_type() {
  return event->type;
}

xcb_client_message_data_t client_message_event_t::get_data() {
  return event->data;
}

}
