#include <xcbxx/connection.h>

int main(int, char*[]) {
  auto connection = xcbxx::connection_t::make();
  auto screen = connection->get_screen();

  auto window = connection->create_window(
    0,
    0,
    150,
    150,
    10,
    screen->get_root(),
    screen->get_root_visual()
  );

  window->show();
  connection->flush();
  connection->pause();

  return 0;
}
