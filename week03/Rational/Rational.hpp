#pragma once 
#include <iostream>

struct Rational {
  int numerator;
  int denominator;
};

Rational add_rational(const Rational& r1, const Rational& r2);
Rational multiply_rational(const Rational& r1, const Rational& r2);
Rational divide_rational(const Rational& r1, const Rational& r2);
Rational substract_rational(const Rational& r1, const Rational& r2);
void print(std::ostream& os, const Rational& r);
Rational read(std::istream& is);
void serialize(std::ostream& os, const Rational& r);
Rational deserialize(std::istream& is);
void simplify(Rational& r);