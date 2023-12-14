#include <rational/rational.hpp>

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

bool operator==(const Rational& lhs, const Rational& rhs) {
  return (lhs.num() == rhs.num() && lhs.den() == rhs.den());
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
  return !(lhs == rhs);
}

bool operator>(const Rational& lhs, const Rational& rhs) {
  return (lhs.num() * rhs.den() - lhs.den() * rhs.num() > 0);
};

bool operator<(const Rational& lhs, const Rational& rhs) {
  return (lhs.num() * rhs.den() - lhs.den() * rhs.num() < 0);
};

bool operator>=(const Rational& lhs, const Rational& rhs) {
  return (lhs.num() * rhs.den() - lhs.den() * rhs.num() >= 0);
};

bool operator<=(const Rational& lhs, const Rational& rhs) {
  return (lhs.num() * rhs.den() - lhs.den() * rhs.num() <= 0);
};

Rational& Rational::operator+=(const Rational& rhs) {
  num_ = num_ * rhs.den_ + den_ * rhs.num_;
  den_ = den_ * rhs.den_;
  simplify();
  return *this;
}

Rational& Rational::operator+=(const int64_t rhs) {
  num_ = num_ + den_ * rhs;
  den_ = den_;
  simplify();
  return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
  num_ = num_ * rhs.den_ - den_ * rhs.num_;
  den_ = den_ * rhs.den_;
  simplify();
  return *this;
}

Rational& Rational::operator-=(const int64_t rhs) {
  num_ = num_ - den_ * rhs;
  den_ = den_;
  simplify();
  return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
  num_ = num_ * rhs.num_;
  den_ = den_ * rhs.den_;
  simplify();
  return *this;
}

Rational& Rational::operator*=(const int64_t rhs) {
  num_ = num_ * rhs;
  den_ = den_;
  simplify();
  return *this;
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
  if (rhs == 0) {
    throw std::invalid_argument("Division by zero");
  }
  num_ = num_;
  den_ = den_ * rhs;
  simplify();
  return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
  Rational sum(lhs);
  sum += rhs;
  return sum;
};

Rational operator+(const Rational& lhs, const int64_t rhs) {
  Rational sum(lhs);
  sum += rhs;
  return sum;
};

Rational operator+(const int64_t lhs, Rational& rhs) {
  Rational sum(rhs);
  sum += lhs;
  return sum;
};

Rational operator-(const Rational& lhs, const Rational& rhs) {
  Rational res(lhs);
  res -= rhs;
  return res;
};

Rational operator-(const Rational& lhs, const int64_t rhs) {
  Rational res(lhs);
  res -= rhs;
  return res;
};

Rational operator-(const int64_t lhs, Rational& rhs) {
  Rational res(-rhs);
  res += lhs;
  return res;
};

Rational operator*(const Rational& lhs, const Rational& rhs) {
  Rational res(lhs);
  res *= rhs;
  return res;
}

Rational operator*(const Rational& lhs, const int64_t rhs) {
  Rational res(lhs);
  res *= rhs;
  return res;
}

Rational operator*(const int64_t lhs, Rational& rhs) {
  Rational res(rhs);
  res *= lhs;
  return res;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
  Rational res(lhs);
  res /= rhs;
  return res;
}

Rational operator/(const Rational& lhs, const int64_t rhs) {
  Rational res(lhs);
  res /= rhs;
  return res;
}

Rational operator/(const int64_t lhs, Rational& rhs) {
  Rational res{ rhs.den(), rhs.num() };
  res *= lhs;
  return res;
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const {
  ostrm << num_ << slash << den_;
  return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) {
  int64_t numerator(0);
  int64_t denumerator(0);
  char slash(0);

  istrm >> numerator >> slash >> denumerator;

  if (istrm.good()) {
    if (Rational::slash == slash) {
      num_ = numerator;
      den_ = denumerator;
    }
    else {
      istrm.setstate(std::ios_base::failbit);
    }
  }

  return istrm;
}