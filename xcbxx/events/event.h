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

  xcb_generic_event_t *event;

  event_t(xcb_generic_event_t *event_): event(event_) {}

  virtual ~event_t() {
    free(event);
  }

public:

  static const std::map<unsigned, std::string> event_types;

  static std::string get_event_name(unsigned int macro);

  template <typename event_type_t>
  static std::shared_ptr<event_type_t>
  make(
    std::shared_ptr<connection_t> connection,
    xcb_generic_event_t *e,
    uint8_t assert_response_type
  ) {
    if (e->response_type != assert_response_type) {
      std::stringstream ss;
      ss << "can't create event " << event_type_t::name << " "
         << "with " << e->response_type;
      throw std::runtime_error(ss.str());
    }

    auto ref = new event_type_t(connection, e);
    return std::shared_ptr<event_type_t>(ref);
  }


};  // event_t

}