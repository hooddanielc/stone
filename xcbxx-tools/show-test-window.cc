#include <xcbxx/connection.h>

int main(int, char*[]) {
  auto connection = xcbxx::connection_t::make();
  auto screen = connection->get_screen();

  // create window
  uint32_t values[] = { screen->get_white_pixel(), XCB_EVENT_MASK_EXPOSURE };
  auto window = connection->create_window(
    0,
    0,
    150,
    150,
    10,
    screen->get_root(),
    screen->get_root_visual(),
    XCB_COPY_FROM_PARENT,
    XCB_WINDOW_CLASS_INPUT_OUTPUT,
    XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK,
    values
  );

  // create graphic context
  values[0] = screen->get_black_pixel();
  values[1] = 0;
  auto ctx = window->make_graphic_ctx(
    XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES,
    values
  );

  window->show();
  connection->flush();


  /* geometric objects */
  xcb_point_t points[] = {
    {10, 10},
    {10, 20},
    {20, 10},
    {20, 20}
  };

  xcb_point_t polyline[] = {
    {50, 10},
    { 5, 20},
    {25,-20},
    {10, 10}
  };

  xcb_segment_t segments[] = {
    {100, 10, 140, 30},
    {110, 25, 130, 60}
  };

  xcb_rectangle_t rectangles[] = {
    { 10, 50, 40, 20},
    { 80, 50, 10, 40}};

  xcb_arc_t arcs[] = {
    {10, 100, 60, 40, 0, 90 << 6},
    {90, 100, 55, 40, 0, 270 << 6}
  };

  xcb_generic_event_t *e;

  while ((e = connection->wait_for_event())) {
    switch (e->response_type & ~0x80) {
      case XCB_EXPOSE: {

        // draw points
        ctx->poly_point(XCB_COORD_MODE_ORIGIN, 4, points);

        // draw poly line
        ctx->poly_line(XCB_COORD_MODE_PREVIOUS, 4 ,polyline);

        // draw the segements
        ctx->poly_segment(2, segments);

        // draw the rectangles
        ctx->poly_rectangle(2, rectangles);

        // draw the arcs
        ctx->poly_arc(2, arcs);

        // flush the request
        connection->flush();

        break;
      }
      default: {
        /* Unknown event type, ignore it */
        break;
      }
    }
    /* Free the Generic Event */
    free (e);
  }

  return 0;
}
