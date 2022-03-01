#pragma once 

struct Rational {
  int numerator;
  int denominator;
};

Rational add_rational(const Rational& r1, const Rational& r2);
Rational multiply_rational(const Rational& r1, const Rational& r2);
Rational divide_rational(const Rational& r1, const Rational& r2);
Rational substract_rational(const Rational& r1, const Rational& r2);
void simplify(Rational& r);