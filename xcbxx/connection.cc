#include <xcbxx/connection.h>

namespace xcbxx {

void connection_t::throw_bad_cookie(const std::string &name, xcb_void_cookie_t cookie) {
  auto err = xcb_request_check(connection, cookie);

  if (err) {
    std::stringstream ss;
    ss << name << " threw error code " << err->error_code;
    throw std::runtime_error(ss.str());
  }
}

std::shared_ptr<connection_t> connection_t::make(const char *display_name, int *screen_num) {
  Display *display = XOpenDisplay(display_name);
  XSetEventQueueOwner(display, XCBOwnsEventQueue);

  if (!display) {
    throw std::runtime_error("Can't open display");
  }

  if (!screen_num) {
    screen_num = new int();
    *screen_num = DefaultScreen(display);
  }

  auto connection = XGetXCBConnection(display);

  if (!connection) {
    throw std::runtime_error("Can't get xcb connection from display");
  }

  auto err = xcb_connection_has_error(connection);

  switch(err) {
    case XCB_CONN_ERROR:
      throw std::runtime_error("XCB_CONN_ERROR");
    case XCB_CONN_CLOSED_EXT_NOTSUPPORTED:
      throw std::runtime_error("XCB_CONN_CLOSED_EXT_NOTSUPPORTED");
    case XCB_CONN_CLOSED_MEM_INSUFFICIENT:
      throw std::runtime_error("XCB_CONN_CLOSED_MEM_INSUFFICIENT");
    case XCB_CONN_CLOSED_REQ_LEN_EXCEED:
      throw std::runtime_error("XCB_CONN_CLOSED_REQ_LEN_EXCEED");
    case XCB_CONN_CLOSED_PARSE_ERR:
      throw std::runtime_error("XCB_CONN_CLOSED_PARSE_ERR");
    case XCB_CONN_CLOSED_INVALID_SCREEN:
      throw std::runtime_error("XCB_CONN_CLOSED_INVALID_SCREEN");
  }

  auto result = std::make_shared<connection_t>(connection, display, display_name, screen_num);
  result->weak_ref = result;
  return result;
}

xcb_generic_event_t *connection_t::wait_for_event() {
  return xcb_wait_for_event(connection);
}

xcb_generic_event_t *connection_t::poll_for_event() {
  return xcb_poll_for_event(connection);
}

int connection_t::get_screen_count() {
  return xcb_setup_roots_length(xcb_get_setup(connection));
}

connection_t::~connection_t() {
  XCloseDisplay(display);
}

const char *connection_t::get_display() {
  return display_name ? display_name : std::getenv("DISPLAY");
}

int *connection_t::get_screen_num() {
  return screen_num;
}

void connection_t::pause() {
  ::pause(); // hold client until Ctrl-C
}

std::shared_ptr<screen_t> connection_t::get_screen(int *num) {
  return std::make_shared<screen_t>(weak_ref.lock(), num);
}

int connection_t::flush() {
  return xcb_flush(connection);
}

std::shared_ptr<window_t> connection_t::create_window(
  xcb_window_t window
) {
  return std::make_shared<window_t>(weak_ref.lock(), window);
}

std::shared_ptr<window_t> connection_t::create_window(
  int16_t x,
  int16_t y,
  uint16_t width,
  uint16_t height,
  uint16_t border_width,
  xcb_window_t parent,
  xcb_visualid_t visual,
  uint8_t depth,
  uint16_t _class,
  uint32_t value_mask,
  const uint32_t *value_list
) {
  xcb_window_t window = xcb_generate_id(connection);

  auto cookie = xcb_create_window(
    connection,
    depth,
    window,
    parent,
    x,
    y,
    width,
    height,
    border_width,
    _class,
    visual,
    value_mask,
    value_list
  );

  throw_bad_cookie("xcb_create_window", cookie);
  return std::make_shared<window_t>(weak_ref.lock(), window);
}

std::shared_ptr<glx_window_t> connection_t::create_glx_window(
  int16_t x,
  int16_t y,
  uint16_t width,
  uint16_t height,
  uint16_t border_width,
  xcb_window_t parent,
  int visual_id,
  uint8_t depth,
  uint16_t _class,
  uint32_t eventmask
) {

  // query framebuffer configs
  GLXFBConfig *fb_configs = nullptr;
  int num_fb_configs = 0;

  fb_configs = glXGetFBConfigs(
    display,
    *screen_num,
    &num_fb_configs
  );

  if (!fb_configs || num_fb_configs == 0) {
    throw std::runtime_error("failed to query framebuffer configs");
  }

  // select first framebuffer config and query visual id
  GLXFBConfig fb_config = fb_configs[0];

  glXGetFBConfigAttrib(
    display,
    fb_config,
    GLX_VISUAL_ID,
    &visual_id
  );

  GLXContext glx_context = glXCreateNewContext(
    display,
    fb_config,
    GLX_RGBA_TYPE,
    nullptr,
    True
  );

  if (!glx_context) {
    throw std::runtime_error("creating glx context failed");
  }

  // create xcb_window
  xcb_window_t window = xcb_generate_id(connection);
  xcb_colormap_t colormap = xcb_generate_id(connection);

  auto cookie_color_map = xcb_create_colormap(
    connection,
    XCB_COLORMAP_ALLOC_NONE,
    colormap,
    get_screen()->get_root(),
    static_cast<unsigned int>(visual_id)
  );

  throw_bad_cookie("xcb_create_colormap", cookie_color_map);
  uint32_t value_mask = XCB_CW_EVENT_MASK | XCB_CW_COLORMAP;
  uint32_t value_list[] = { eventmask, colormap, 0 };

  auto cookie = xcb_create_window(
    connection,
    depth,
    window,
    parent,
    x,
    y,
    width,
    height,
    border_width,
    _class,
    static_cast<unsigned int>(visual_id),
    value_mask,
    value_list
  );

  throw_bad_cookie("xcb_create_window", cookie);

  // create glx window
  GLXWindow glx_window = glXCreateWindow(
    display,
    fb_config,
    window,
    nullptr
  );

  GLXDrawable glx_drawable = glx_window;

  auto res = std::make_shared<glx_window_t>(
    weak_ref.lock(),
    window,
    visual_id,
    glx_context,
    glx_window
  );

  res->show();

  // todo check if window is shown, if it is, then 
  // make context current, otherwise make context current in
  // show override
  if (!glXMakeContextCurrent(
    display,
    glx_drawable,
    glx_drawable,
    glx_context
  )) {
    throw std::runtime_error("setting glx context current failed");
  }

  return res;
}

};  // xcbxx
