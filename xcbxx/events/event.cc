#include <xcbxx/events/event.h>

namespace xcbxx {

std::string event_t::get_event_name(unsigned macro) {
  switch (macro) {
    case XCB_KEY_PRESS: return "XCB_KEY_PRESS"; break;
    case XCB_KEY_RELEASE: return "XCB_KEY_RELEASE"; break;
    case XCB_BUTTON_PRESS: return "XCB_BUTTON_PRESS"; break;
    case XCB_BUTTON_RELEASE: return "XCB_BUTTON_RELEASE"; break;
    case XCB_MOTION_NOTIFY: return "XCB_MOTION_NOTIFY"; break;
    case XCB_ENTER_NOTIFY: return "XCB_ENTER_NOTIFY"; break;
    case XCB_LEAVE_NOTIFY: return "XCB_LEAVE_NOTIFY"; break;
    case XCB_FOCUS_IN: return "XCB_FOCUS_IN"; break;
    case XCB_FOCUS_OUT: return "XCB_FOCUS_OUT"; break;
    case XCB_KEYMAP_NOTIFY: return "XCB_KEYMAP_NOTIFY"; break;
    case XCB_EXPOSE: return "XCB_EXPOSE"; break;
    case XCB_GRAPHICS_EXPOSURE: return "XCB_GRAPHICS_EXPOSURE"; break;
    case XCB_NO_EXPOSURE: return "XCB_NO_EXPOSURE"; break;
    case XCB_VISIBILITY_NOTIFY: return "XCB_VISIBILITY_NOTIFY"; break;
    case XCB_CREATE_NOTIFY: return "XCB_CREATE_NOTIFY"; break;
    case XCB_DESTROY_NOTIFY: return "XCB_DESTROY_NOTIFY"; break;
    case XCB_UNMAP_NOTIFY: return "XCB_UNMAP_NOTIFY"; break;
    case XCB_MAP_NOTIFY: return "XCB_MAP_NOTIFY"; break;
    case XCB_MAP_REQUEST: return "XCB_MAP_REQUEST"; break;
    case XCB_REPARENT_NOTIFY: return "XCB_REPARENT_NOTIFY"; break;
    case XCB_CONFIGURE_NOTIFY: return "XCB_CONFIGURE_NOTIFY"; break;
    case XCB_CONFIGURE_REQUEST: return "XCB_CONFIGURE_REQUEST"; break;
    case XCB_GRAVITY_NOTIFY: return "XCB_GRAVITY_NOTIFY"; break;
    case XCB_RESIZE_REQUEST: return "XCB_RESIZE_REQUEST"; break;
    case XCB_CIRCULATE_REQUEST: return "XCB_CIRCULATE_REQUEST"; break;
    case XCB_PROPERTY_NOTIFY: return "XCB_PROPERTY_NOTIFY"; break;
    case XCB_SELECTION_CLEAR: return "XCB_SELECTION_CLEAR"; break;
    case XCB_SELECTION_REQUEST: return "XCB_SELECTION_REQUEST"; break;
    case XCB_SELECTION_NOTIFY: return "XCB_SELECTION_NOTIFY"; break;
    case XCB_COLORMAP_NOTIFY: return "XCB_COLORMAP_NOTIFY"; break;
    case XCB_CLIENT_MESSAGE: return "XCB_CLIENT_MESSAGE"; break;
    case XCB_MAPPING_NOTIFY: return "XCB_MAPPING_NOTIFY"; break;
    default:
      std::stringstream ss;
      ss << "unknown " << macro;
      return ss.str();
  }
}

}