namespace cane {

/*
 * stores vertex data
 */
class mesh_t {

private:

  unsigned int vbo;

  mesh_t() {
    glGenBuffers(1, &vbo);
  }

};

}
