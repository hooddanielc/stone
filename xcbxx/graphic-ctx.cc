#include <xcbxx/graphic-ctx.h>
#include <xcbxx/connection.h>

namespace xcbxx {

void graphic_ctx_t::poly_point(uint8_t coordinate_mode, uint32_t length, const xcb_point_t *points) {
  xcb_poly_point(
    connection->connection,
    coordinate_mode,
    win,
    context,
    length,
    points
  );
}

void graphic_ctx_t::poly_line(uint8_t coordinate_mode, uint32_t length, const xcb_point_t *points) {
  xcb_poly_line(
    connection->connection,
    coordinate_mode,
    win,
    context,
    length,
    points
  );
}

void graphic_ctx_t::poly_segment(uint32_t length, const xcb_segment_t *segments) {
  xcb_poly_segment(
    connection->connection,
    win,
    context,
    length,
    segments
  );
}

void graphic_ctx_t::poly_rectangle(uint32_t length, const xcb_rectangle_t *rectangles) {
  xcb_poly_rectangle(
    connection->connection,
    win,
    context,
    length,
    rectangles
  );
}

void graphic_ctx_t::poly_arc(uint32_t length, const xcb_arc_t *arcs) {
  xcb_poly_arc(
    connection->connection,
    win,
    context,
    length,
    arcs
  );
}

xcb_connection_t *graphic_ctx_t::get_connection() {
  return connection->connection;
}

};