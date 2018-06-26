#pragma once

#include <functional>
#include <vector>
#include <xcbxx/events/button-press-event.h>
#include <xcbxx/events/button-release-event.h>
#include <xcbxx/events/circulate-notify-event.h>
#include <xcbxx/events/circulate-request-event.h>
#include <xcbxx/events/client-message-event.h>
#include <xcbxx/events/colormap-notify-event.h>
#include <xcbxx/events/configure-notify-event.h>
#include <xcbxx/events/configure-request-event.h>
#include <xcbxx/events/create-notify-event.h>
#include <xcbxx/events/destroy-notify-event.h>
#include <xcbxx/events/enter-notify-event.h>
#include <xcbxx/events/expose-event.h>
#include <xcbxx/events/focus-in-event.h>
#include <xcbxx/events/focus-out-event.h>
#include <xcbxx/events/graphics-exposure-event.h>
#include <xcbxx/events/gravity-notify-event.h>
#include <xcbxx/events/key-press-event.h>
#include <xcbxx/events/key-release-event.h>
#include <xcbxx/events/keymap-notify-event.h>
#include <xcbxx/events/leave-notify-event.h>
#include <xcbxx/events/map-notify-event.h>
#include <xcbxx/events/map-request-event.h>
#include <xcbxx/events/mapping-notify-event.h>
#include <xcbxx/events/motion-notify-event.h>
#include <xcbxx/events/no-exposure-event.h>
#include <xcbxx/events/property-notify-event.h>
#include <xcbxx/events/reparent-notify-event.h>
#include <xcbxx/events/resize-request-event.h>
#include <xcbxx/events/selection-clear-event.h>
#include <xcbxx/events/selection-notify-event.h>
#include <xcbxx/events/selection-request-event.h>
#include <xcbxx/events/unmap-notify-event.h>
#include <xcbxx/events/visibility-notify-event.h>

namespace xcbxx {

template <unsigned int xcb_enum_type> struct xcb_to_xcbxx_event_t { using type = event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_KEY_PRESS> { using type = key_press_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_KEY_RELEASE> { using type = key_release_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_BUTTON_PRESS> { using type = button_press_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_BUTTON_RELEASE> { using type = button_release_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_MOTION_NOTIFY> { using type = motion_notify_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_ENTER_NOTIFY> { using type = enter_notify_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_LEAVE_NOTIFY> { using type = leave_notify_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_FOCUS_IN> { using type = focus_in_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_FOCUS_OUT> { using type = focus_out_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_KEYMAP_NOTIFY> { using type = keymap_notify_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_EXPOSE> { using type = expose_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_GRAPHICS_EXPOSURE> { using type = graphics_exposure_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_NO_EXPOSURE> { using type = no_exposure_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_VISIBILITY_NOTIFY> { using type = visibility_notify_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_CREATE_NOTIFY> { using type = create_notify_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_DESTROY_NOTIFY> { using type = destroy_notify_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_UNMAP_NOTIFY> { using type = unmap_notify_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_MAP_NOTIFY> { using type = map_notify_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_MAP_REQUEST> { using type = map_request_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_REPARENT_NOTIFY> { using type = reparent_notify_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_CONFIGURE_NOTIFY> { using type = configure_notify_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_CONFIGURE_REQUEST> { using type = configure_request_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_GRAVITY_NOTIFY> { using type = gravity_notify_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_RESIZE_REQUEST> { using type = resize_request_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_CIRCULATE_REQUEST> { using type = circulate_request_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_PROPERTY_NOTIFY> { using type = property_notify_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_SELECTION_CLEAR> { using type = selection_clear_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_SELECTION_REQUEST> { using type = selection_request_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_SELECTION_NOTIFY> { using type = selection_notify_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_COLORMAP_NOTIFY> { using type = colormap_notify_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_CLIENT_MESSAGE> { using type = client_message_event_t; };
template <> struct xcb_to_xcbxx_event_t<XCB_MAPPING_NOTIFY> { using type = mapping_notify_event_t; };

template <unsigned int xcb_enum_type>
class event_register_t {

  using xcbxx_event_type_t = typename xcb_to_xcbxx_event_t<xcb_enum_type>::type;

  friend class master_event_register_t;

  using callback_t = std::function<void(std::shared_ptr<xcbxx_event_type_t>)>;

  std::vector<callback_t> events;

  void on(const callback_t &e) {
    events.push_back(e);
  }

  void emit(std::shared_ptr<xcbxx_event_type_t> e) {
    for (auto &cb: events) {
      cb(e);
    }
  }

};  // event_register_t

class master_event_register_t {

  friend class connection_t;

  event_register_t<XCB_KEY_PRESS> key_press_register;
  event_register_t<XCB_KEY_RELEASE> key_release_register;
  event_register_t<XCB_BUTTON_PRESS> button_press_register;
  event_register_t<XCB_BUTTON_RELEASE> button_release_register;
  event_register_t<XCB_MOTION_NOTIFY> motion_notify_register;
  event_register_t<XCB_ENTER_NOTIFY> enter_notify_register;
  event_register_t<XCB_LEAVE_NOTIFY> leave_notify_register;
  event_register_t<XCB_FOCUS_IN> focus_in_register;
  event_register_t<XCB_FOCUS_OUT> focus_out_register;
  event_register_t<XCB_KEYMAP_NOTIFY> keymap_notify_register;
  event_register_t<XCB_EXPOSE> expose_register;
  event_register_t<XCB_GRAPHICS_EXPOSURE> graphics_exposure_register;
  event_register_t<XCB_NO_EXPOSURE> no_exposure_register;
  event_register_t<XCB_VISIBILITY_NOTIFY> visibility_notify_register;
  event_register_t<XCB_CREATE_NOTIFY> create_notify_register;
  event_register_t<XCB_DESTROY_NOTIFY> destroy_notify_register;
  event_register_t<XCB_UNMAP_NOTIFY> unmap_notify_register;
  event_register_t<XCB_MAP_NOTIFY> map_notify_register;
  event_register_t<XCB_MAP_REQUEST> map_request_register;
  event_register_t<XCB_REPARENT_NOTIFY> reparent_notify_register;
  event_register_t<XCB_CONFIGURE_NOTIFY> configure_notify_register;
  event_register_t<XCB_CONFIGURE_REQUEST> configure_request_register;
  event_register_t<XCB_GRAVITY_NOTIFY> gravity_notify_register;
  event_register_t<XCB_RESIZE_REQUEST> resize_request_register;
  event_register_t<XCB_CIRCULATE_REQUEST> circulate_request_register;
  event_register_t<XCB_PROPERTY_NOTIFY> property_notify_register;
  event_register_t<XCB_SELECTION_CLEAR> selection_clear_register;
  event_register_t<XCB_SELECTION_REQUEST> selection_request_register;
  event_register_t<XCB_SELECTION_NOTIFY> selection_notify_register;
  event_register_t<XCB_COLORMAP_NOTIFY> colormap_notify_register;
  event_register_t<XCB_CLIENT_MESSAGE> client_message_register;
  event_register_t<XCB_MAPPING_NOTIFY> mapping_notify_register;

  template <unsigned int xcb_enum_type> event_register_t<xcb_enum_type> &get();

  template <unsigned int xcb_enum_type, typename cb_t> void on(const cb_t &cb) {
    get<xcb_enum_type>().on(cb);
  }

  template <unsigned int xcb_enum_type, typename ev_t> void emit(ev_t ev) {
    get<xcb_enum_type>().emit(ev);
  }

  void emit_raw(std::shared_ptr<connection_t> connection, xcb_generic_event_t *e) {
    switch(e->response_type & ~0x80) {
      case XCB_KEY_PRESS: return emit<XCB_KEY_PRESS>(event_t::make<key_press_event_t>(connection, e, XCB_KEY_PRESS)); break;
      case XCB_KEY_RELEASE: return emit<XCB_KEY_RELEASE>(event_t::make<key_release_event_t>(connection, e, XCB_KEY_RELEASE)); break;
      case XCB_BUTTON_PRESS: return emit<XCB_BUTTON_PRESS>(event_t::make<button_press_event_t>(connection, e, XCB_BUTTON_PRESS)); break;
      case XCB_BUTTON_RELEASE: return emit<XCB_BUTTON_RELEASE>(event_t::make<button_release_event_t>(connection, e, XCB_BUTTON_RELEASE)); break;
      case XCB_MOTION_NOTIFY: return emit<XCB_MOTION_NOTIFY>(event_t::make<motion_notify_event_t>(connection, e, XCB_MOTION_NOTIFY)); break;
      case XCB_ENTER_NOTIFY: return emit<XCB_ENTER_NOTIFY>(event_t::make<enter_notify_event_t>(connection, e, XCB_ENTER_NOTIFY)); break;
      case XCB_LEAVE_NOTIFY: return emit<XCB_LEAVE_NOTIFY>(event_t::make<leave_notify_event_t>(connection, e, XCB_LEAVE_NOTIFY)); break;
      case XCB_FOCUS_IN: return emit<XCB_FOCUS_IN>(event_t::make<focus_in_event_t>(connection, e, XCB_FOCUS_IN)); break;
      case XCB_FOCUS_OUT: return emit<XCB_FOCUS_OUT>(event_t::make<focus_out_event_t>(connection, e, XCB_FOCUS_OUT)); break;
      case XCB_KEYMAP_NOTIFY: return emit<XCB_KEYMAP_NOTIFY>(event_t::make<keymap_notify_event_t>(connection, e, XCB_KEYMAP_NOTIFY)); break;
      case XCB_EXPOSE: return emit<XCB_EXPOSE>(event_t::make<expose_event_t>(connection, e, XCB_EXPOSE)); break;
      case XCB_GRAPHICS_EXPOSURE: return emit<XCB_GRAPHICS_EXPOSURE>(event_t::make<graphics_exposure_event_t>(connection, e, XCB_GRAPHICS_EXPOSURE)); break;
      case XCB_NO_EXPOSURE: return emit<XCB_NO_EXPOSURE>(event_t::make<no_exposure_event_t>(connection, e, XCB_NO_EXPOSURE)); break;
      case XCB_VISIBILITY_NOTIFY: return emit<XCB_VISIBILITY_NOTIFY>(event_t::make<visibility_notify_event_t>(connection, e, XCB_VISIBILITY_NOTIFY)); break;
      case XCB_CREATE_NOTIFY: return emit<XCB_CREATE_NOTIFY>(event_t::make<create_notify_event_t>(connection, e, XCB_CREATE_NOTIFY)); break;
      case XCB_DESTROY_NOTIFY: return emit<XCB_DESTROY_NOTIFY>(event_t::make<destroy_notify_event_t>(connection, e, XCB_DESTROY_NOTIFY)); break;
      case XCB_UNMAP_NOTIFY: return emit<XCB_UNMAP_NOTIFY>(event_t::make<unmap_notify_event_t>(connection, e, XCB_UNMAP_NOTIFY)); break;
      case XCB_MAP_NOTIFY: return emit<XCB_MAP_NOTIFY>(event_t::make<map_notify_event_t>(connection, e, XCB_MAP_NOTIFY)); break;
      case XCB_MAP_REQUEST: return emit<XCB_MAP_REQUEST>(event_t::make<map_request_event_t>(connection, e, XCB_MAP_REQUEST)); break;
      case XCB_REPARENT_NOTIFY: return emit<XCB_REPARENT_NOTIFY>(event_t::make<reparent_notify_event_t>(connection, e, XCB_REPARENT_NOTIFY)); break;
      case XCB_CONFIGURE_NOTIFY: return emit<XCB_CONFIGURE_NOTIFY>(event_t::make<configure_notify_event_t>(connection, e, XCB_CONFIGURE_NOTIFY)); break;
      case XCB_CONFIGURE_REQUEST: return emit<XCB_CONFIGURE_REQUEST>(event_t::make<configure_request_event_t>(connection, e, XCB_CONFIGURE_REQUEST)); break;
      case XCB_GRAVITY_NOTIFY: return emit<XCB_GRAVITY_NOTIFY>(event_t::make<gravity_notify_event_t>(connection, e, XCB_GRAVITY_NOTIFY)); break;
      case XCB_RESIZE_REQUEST: return emit<XCB_RESIZE_REQUEST>(event_t::make<resize_request_event_t>(connection, e, XCB_RESIZE_REQUEST)); break;
      case XCB_CIRCULATE_REQUEST: return emit<XCB_CIRCULATE_REQUEST>(event_t::make<circulate_request_event_t>(connection, e, XCB_CIRCULATE_REQUEST)); break;
      case XCB_PROPERTY_NOTIFY: return emit<XCB_PROPERTY_NOTIFY>(event_t::make<property_notify_event_t>(connection, e, XCB_PROPERTY_NOTIFY)); break;
      case XCB_SELECTION_CLEAR: return emit<XCB_SELECTION_CLEAR>(event_t::make<selection_clear_event_t>(connection, e, XCB_SELECTION_CLEAR)); break;
      case XCB_SELECTION_REQUEST: return emit<XCB_SELECTION_REQUEST>(event_t::make<selection_request_event_t>(connection, e, XCB_SELECTION_REQUEST)); break;
      case XCB_SELECTION_NOTIFY: return emit<XCB_SELECTION_NOTIFY>(event_t::make<selection_notify_event_t>(connection, e, XCB_SELECTION_NOTIFY)); break;
      case XCB_COLORMAP_NOTIFY: return emit<XCB_COLORMAP_NOTIFY>(event_t::make<colormap_notify_event_t>(connection, e, XCB_COLORMAP_NOTIFY)); break;
      case XCB_CLIENT_MESSAGE: return emit<XCB_CLIENT_MESSAGE>(event_t::make<client_message_event_t>(connection, e, XCB_CLIENT_MESSAGE)); break;
      case XCB_MAPPING_NOTIFY: return emit<XCB_MAPPING_NOTIFY>(event_t::make<mapping_notify_event_t>(connection, e, XCB_MAPPING_NOTIFY)); break;
      default:
        std::stringstream ss;
        ss << "Cannot Automake Event #" << e->response_type << " Event Unknown" << std::endl;
        throw std::runtime_error(ss.str());
    }
  }

};  // master_event_register


template<> inline event_register_t<XCB_KEY_PRESS> &master_event_register_t::get<XCB_KEY_PRESS>() { return key_press_register; }
template<> inline event_register_t<XCB_KEY_RELEASE> &master_event_register_t::get<XCB_KEY_RELEASE>() { return key_release_register; }
template<> inline event_register_t<XCB_BUTTON_PRESS> &master_event_register_t::get<XCB_BUTTON_PRESS>() { return button_press_register; }
template<> inline event_register_t<XCB_BUTTON_RELEASE> &master_event_register_t::get<XCB_BUTTON_RELEASE>() { return button_release_register; }
template<> inline event_register_t<XCB_MOTION_NOTIFY> &master_event_register_t::get<XCB_MOTION_NOTIFY>() { return motion_notify_register; }
template<> inline event_register_t<XCB_ENTER_NOTIFY> &master_event_register_t::get<XCB_ENTER_NOTIFY>() { return enter_notify_register; }
template<> inline event_register_t<XCB_LEAVE_NOTIFY> &master_event_register_t::get<XCB_LEAVE_NOTIFY>() { return leave_notify_register; }
template<> inline event_register_t<XCB_FOCUS_IN> &master_event_register_t::get<XCB_FOCUS_IN>() { return focus_in_register; }
template<> inline event_register_t<XCB_FOCUS_OUT> &master_event_register_t::get<XCB_FOCUS_OUT>() { return focus_out_register; }
template<> inline event_register_t<XCB_KEYMAP_NOTIFY> &master_event_register_t::get<XCB_KEYMAP_NOTIFY>() { return keymap_notify_register; }
template<> inline event_register_t<XCB_EXPOSE> &master_event_register_t::get<XCB_EXPOSE>() { return expose_register; }
template<> inline event_register_t<XCB_GRAPHICS_EXPOSURE> &master_event_register_t::get<XCB_GRAPHICS_EXPOSURE>() { return graphics_exposure_register; }
template<> inline event_register_t<XCB_NO_EXPOSURE> &master_event_register_t::get<XCB_NO_EXPOSURE>() { return no_exposure_register; }
template<> inline event_register_t<XCB_VISIBILITY_NOTIFY> &master_event_register_t::get<XCB_VISIBILITY_NOTIFY>() { return visibility_notify_register; }
template<> inline event_register_t<XCB_CREATE_NOTIFY> &master_event_register_t::get<XCB_CREATE_NOTIFY>() { return create_notify_register; }
template<> inline event_register_t<XCB_DESTROY_NOTIFY> &master_event_register_t::get<XCB_DESTROY_NOTIFY>() { return destroy_notify_register; }
template<> inline event_register_t<XCB_UNMAP_NOTIFY> &master_event_register_t::get<XCB_UNMAP_NOTIFY>() { return unmap_notify_register; }
template<> inline event_register_t<XCB_MAP_NOTIFY> &master_event_register_t::get<XCB_MAP_NOTIFY>() { return map_notify_register; }
template<> inline event_register_t<XCB_MAP_REQUEST> &master_event_register_t::get<XCB_MAP_REQUEST>() { return map_request_register; }
template<> inline event_register_t<XCB_REPARENT_NOTIFY> &master_event_register_t::get<XCB_REPARENT_NOTIFY>() { return reparent_notify_register; }
template<> inline event_register_t<XCB_CONFIGURE_NOTIFY> &master_event_register_t::get<XCB_CONFIGURE_NOTIFY>() { return configure_notify_register; }
template<> inline event_register_t<XCB_CONFIGURE_REQUEST> &master_event_register_t::get<XCB_CONFIGURE_REQUEST>() { return configure_request_register; }
template<> inline event_register_t<XCB_GRAVITY_NOTIFY> &master_event_register_t::get<XCB_GRAVITY_NOTIFY>() { return gravity_notify_register; }
template<> inline event_register_t<XCB_RESIZE_REQUEST> &master_event_register_t::get<XCB_RESIZE_REQUEST>() { return resize_request_register; }
template<> inline event_register_t<XCB_CIRCULATE_REQUEST> &master_event_register_t::get<XCB_CIRCULATE_REQUEST>() { return circulate_request_register; }
template<> inline event_register_t<XCB_PROPERTY_NOTIFY> &master_event_register_t::get<XCB_PROPERTY_NOTIFY>() { return property_notify_register; }
template<> inline event_register_t<XCB_SELECTION_CLEAR> &master_event_register_t::get<XCB_SELECTION_CLEAR>() { return selection_clear_register; }
template<> inline event_register_t<XCB_SELECTION_REQUEST> &master_event_register_t::get<XCB_SELECTION_REQUEST>() { return selection_request_register; }
template<> inline event_register_t<XCB_SELECTION_NOTIFY> &master_event_register_t::get<XCB_SELECTION_NOTIFY>() { return selection_notify_register; }
template<> inline event_register_t<XCB_COLORMAP_NOTIFY> &master_event_register_t::get<XCB_COLORMAP_NOTIFY>() { return colormap_notify_register; }
template<> inline event_register_t<XCB_CLIENT_MESSAGE> &master_event_register_t::get<XCB_CLIENT_MESSAGE>() { return client_message_register; }
template<> inline event_register_t<XCB_MAPPING_NOTIFY> &master_event_register_t::get<XCB_MAPPING_NOTIFY>() { return mapping_notify_register; }

}
