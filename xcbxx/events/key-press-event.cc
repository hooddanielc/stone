#include "key-press-event.h"
#include <xcbxx/connection.h>

namespace xcbxx {

xcb_keycode_t key_press_event_t::get_keycode() {  
  return event->detail;
}

std::string key_press_event_t::get_name() {
  return connection->get_keysym_str(event->detail);
}

}
