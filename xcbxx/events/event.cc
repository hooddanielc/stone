#include <xcbxx/events/event.h>

namespace xcbxx {

const std::map<unsigned, std::string> event_t::event_types = {
  { XCB_KEY_PRESS, "XCB_KEY_PRESS" },
  { XCB_KEY_RELEASE, "XCB_KEY_RELEASE" },
  { XCB_BUTTON_PRESS, "XCB_BUTTON_PRESS" },
  { XCB_BUTTON_RELEASE, "XCB_BUTTON_RELEASE" },
  { XCB_MOTION_NOTIFY, "XCB_MOTION_NOTIFY" },
  { XCB_ENTER_NOTIFY, "XCB_ENTER_NOTIFY" },
  { XCB_LEAVE_NOTIFY, "XCB_LEAVE_NOTIFY" },
  { XCB_FOCUS_IN, "XCB_FOCUS_IN" },
  { XCB_FOCUS_OUT, "XCB_FOCUS_OUT" },
  { XCB_KEYMAP_NOTIFY, "XCB_KEYMAP_NOTIFY" },
  { XCB_EXPOSE, "XCB_EXPOSE" },
  { XCB_GRAPHICS_EXPOSURE, "XCB_GRAPHICS_EXPOSURE" },
  { XCB_NO_EXPOSURE, "XCB_NO_EXPOSURE" },
  { XCB_VISIBILITY_NOTIFY, "XCB_VISIBILITY_NOTIFY" },
  { XCB_CREATE_NOTIFY, "XCB_CREATE_NOTIFY" },
  { XCB_DESTROY_NOTIFY, "XCB_DESTROY_NOTIFY" },
  { XCB_UNMAP_NOTIFY, "XCB_UNMAP_NOTIFY" },
  { XCB_MAP_NOTIFY, "XCB_MAP_NOTIFY" },
  { XCB_MAP_REQUEST, "XCB_MAP_REQUEST" },
  { XCB_REPARENT_NOTIFY, "XCB_REPARENT_NOTIFY" },
  { XCB_CONFIGURE_NOTIFY, "XCB_CONFIGURE_NOTIFY" },
  { XCB_CONFIGURE_REQUEST, "XCB_CONFIGURE_REQUEST" },
  { XCB_GRAVITY_NOTIFY, "XCB_GRAVITY_NOTIFY" },
  { XCB_RESIZE_REQUEST, "XCB_RESIZE_REQUEST" },
  { XCB_CIRCULATE_REQUEST, "XCB_CIRCULATE_REQUEST" },
  { XCB_PROPERTY_NOTIFY, "XCB_PROPERTY_NOTIFY" },
  { XCB_SELECTION_CLEAR, "XCB_SELECTION_CLEAR" },
  { XCB_SELECTION_REQUEST, "XCB_SELECTION_REQUEST" },
  { XCB_SELECTION_NOTIFY, "XCB_SELECTION_NOTIFY" },
  { XCB_COLORMAP_NOTIFY, "XCB_COLORMAP_NOTIFY" },
  { XCB_CLIENT_MESSAGE, "XCB_CLIENT_MESSAGE" },
  { XCB_MAPPING_NOTIFY, "XCB_MAPPING_NOTIFY" }
};

std::string event_t::get_event_name(unsigned int macro) {
  if (event_types.count(macro)) {
    return event_types.at(macro);
  }

  std::stringstream ss;
  ss << "UNKNOWN " << macro;
  return ss.str();
}

}