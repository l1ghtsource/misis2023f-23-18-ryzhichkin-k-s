#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <rational/rational.hpp>
#include <rational/rational.cpp>
#include "doctest.h"

TEST_CASE("rational ctor") {
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