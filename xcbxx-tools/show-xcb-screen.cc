#include <xcbxx/connection.h>

int main(int, char*[]) {
  auto connection = xcbxx::connection_t::make();
  connection->print_screen_data();
  return 0;
}
