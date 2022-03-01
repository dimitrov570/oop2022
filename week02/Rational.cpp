#include <numeric>
#include "Rational.hpp"

Rational add_rational(const Rational& r1, const Rational& r2) {
  Rational result = {r1.numerator * r2.denominator + r2.numerator * r1.denominator, r1.denominator * r2.denominator};
  return result;
}

Rational multiply_rational(const Rational& r1, const Rational& r2) {
  Rational result = {r1.numerator * r2.numerator, r1.denominator * r2.denominator};
  return result;
}

Rational divide_rational(const Rational& r1, const Rational& r2) {
  Rational result = {r1.numerator * r2.denominator, r1.denominator * r2.numerator};
  return result;
}

Rational substract_rational(const Rational& r1, const Rational& r2) {
  Rational result = {r1.numerator * r2.denominator - r2.numerator * r1.denominator, r1.denominator * r2.denominator};
  return result;
}

void simplify(Rational& r) {
  int gcd = std::gcd(r.numerator, r.denominator);
  r.numerator /= gcd;
  r.denominator /= gcd;
}