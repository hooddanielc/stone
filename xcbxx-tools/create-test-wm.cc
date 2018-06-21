/*
 * This program is meant to run as a window manager.
 */

#include <iostream>
#include <csignal>
#include <xcbxx/connection.h>

using namespace std;
using namespace xcbxx;

bool run = true;

std::shared_ptr<connection_t> connection;

void event_loop() {
  xcb_generic_event_t *e;

  do {
    if ((e = connection->wait_for_event())) {
      std::cout << event_t::get_event_name(e->response_type & ~0x80) << std::endl;
      connection->emit_raw(e);
    }
  } while (run);
}

int main(int, char*[]) {

  connection = xcbxx::connection_t::make();

  connection->on<XCB_CONFIGURE_NOTIFY>([](std::shared_ptr<configure_notify_event_t> e) {
    std::cout << "xcb configure notify" << std::endl;
    std::cout << "window width " << e->get_width() << std::endl;
    std::cout << "window height " << e->get_height() << std::endl;
  });

  connection->on<XCB_CREATE_NOTIFY>([](std::shared_ptr<create_notify_event_t> e) {
    std::cout << "xcb create notify" << std::endl;
    std::cout << "window width " << e->get_width() << std::endl;
    std::cout << "window height " << e->get_height() << std::endl;
  });

  connection->on<XCB_MAP_REQUEST>([](std::shared_ptr<map_request_event_t> e) {
    uint16_t mask = 0;
    mask |= XCB_CONFIG_WINDOW_X;
    mask |= XCB_CONFIG_WINDOW_Y;
    mask |= XCB_CONFIG_WINDOW_WIDTH;
    mask |= XCB_CONFIG_WINDOW_HEIGHT;

    auto screen = connection->get_screen();

    const uint32_t values[] = {
      0,
      0,
      screen->get_width_in_pixels(),
      screen->get_height_in_pixels()
    };

    auto win = e->get_window();
    win->configure_window(mask, values);
    win->show();
    connection->flush();
  });

  auto screen = connection->get_screen();
  auto root_window = screen->get_root_window();

  const uint32_t select_input_val[] = {
    XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT |
    XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY |
    XCB_EVENT_MASK_ENTER_WINDOW |
    XCB_EVENT_MASK_LEAVE_WINDOW |
    XCB_EVENT_MASK_STRUCTURE_NOTIFY |
    XCB_EVENT_MASK_PROPERTY_CHANGE |
    XCB_EVENT_MASK_BUTTON_PRESS |
    XCB_EVENT_MASK_BUTTON_RELEASE |
    XCB_EVENT_MASK_FOCUS_CHANGE
  };

  root_window->change_attributes(XCB_CW_EVENT_MASK, select_input_val);
  connection->flush();

  event_loop();
  return 0;
}
