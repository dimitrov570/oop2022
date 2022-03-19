#include "Rational.hpp"
#include <numeric>

Rational::Rational(int n, int d) : numerator(n)
{
    if (d != 0)
    {
        denominator = d;
        simplify();
    }
    else
    {
        denominator = 1;
    }
}

int Rational::getNumerator(/* Rational const * const this */) const
{
    return numerator;
}

int Rational::getDenominator(/* Rational const * const this */) const
{
    return denominator;
}

bool Rational::setNumerator(/* Rational * const this, */ int n)
{
    numerator = n;
    simplify();
    return true;
}

bool Rational::setDenominator(/* Rational * const this, */ int d)
{
    if (d != 0)
    {
        denominator = d;
        simplify();
        return true;
    }
    return false;
}

Rational Rational::add(/* Rational const * const this, */ const Rational &rhs) const
{
    Rational r;
    r.numerator = numerator * rhs.denominator + rhs.numerator * denominator;
    r.denominator = denominator * rhs.denominator;
    r.simplify();
    return r;
}

Rational Rational::subtract(/* Rational const * const this, */ const Rational &rhs) const
{
    Rational r;
    r.numerator = numerator * rhs.denominator - rhs.numerator * denominator;
    r.denominator = denominator * rhs.denominator;
    r.simplify();
    return r;
}

Rational Rational::multiply(/* Rational const * const this, */ const Rational &rhs) const
{
    return Rational(numerator * rhs.numerator, denominator * rhs.denominator);
}

Rational Rational::divide(/* Rational const * const this, */ const Rational &rhs) const
{
    return Rational(numerator * rhs.denominator, denominator * rhs.numerator);
}

void Rational::simplify(/* Rational * const this */ )
{
    int gcd = std::gcd(numerator, denominator); //available from c++17 (#include <numeric>)
    numerator /= gcd;
    denominator /= gcd;
}

void Rational::print(/* Rational const * const this, */ std::ostream& os) const {
  os << this->numerator << " / " << this->denominator;
}

void Rational::serialize(/* Rational const * const this, */ std::ostream& os) const {
  os.write((const char*)this, sizeof(Rational));
}

Rational Rational::read(std::istream& is) {
  Rational r;
  char c;
  
  is >> r.numerator;
  is >> c; // for '/'
  is >> r.denominator;

  return r;
}

Rational Rational::deserialize(std::istream& is) {
  Rational r;
  is.read((char *)&r, sizeof(r));
  return r;
}