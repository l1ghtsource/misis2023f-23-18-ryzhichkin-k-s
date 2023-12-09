#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <stdexcept>
#include <cstdint>
#include <sstream>

class Rational {
public:
  [[nodiscard]] Rational() = default;
  [[nodiscard]] Rational(const int64_t num);
  [[nodiscard]] Rational(const int64_t num, const int64_t den);
  [[nodiscard]] Rational(const Rational& rhs);
  [[nodiscard]] Rational& operator=(const Rational&) = default;

  ~Rational() = default;

  [[nodiscard]] std::int64_t num() const noexcept { return num_; }
  [[nodiscard]] std::int64_t den() const noexcept { return den_; }

  [[nodiscard]] Rational operator-() const noexcept { return { -num_, den_ }; }

  Rational& operator+=(const Rational& rhs);
  Rational& operator+=(const int64_t rhs);

  Rational& operator-=(const Rational& rhs);
  Rational& operator-=(const int64_t rhs);

  Rational& operator*=(const Rational& rhs);
  Rational& operator*=(const int64_t rhs);

  Rational& operator/=(const Rational& rhs);
  Rational& operator/=(const int64_t rhs);

  std::ostream& writeTo(std::ostream& ostrm) const;
  std::istream& readFrom(std::istream& istrm);

private:

  int64_t num_ = 0;
  int64_t den_ = 1;

  int64_t gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
  }

  void simplify() {
    if (den_ < 0) {
      num_ *= (-1);
      den_ *= (-1);
    }
    int64_t gcd_ = gcd(std::abs(num_), std::abs(den_));
    num_ /= gcd_;
    den_ /= gcd_;
  }

  static const char slash{ '/' };
};

Rational::Rational(const int64_t num) {
  num_ = num;
  den_ = 1;
}

Rational::Rational(const int64_t num, const int64_t den) {
  num_ = num;
  den_ = den;
  if (0 == den_) {
    throw std::invalid_argument("Zero denumenator in Rational ctor");
  }
  simplify();
}

Rational::Rational(const Rational& rhs) {
  num_ = rhs.num();
  den_ = rhs.den();
  if (0 == den_) {
    throw std::invalid_argument("Zero denumenator in Rational ctor");
  }
  simplify();
}

[[nodiscard]] Rational operator+(const Rational& lhs, const Rational& rhs);
[[nodiscard]] Rational operator+(const Rational& lhs, const int64_t rhs);
[[nodiscard]] Rational operator+(const int64_t lhs, Rational& rhs);

[[nodiscard]] Rational operator-(const Rational& lhs, const Rational& rhs);
[[nodiscard]] Rational operator-(const Rational& lhs, const int64_t rhs);
[[nodiscard]] Rational operator-(const int64_t lhs, Rational& rhs);

[[nodiscard]] Rational operator*(const Rational& lhs, const Rational& rhs);
[[nodiscard]] Rational operator*(const Rational& lhs, const int64_t rhs);
[[nodiscard]] Rational operator*(const int64_t lhs, Rational& rhs);

[[nodiscard]] Rational operator/(const Rational& lhs, const Rational& rhs);
[[nodiscard]] Rational operator/(const Rational& lhs, const int64_t rhs);
[[nodiscard]] Rational operator/(const int64_t lhs, Rational& rhs);

[[nodiscard]] bool operator==(const Rational& lhs, const Rational& rhs);
[[nodiscard]] bool operator!=(const Rational& lhs, const Rational& rhs);

[[nodiscard]] bool operator>(const Rational& lhs, const Rational& rhs);
[[nodiscard]] bool operator<(const Rational& lhs, const Rational& rhs);
[[nodiscard]] bool operator>=(const Rational& lhs, const Rational& rhs);
[[nodiscard]] bool operator<=(const Rational& lhs, const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
  return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs) {
  return rhs.readFrom(istrm);
}

#endif