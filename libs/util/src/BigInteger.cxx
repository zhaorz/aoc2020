#include <util/BigInteger.h>

#include <stdexcept>

namespace util {

// -----------------------------------------------------------------------------
// BigDigit
// -----------------------------------------------------------------------------

BigDigit::BigDigit()
  : data_()
{}

BigDigit::BigDigit(uint32_t d)
  : data_(d)
{}

uint32_t BigDigit::data() const {
  return data_;
}

BigDigit::operator uint32_t() const {
  return data_;
}

BigDigit BigDigit::getHi(DoubleBigDigit n)
{
  return n >> bits;
}

BigDigit BigDigit::getLo(DoubleBigDigit n)
{
  return n & loMask_;
}

std::pair<BigDigit, BigDigit> BigDigit::fromDoubleBigDigit(DoubleBigDigit n)
{
  return {BigDigit::getHi(n), BigDigit::getLo(n)};
}

DoubleBigDigit BigDigit::toDoubleBigDigit(BigDigit hi, BigDigit lo)
{
  return static_cast<DoubleBigDigit>(lo)
    | (static_cast<DoubleBigDigit>(hi) << bits);
}

// -----------------------------------------------------------------------------
// BigUint
// -----------------------------------------------------------------------------

BigUint::BigUint()
  : data_()
{}

BigUint::BigUint(uint32_t n)
  : data_(n)
{}

BigUint::BigUint(std::vector<BigDigit> const& data)
  : data_(data)
{}

BigUint BigUint::zero()
{
  return BigUint{};
}

BigUint BigUint::one()
{
  return BigUint{std::vector<BigDigit>{1}};
}

BigUint BigUint::fromString(std::string const& s)
{
  // TODO: This could be optimized (parse chunks of the string)
  BigUint n = BigUint::zero();
  for (auto c : s) {
    uint32_t d = c - '0';
    if (d > 9) {
      throw std::invalid_argument("Invalid character in string initializer");
    }
    n *= 10;
    n += d;
  }
  return n;
}

// Arithmetic ------------------------------------------------------------------

BigUint& BigUint::operator+=(BigUint const&)
{
  // TODO
  return *this;
}

BigUint operator+(BigUint lhs, BigUint const& rhs)
{
  lhs += rhs;
  return lhs;
}

BigUint& BigUint::operator*=(BigUint const&)
{
  // TODO
  return *this;
}

BigUint operator*(BigUint lhs, BigUint const& rhs)
{
  lhs *= rhs;
  return lhs;
}

} // namespace util
