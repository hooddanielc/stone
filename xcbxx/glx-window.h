#pragma once

#include <GL/glx.h>
#include <GL/gl.h>
#include <xcbxx/window.h>

namespace xcbxx {

class connection_t;

class glx_window_t: public window_t {

protected:

  friend class connection_t;

  int visual_id;

  GLXContext glx_context;

  GLXWindow glx_window;

  GLXDrawable glx_drawable;

  glx_window_t(
    std::shared_ptr<connection_t> connection,
    xcb_window_t window,
    int visual_id_,
    GLXContext glx_context_,
    GLXWindow glx_window_
  ):
    window_t(connection, window),
    visual_id(visual_id_),
    glx_context(glx_context_),
    glx_window(glx_window_),
    glx_drawable(glx_window_) {}

public:

  void swap_buffers();

  ~glx_window_t();

};  // glx_window

}   // xcbxx