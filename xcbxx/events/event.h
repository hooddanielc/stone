#pragma once

#include <memory>
#include <sstream>
#include <string>
#include <map>
#include <xcb/xcb.h>

namespace xcbxx {

class connection_t;

class event_t {

protected:

  xcb_generic_event_t *xevent;

public:

  event_t(xcb_generic_event_t *event_): xevent(event_) {}

  ~event_t();

  static const std::map<unsigned char, std::string> event_types;

  static std::string get_event_name(unsigned char macro);

  template <typename event_type_t>
  static std::shared_ptr<event_type_t>
  make(
    std::shared_ptr<connection_t> connection,
    xcb_generic_event_t *e,
    uint8_t assert_response_type
  ) {
    if ((e->response_type & ~0x80) != assert_response_type) {
      std::stringstream ss;
      ss << "can't create event " << event_type_t::name << " "
         << "with ";
      if (event_types.count(e->response_type & ~0x80)) {
        ss << event_types.at(e->response_type & ~0x80);
      } else {
        ss << " unknown event type";
      }
      throw std::runtime_error(ss.str());
    }

    auto ref = new event_type_t(connection, e);
    return std::shared_ptr<event_type_t>(ref);
  }


};  // event_t

}
