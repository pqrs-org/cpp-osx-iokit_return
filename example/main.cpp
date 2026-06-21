#include <pqrs/osx/iokit_return.hpp>

int main() {
  {
    pqrs::osx::iokit_return r(kIOReturnAborted);
    std::cout << r << std::endl;
  }

  {
    pqrs::osx::iokit_return r(54321);
    std::cout << r << std::endl;
  }

  return 0;
}
