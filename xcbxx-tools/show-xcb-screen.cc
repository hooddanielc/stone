#include <xcbxx/connection.h>

int main(int, char*[]) {
  auto connection = xcbxx::connection_t::make();
  connection->get_screen()->print();
  std::cout << "total screens: " << connection->get_screen_count() << std::endl;
  return 0;
}
