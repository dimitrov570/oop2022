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

void print(std::ostream& os, const Rational& r) {
  os << r.numerator << " / " << r.denominator;
}

Rational read(std::istream& is) {
  Rational r;
  char c;
  
  is >> r.numerator;
  is >> c;
  is >> r.denominator;

  std::cout << r.numerator << '\n' << r.denominator << '\n';
  return r;
}


void serialize(std::ostream& os, const Rational& r) {
  os.write((const char*)&r, sizeof(r));
}

Rational deserialize(std::istream& is) {
  Rational r;
  is.read((char *)&r, sizeof(r));
  return r;
}

void simplify(Rational& r) {
  int gcd = std::gcd(r.numerator, r.denominator);
  r.numerator /= gcd;
  r.denominator /= gcd;
}