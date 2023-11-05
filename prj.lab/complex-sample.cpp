#define _USE_MATH_DEFINES

#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <stdexcept>

class Complex {
public:
  Complex() : re(0.0), im(0.0) {}
  Complex(const double real) : re(real), im(0.0) {}
  Complex(const double real, const double imaginary) : re(real), im(imaginary) {}

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

bool operator==(const Complex& lhs, const Complex& rhs);
bool operator!=(const Complex& lhs, const Complex& rhs);

Complex degree(const Complex& lhs, const int rhs);
std::vector<Complex> root(const Complex& lhs, const int rhs);
double arg(const Complex& z);
double modulus(const Complex& z);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
  return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
  return rhs.readFrom(istrm);
}

bool testParse(const std::string& str) {
  std::istringstream istrm(str);
  Complex z;
  istrm >> z;

  if (istrm.good()) {
    std::cout << "Read success: " << str << " -> " << z << std::endl;
  }
  else {
    std::cout << "Read error : " << str << " -> " << z << std::endl;
  }
  return istrm.good();
}

bool operator==(const Complex& lhs, const Complex& rhs) {
  return (lhs.re == rhs.re) && (lhs.im == rhs.im);
}

bool operator!=(const Complex& lhs, const Complex& rhs) {
  return !(lhs == rhs);
}

Complex& Complex::operator+=(const double rhs) {
  re += rhs;
  return *this;
}

Complex& Complex::operator+=(const Complex& rhs) {
  re += rhs.re;
  im += rhs.im;
  return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
  Complex sum(lhs);
  sum += rhs;
  return sum;
}

Complex operator+(const Complex& lhs, const double rhs) {
  Complex sum(lhs);
  sum += rhs;
  return sum;
}

Complex& Complex::operator-=(const double rhs) {
  re -= rhs;
  return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
  re -= rhs.re;
  im -= rhs.im;
  return *this;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
  Complex result(lhs);
  result -= rhs;
  return result;
}

Complex operator-(const Complex& lhs, const double rhs) {
  Complex result(lhs);
  result -= rhs;
  return result;
}

Complex& Complex::operator*=(const double rhs) {
  re *= rhs;
  im *= rhs;
  return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
  double tempRe = re * rhs.re - im * rhs.im;
  double tempIm = re * rhs.im + im * rhs.re;
  re = tempRe;
  im = tempIm;
  return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
  Complex result(lhs);
  result *= rhs;
  return result;
}

Complex operator*(const Complex& lhs, const double rhs) {
  Complex result(lhs);
  result *= rhs;
  return result;
}

Complex& Complex::operator/=(const double rhs) {
  if (rhs == 0.0) {
    throw std::invalid_argument("Division by zero");
  }
  re /= rhs;
  im /= rhs;
  return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
  double denominator = rhs.re * rhs.re + rhs.im * rhs.im;
  if (denominator == 0.0) {
    throw std::invalid_argument("Division by zero");
  }
  double newRe = (re * rhs.re + im * rhs.im) / denominator;
  double newIm = (im * rhs.re - re * rhs.im) / denominator;
  re = newRe;
  im = newIm;
  return *this;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
  Complex result(lhs);
  result /= rhs;
  return result;
}

Complex operator/(const Complex& lhs, const double rhs) {
  Complex result(lhs);
  result /= rhs;
  return result;
}

double modulus(const Complex& z) {
  return std::sqrt(z.re * z.re + z.im * z.im);
}

double arg(const Complex& z) {
  if (z.re == 0.0 && z.im == 0.0) {
    throw std::domain_error("Undefined argument for zero complex number");
  }
  return std::asin(z.im / modulus(z));
}

Complex degree(const Complex& lhs, const int rhs) {
  if (lhs.im == 0) {
    return Complex(std::pow(lhs.re, rhs), 0.0);
  }
  double modulusZ = modulus(lhs);
  double argZ = arg(lhs);
  double newModulus = std::pow(modulusZ, rhs);
  double newArg = argZ * rhs;
  return Complex(newModulus * std::cos(newArg), newModulus * std::sin(newArg));
}

std::vector<Complex> root(const Complex& lhs, const int rhs) {
  std::vector<Complex> roots;
  double modulusZ = modulus(lhs);
  double argZ = arg(lhs);
  double rootModulus = std::pow(modulusZ, 1.0 / rhs);
  for (int k = 0; k < rhs; ++k) {
    double rootArg = (argZ + 2 * M_PI * k) / rhs;
    roots.push_back(Complex(rootModulus * std::cos(rootArg), rootModulus * std::sin(rootArg)));
  }
  return roots;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const {
  ostrm << leftBrace << re << separator << im << rightBrace;
  return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm) {
  char leftBrace(0);
  double real(0.0);
  char comma(0);
  double imaginary(0.0);
  char rightBrace(0);

  istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;

  if (istrm.good()) {
    if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) && (Complex::rightBrace == rightBrace)) {
      re = real;
      im = imaginary;
    }
    else {
      istrm.setstate(std::ios_base::failbit);
    }
  }

  return istrm;
}

int main() {
  Complex z1{ 1, 2 };
  Complex z2{ 2, 3 };
  Complex z3{ 4, 0 };
  Complex z4{ 0, 4 };
  Complex z5{ 0, 0 };

  const double alpha = 11;
  const int deg = 5;

  std::vector<Complex> roots = root(z2, deg);

  testParse("{8.9,9}");
  testParse("{8.9, 9}");
  testParse("{8.9,9");

  std::cout << z1 * z2 << std::endl;
  std::cout << z1 / z2 << std::endl;
  std::cout << z1 + z2 << std::endl;
  std::cout << z1 - z2 << std::endl;

  std::cout << z1 * alpha << std::endl;
  std::cout << z2 / alpha << std::endl;
  std::cout << z3 + alpha << std::endl;
  std::cout << z4 - alpha << std::endl;

  std::cout << degree(z1, deg) << std::endl;

  for (Complex& z : roots) {
    std::cout << z << " ";
  }
  std::cout << std::endl;

  std::cout << arg(z2) << std::endl;

  std::cout << modulus(z1) << std::endl;

  return 0;
}