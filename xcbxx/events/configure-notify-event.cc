#include <xcbxx/events/configure-notify-event.h>
#include <xcbxx/connection.h>

namespace xcbxx {

std::shared_ptr<window_t> configure_notify_event_t::get_window() {
  return connection->create_window(event->window);
}

std::shared_ptr<window_t> configure_notify_event_t::get_above_sibling() {
  return connection->create_window(event->above_sibling);
}

std::shared_ptr<window_t> configure_notify_event_t::get_event() {
  return connection->create_window(event->event);
}

int16_t configure_notify_event_t::get_x() {
  return event->x;
}

int16_t configure_notify_event_t::get_y() {
  return event->y;
}

uint16_t configure_notify_event_t::get_width() {
  return event->width;
}

uint16_t configure_notify_event_t::get_height() {
  return event->height;
}

uint16_t configure_notify_event_t::get_border_width() {
  return event->border_width;
}

uint8_t configure_notify_event_t::get_override_redirect() {
  return event->override_redirect;
}

}