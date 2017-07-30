#include <xcbxx/events/create-notify-event.h>
#include <xcbxx/connection.h>

namespace xcbxx {

std::shared_ptr<window_t> create_notify_event_t::get_window() {
  return connection->create_window(event->window);
}

std::shared_ptr<window_t> create_notify_event_t::get_parent() {
  return connection->create_window(event->parent);
}

int16_t create_notify_event_t::get_x() {
  return event->x;
}

int16_t create_notify_event_t::get_y() {
  return event->y;
}

uint16_t create_notify_event_t::get_width() {
  return event->width;
}

uint16_t create_notify_event_t::get_height() {
  return event->height;
}

uint16_t create_notify_event_t::get_border_width() {
  return event->border_width;
}

}