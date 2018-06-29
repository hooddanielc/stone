#include <iostream>
#include <csignal>
#include <xcbxx/connection.h>

using namespace std;
using namespace xcbxx;

static bool run = true;

static std::shared_ptr<connection_t> connection;
static std::shared_ptr<glx_window_t> window;
static std::shared_ptr<glx_window_t> window2;

inline void event_loop() {
  xcb_generic_event_t *e;

  do {
    if ((e = connection->wait_for_event())) {
      std::cout << event_t::get_event_name(e->response_type & ~0x80) << std::endl;
      connection->emit_raw(e);
      if ((e->response_type & ~0x80) == XCB_MOTION_NOTIFY) {
        connection->flush();
      }
    }
  } while (run);
}

inline void draw() {
  glClearColor(0.2f, 0.9f, 0.9f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

inline void draw2() {
  glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

int main(int, char*[]) {
  connection = xcbxx::connection_t::make();

  connection->on<XCB_KEY_PRESS>([&](std::shared_ptr<key_press_event_t> e) {
    if (e->get_name() == "Escape") {
      run = false;
    }
  });

  uint32_t event_mask = (
    XCB_EVENT_MASK_NO_EVENT |
    XCB_EVENT_MASK_KEY_PRESS |
    XCB_EVENT_MASK_KEY_RELEASE |
    XCB_EVENT_MASK_BUTTON_PRESS |
    XCB_EVENT_MASK_BUTTON_RELEASE |
    XCB_EVENT_MASK_ENTER_WINDOW |
    XCB_EVENT_MASK_LEAVE_WINDOW |
    XCB_EVENT_MASK_POINTER_MOTION |
    XCB_EVENT_MASK_POINTER_MOTION_HINT |
    XCB_EVENT_MASK_BUTTON_1_MOTION |
    XCB_EVENT_MASK_BUTTON_2_MOTION |
    XCB_EVENT_MASK_BUTTON_3_MOTION |
    XCB_EVENT_MASK_BUTTON_4_MOTION |
    XCB_EVENT_MASK_BUTTON_5_MOTION |
    XCB_EVENT_MASK_BUTTON_MOTION |
    XCB_EVENT_MASK_KEYMAP_STATE |
    XCB_EVENT_MASK_EXPOSURE |
    XCB_EVENT_MASK_VISIBILITY_CHANGE |
    XCB_EVENT_MASK_STRUCTURE_NOTIFY |
    //XCB_EVENT_MASK_RESIZE_REDIRECT |
    XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY |
    //XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT |
    XCB_EVENT_MASK_FOCUS_CHANGE |
    XCB_EVENT_MASK_PROPERTY_CHANGE |
    XCB_EVENT_MASK_COLOR_MAP_CHANGE |
    XCB_EVENT_MASK_OWNER_GRAB_BUTTON
  );

  auto screen = connection->get_screen();
  window = connection->create_glx_window(
    0,
    0,
    150,
    150,
    10,
    screen->get_root(),
    static_cast<int>(screen->get_root_visual()),
    XCB_NONE,
    XCB_WINDOW_CLASS_INPUT_OUTPUT,
    event_mask
  );

  window2 = connection->create_glx_window(
    0,
    0,
    150,
    150,
    10,
    screen->get_root(),
    static_cast<int>(screen->get_root_visual()),
    XCB_NONE,
    XCB_WINDOW_CLASS_INPUT_OUTPUT,
    event_mask
  );

  window2->on_expose([&](std::shared_ptr<expose_event_t>) {
    window2->make_current();
    draw2();
    window2->swap_buffers();
  });

  window->on_expose([&](std::shared_ptr<expose_event_t>) {
    window->make_current();
    draw();
    window->swap_buffers();
  });

  window->on_enter_notify([&](std::shared_ptr<enter_notify_event_t>) {
    window->make_current();
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    window->swap_buffers();
  });

  window2->on_enter_notify([&](std::shared_ptr<enter_notify_event_t>) {
    window2->make_current();
    glClearColor(0.9f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    window2->swap_buffers();
  });

  connection->flush();

  event_loop();
  return 0;
}
