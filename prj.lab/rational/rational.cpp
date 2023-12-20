#include <rational/rational.hpp>

Rational::Rational(const int64_t num) {
  num_ = num;
  den_ = 1;
  simplify();
}

Rational::Rational(const int64_t num, const int64_t den) {
  num_ = num;
  den_ = den;
  if (0 == den_) {
    throw std::invalid_argument("Zero denumenator in Rational ctor");
  }
  simplify();
}

Rational& Rational::operator+=(const Rational& rhs) noexcept {
  num_ = num_ * rhs.den_ + den_ * rhs.num_;
  den_ = den_ * rhs.den_;
  simplify();
  return *this;
}

Rational& Rational::operator+=(const int64_t rhs) noexcept {
  return operator+=(Rational(rhs));
}

Rational& Rational::operator-=(const Rational& rhs) noexcept {
  num_ = num_ * rhs.den_ - den_ * rhs.num_;
  den_ = den_ * rhs.den_;
  simplify();
  return *this;
}

Rational& Rational::operator-=(const int64_t rhs) noexcept {
  return operator-=(Rational(rhs));
}

Rational& Rational::operator*=(const Rational& rhs) noexcept {
  num_ = num_ * rhs.num_;
  den_ = den_ * rhs.den_;
  simplify();
  return *this;
}

Rational& Rational::operator*=(const int64_t rhs) noexcept {
  return operator*=(Rational(rhs));
}

Rational& Rational::operator/=(const Rational& rhs) {
  if (rhs.den_ == 0) {
    throw std::invalid_argument("Division by zero");
  }
  num_ = num_ * rhs.den_;
  den_ = den_ * rhs.num_;
  simplify();
  return *this;
}

Rational& Rational::operator/=(const int64_t rhs) {
  return operator/=(Rational(rhs));
}

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept {
  return Rational(lhs) += rhs;
};

Rational operator+(const Rational& lhs, const int64_t rhs) noexcept {
  return Rational(lhs) += Rational(rhs);
};

Rational operator+(const int64_t lhs, Rational& rhs) noexcept {
  return Rational(lhs) += Rational(rhs);
};

Rational operator-(const Rational& lhs, const Rational& rhs) noexcept {
  return Rational(lhs) -= rhs;
};

Rational operator-(const Rational& lhs, const int64_t rhs) noexcept {
  return Rational(lhs) -= Rational(rhs);
};

Rational operator-(const int64_t lhs, Rational& rhs) noexcept {
  return Rational(lhs) -= Rational(rhs);
};

Rational operator*(const Rational& lhs, const Rational& rhs) noexcept {
  return Rational(lhs) *= rhs;
}

Rational operator*(const Rational& lhs, const int64_t rhs) noexcept {
  return Rational(lhs) *= Rational(rhs);
}

Rational operator*(const int64_t lhs, Rational& rhs) noexcept {
  return Rational(lhs) *= Rational(rhs);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
  return Rational(lhs) /= rhs;
}

Rational operator/(const Rational& lhs, const int64_t rhs) {
  return Rational(lhs) /= Rational(rhs);
}

Rational operator/(const int64_t lhs, Rational& rhs) {
  return Rational(lhs) /= Rational(rhs);
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const noexcept {
  ostrm << num_ << slash << den_;
  return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) noexcept {
  int64_t numerator(0);
  int64_t denumerator(1);
  char slash(0);

  istrm >> numerator >> slash >> denumerator;

  if (istrm.good()) {
    if (Rational::slash == slash) {
      num_ = numerator;
      den_ = denumerator;
      simplify();
    }
    else {
      istrm.setstate(std::ios_base::failbit);
    }
  }

  return istrm;
}