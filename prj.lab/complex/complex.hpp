#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#define _USE_MATH_DEFINES

#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <algorithm>

struct Complex {
  Complex() : re(0.0), im(0.0) {}
  Complex(const double real) : re(real), im(0.0) {}
  Complex(const double real, const double imaginary) : re(real), im(imaginary) {}

  Complex& operator=(const Complex&) = default;
  ~Complex() = default;

  Complex& operator+=(const Complex& rhs);
  Complex& operator+=(const double rhs);
  Complex& operator-=(const Complex& rhs);
  Complex& operator-=(const double rhs);
  Complex& operator*=(const Complex& rhs);
  Complex& operator*=(const double rhs);
  Complex& operator/=(const Complex& rhs);
  Complex& operator/=(const double rhs);

  std::ostream& writeTo(std::ostream& ostrm) const;
  std::istream& readFrom(std::istream& istrm);

  double re{ 0.0 };
  double im{ 0.0 };

  static const char leftBrace{ '{' };
  static const char separator{ ',' };
  static const char rightBrace{ '}' };
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
  return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
  return rhs.readFrom(istrm);
}

bool operator==(const Complex& lhs, const Complex& rhs);
bool operator!=(const Complex& lhs, const Complex& rhs);

Complex degree(const Complex& lhs, const int rhs);
std::vector<Complex> root(const Complex& lhs, const int rhs);
double arg(const Complex& z);
double modulus(const Complex& z);

bool is_equal(const double& x, const double& y);
bool is_equal_complex(const Complex& lhs, const Complex& rhs);
bool is_equal_vector(const std::vector<Complex>& lhs, const std::vector<Complex>& rhs);

#endif