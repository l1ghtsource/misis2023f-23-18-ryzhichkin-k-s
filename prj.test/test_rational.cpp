#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <rational/rational.hpp>
#include <rational/rational.cpp>
#include "doctest.h"

TEST_CASE("rational ctor and simplifier") {
  Rational r_def;
  CHECK(0 == r_def.num());
  CHECK(1 == r_def.den());

  Rational r_int(3);
  CHECK(3 == r_int.num());
  CHECK(1 == r_int.den());

  Rational r{ 4, 5 };
  CHECK(4 == r.num());
  CHECK(5 == r.den());

  Rational r_2{ 16, 24 };
  CHECK(2 == r_2.num());
  CHECK(3 == r_2.den());

  Rational r_3{ -1, 2 };
  CHECK(-1 == r_3.num());
  CHECK(2 == r_3.den());

  Rational r_4{ 1, -3 };
  CHECK(-1 == r_4.num());
  CHECK(3 == r_4.den());

  CHECK_THROWS(Rational(1, 0));
}

TEST_CASE("operators") {
  Rational r_1{ 2, -6 };
  Rational r_2{ 7, 28 };
  Rational r_3{ 0, 128 };

  Rational sum{ -1, 12 };
  Rational difference{ -7, 12 };
  Rational product{ -1, 12 };
  Rational quotient{ -4, 3 };

  CHECK(sum == (r_1 + r_2));
  CHECK(difference == (r_1 - r_2));
  CHECK(product == (r_1 * r_2));
  CHECK(quotient == (r_1 / r_2));

  CHECK_THROWS(r_1 / r_3);
}