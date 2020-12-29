#include <util/BigInteger.h>

#include <catch/catch.hpp>

using namespace util;

TEST_CASE("BigDigit", "[BigInteger]") {
  SECTION("default ctor") {
    BigDigit d;
    CHECK(d.data() == 0);
  }

  SECTION("ctor") {
    BigDigit d{123};
    CHECK(d.data() == 123);
  }

  SECTION("getHi") {
    CHECK(BigDigit::getHi(0xaabbccddeeff8899ull) == 0xaabbccdd);
  }

  SECTION("getLo") {
    CHECK(BigDigit::getLo(0xaabbccddeeff8899ull) == 0xeeff8899);
  }

  SECTION("fromDoubleBigDigit") {
    CHECK(BigDigit::fromDoubleBigDigit(0xaabbccddeeff8899ull)
        == std::pair<BigDigit, BigDigit>({ 0xaabbccdd, 0xeeff8899 }));
  }

  SECTION("toDoubleBigDigit") {
    CHECK(BigDigit::toDoubleBigDigit(0xaabbccdd, 0xeeff8899)
        == 0xaabbccddeeff8899ull);
  }
}

TEST_CASE("BigUint", "[BigInteger]") {
}
