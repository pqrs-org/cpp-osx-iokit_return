#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pqrs/osx/iokit_return.hpp>

TEST_CASE("iokit_return") {
  {
    pqrs::osx::iokit_return r(kIOReturnSuccess);
    REQUIRE(r.to_string() == "kIOReturnSuccess");
    REQUIRE(r == true);
    REQUIRE(r.success() == true);
    REQUIRE(r.exclusive_access() == false);
    REQUIRE(r.not_permitted() == false);
  }
  {
    pqrs::osx::iokit_return r(kIOReturnError);
    REQUIRE(r.to_string() == "kIOReturnError");
    REQUIRE(r == false);
    REQUIRE(r.success() == false);
    REQUIRE(r.exclusive_access() == false);
    REQUIRE(r.not_permitted() == false);
  }
  {
    pqrs::osx::iokit_return r(kIOReturnNoMemory);
    REQUIRE(r.to_string() == "kIOReturnNoMemory");
    REQUIRE(r == false);
    REQUIRE(r.success() == false);
    REQUIRE(r.exclusive_access() == false);
    REQUIRE(r.not_permitted() == false);
  }
  {
    pqrs::osx::iokit_return r(kIOReturnExclusiveAccess);
    REQUIRE(r.to_string() == "kIOReturnExclusiveAccess");
    REQUIRE(r == false);
    REQUIRE(r.success() == false);
    REQUIRE(r.exclusive_access() == true);
    REQUIRE(r.not_permitted() == false);
  }
  {
    pqrs::osx::iokit_return r(kIOReturnNotPermitted);
    REQUIRE(r.to_string() == "kIOReturnNotPermitted");
    REQUIRE(r == false);
    REQUIRE(r.success() == false);
    REQUIRE(r.exclusive_access() == false);
    REQUIRE(r.not_permitted() == true);
  }
}
