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

  connection->on<XCB_MAP_REQUEST>([](std::shared_ptr<map_request_event_t> e) {
    std::cout << "show window as is" << std::endl;
    auto win = e->get_window();
    win->show();
  });

  auto screen = connection->get_screen();
  auto root_window = screen->get_root_window();

  const uint32_t select_input_val[] = {
    XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT | XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY
    | XCB_EVENT_MASK_ENTER_WINDOW | XCB_EVENT_MASK_LEAVE_WINDOW
    | XCB_EVENT_MASK_STRUCTURE_NOTIFY | XCB_EVENT_MASK_PROPERTY_CHANGE
    | XCB_EVENT_MASK_BUTTON_PRESS | XCB_EVENT_MASK_BUTTON_RELEASE
    | XCB_EVENT_MASK_FOCUS_CHANGE
  };

  root_window->change_attributes(XCB_CW_EVENT_MASK, select_input_val);
  connection->flush();

  event_loop();
  return 0;
}
