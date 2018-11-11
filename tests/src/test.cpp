#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pqrs/osx/iokit_return.hpp>

TEST_CASE("iokit_return") {
  {
    pqrs::osx::iokit_return r(kIOReturnSuccess);
    REQUIRE(r.to_string() == "kIOReturnSuccess");
    REQUIRE(r == true);
  }
  {
    pqrs::osx::iokit_return r(kIOReturnError);
    REQUIRE(r.to_string() == "kIOReturnError");
    REQUIRE(r == false);
  }
  {
    pqrs::osx::iokit_return r(kIOReturnNoMemory);
    REQUIRE(r.to_string() == "kIOReturnNoMemory");
    REQUIRE(r == false);
  }
}
