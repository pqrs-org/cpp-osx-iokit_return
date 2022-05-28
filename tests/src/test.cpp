#include <boost/ut.hpp>
#include <pqrs/osx/iokit_return.hpp>

int main(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "iokit_return"_test = [] {
    {
      pqrs::osx::iokit_return r(kIOReturnSuccess);
      expect(r.to_string() == "kIOReturnSuccess");
      expect(r == true);
      expect(r.success() == true);
      expect(r.exclusive_access() == false);
      expect(r.not_permitted() == false);
    }
    {
      pqrs::osx::iokit_return r(kIOReturnError);
      expect(r.to_string() == "kIOReturnError");
      expect(r == false);
      expect(r.success() == false);
      expect(r.exclusive_access() == false);
      expect(r.not_permitted() == false);
    }
    {
      pqrs::osx::iokit_return r(kIOReturnNoMemory);
      expect(r.to_string() == "kIOReturnNoMemory");
      expect(r == false);
      expect(r.success() == false);
      expect(r.exclusive_access() == false);
      expect(r.not_permitted() == false);
    }
    {
      pqrs::osx::iokit_return r(kIOReturnExclusiveAccess);
      expect(r.to_string() == "kIOReturnExclusiveAccess");
      expect(r == false);
      expect(r.success() == false);
      expect(r.exclusive_access() == true);
      expect(r.not_permitted() == false);
    }
    {
      pqrs::osx::iokit_return r(kIOReturnNotPermitted);
      expect(r.to_string() == "kIOReturnNotPermitted");
      expect(r == false);
      expect(r.success() == false);
      expect(r.exclusive_access() == false);
      expect(r.not_permitted() == true);
    }
    {
      pqrs::osx::iokit_return r(123456);
      expect(r.to_string() == "Unknown IOReturn (123456)");
      expect(r == false);
      expect(r.success() == false);
      expect(r.exclusive_access() == false);
      expect(r.not_permitted() == false);
    }
  };

  return 0;
}
