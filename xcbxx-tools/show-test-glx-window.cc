#include <iostream>
#include <csignal>
#include <xcbxx/connection.h>

using namespace std;
using namespace xcbxx;

bool run = true;

std::shared_ptr<connection_t> connection;
std::shared_ptr<glx_window_t> window;

void event_loop() {
  xcb_generic_event_t *e;

  do {
    if ((e = connection->wait_for_event())) {
      std::cout << event_t::get_event_name(e->response_type & ~0x80) << std::endl;
      connection->emit_raw(e);
    }
  } while (run);
}

void draw() {
  glClearColor(0.2, 0.9, 0.9, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
}

int main(int, char*[]) {
  connection = xcbxx::connection_t::make();

  connection->on<XCB_KEY_PRESS>([](std::shared_ptr<key_press_event_t>) {
    run = false;
  });

  connection->on<XCB_EXPOSE>([&](std::shared_ptr<expose_event_t>) {
    draw();
    window->swap_buffers();
  });

  auto screen = connection->get_screen();
  window = connection->create_glx_window(
    0,
    0,
    150,
    150,
    10,
    screen->get_root(),
    screen->get_root_visual(),
    XCB_COPY_FROM_PARENT,
    XCB_WINDOW_CLASS_INPUT_OUTPUT,
    XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_KEY_PRESS
  );

  connection->flush();

  event_loop();
  return 0;
}
