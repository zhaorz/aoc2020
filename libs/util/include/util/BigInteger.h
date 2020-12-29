#pragma once

#include <cstdint>
#include <iostream>
#include <vector>

// An unbounded size integer implementation, loosely based off of Rust's BigInt.

namespace util {

using DoubleBigDigit = uint64_t;

class BigDigit
{
public:
  static constexpr size_t bits = 32;
  static constexpr DoubleBigDigit base = 1ull << bits;

  BigDigit();
  BigDigit(uint32_t);

  uint32_t data() const;
  operator uint32_t() const;

  static BigDigit getHi(DoubleBigDigit);
  static BigDigit getLo(DoubleBigDigit);

  static std::pair<BigDigit, BigDigit> fromDoubleBigDigit(DoubleBigDigit);
  static DoubleBigDigit toDoubleBigDigit(BigDigit, BigDigit);

private:
  static constexpr uint64_t loMask_ = 0xffffffff;
  uint32_t data_;
};

class BigUint {
public:
  BigUint();
  BigUint(uint32_t);
  BigUint(std::vector<BigDigit> const&);

  static BigUint zero();
  static BigUint one();

  // Assumes radix = 10
  static BigUint fromString(std::string const&);

  // Arithmetic ----------------------------------------------------------------
  BigUint& operator+=(BigUint const&);
  friend BigUint operator+(BigUint, BigUint const&);
  BigUint& operator*=(BigUint const&);
  friend BigUint operator*(BigUint, BigUint const&);

private:
  std::vector<BigDigit> data_;
};

} // namespace
