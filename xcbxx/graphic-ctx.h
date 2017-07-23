#pragma once

#include <xcb/xcb.h>
#include <xcbxx/connection.h>

namespace xcbxx {

class graphic_ctx_t {

public:
  friend class window_t;

  void poly_point(uint8_t coordinate_mode, uint32_t length, const xcb_point_t *points);

  void poly_line(uint8_t coordinate_mode, uint32_t length, const xcb_point_t *points);

  void poly_segment(uint32_t length, const xcb_segment_t *segments);

  void poly_rectangle(uint32_t length, const xcb_rectangle_t *rectangles);

  void poly_arc(uint32_t length, const xcb_arc_t *arcs);

private:

  std::shared_ptr<connection_t> connection;

  xcb_gcontext_t context;

  xcb_drawable_t win;

  xcb_connection_t *get_connection();

  graphic_ctx_t(
    std::shared_ptr<connection_t> connection_,
    xcb_drawable_t win_,
    uint32_t value_mask,
    const uint32_t *value_list
  ) : connection(connection_), context(xcb_generate_id(get_connection())), win(win_) {
    xcb_create_gc(get_connection(), context, win_, value_mask, value_list);
  }

};  // graphic_ctx_t

};  // xcbxx