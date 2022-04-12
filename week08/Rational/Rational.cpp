#include "Rational.hpp"
#include <numeric>

int a = 6;

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

int Rational::getNumerator() const
{
    return numerator;
}

int Rational::getDenominator() const
{
    return denominator;
}

double Rational::toDouble() const
{
    return (double)numerator / denominator;
}

void Rational::print() const
{
    std::cout << numerator << '/' << denominator;
}

bool Rational::setNumerator(int n)
{
    numerator = n;
    simplify();
    return true;
}

bool Rational::setDenominator(int d)
{
    if (d != 0)
    {
        denominator = d;
        simplify();
        return true;
    }
    return false;
}

Rational::operator double() const
{
    return (double)numerator / denominator;
}

Rational &Rational::operator++()
{
    numerator += denominator;
    return *this;
}

Rational Rational::operator++(int)
{
    Rational r = *this;       //запазва се старата стойност
    numerator += denominator; //променя се стойността
    return r;                 //връща се старата стойност
}

Rational &Rational::operator--()
{
    numerator -= denominator;
    return *this;
}

Rational Rational::operator--(int)
{
    Rational r = *this;       //запазва се старата стойност
    numerator -= denominator; //променя се стойността
    return r;                 //връща се старата стойност
}

Rational Rational::operator+(const Rational &rhs) const
{
    Rational r;
    r.numerator = numerator * rhs.denominator + rhs.numerator * denominator;
    r.denominator = denominator * rhs.denominator;
    r.simplify();
    return r;
}

// unary -
Rational Rational::operator-() const
{
    return Rational(-numerator, denominator);
}

//binary
Rational Rational::operator-(const Rational &rhs) const
{
    Rational r;
    r.numerator = numerator * rhs.denominator - rhs.numerator * denominator;
    r.denominator = denominator * rhs.denominator;
    r.simplify();
    return r;
}

Rational Rational::operator*(const Rational &rhs) const
{
    return Rational(numerator * rhs.numerator, denominator * rhs.denominator);
}

Rational Rational::operator/(const Rational &rhs) const
{
    return Rational(numerator * rhs.denominator, denominator * rhs.numerator);
}

Rational& Rational::operator+=(const Rational &rhs)
{
    numerator = numerator * rhs.denominator + rhs.numerator * denominator;
    denominator *= rhs.denominator;
    simplify();
    return *this;
}

Rational &Rational::operator-=(const Rational &rhs)
{
    numerator = numerator * rhs.denominator - rhs.numerator * denominator;
    denominator *= rhs.denominator;
    simplify();
    return *this;
}

Rational &Rational::operator*=(const Rational &rhs)
{
    numerator *= rhs.numerator;
    denominator *= rhs.denominator;
    simplify();
    return *this;
}

Rational &Rational::operator/=(const Rational &rhs)
{
    numerator *= rhs.denominator;
    denominator *= rhs.numerator;
    simplify();
    return *this;
}

Rational Rational::operator+(int x) const
{
    return Rational(numerator + denominator * x, denominator);
}

Rational operator+(int x, const Rational &r)
{
    return Rational(r.numerator + r.denominator * x, r.denominator);
}

void Rational::simplify()
{
    int gcd = std::gcd(numerator, denominator); //available from c++17 (#include <numeric>)
    numerator /= gcd;
    denominator /= gcd;
}

std::ostream &operator<<(std::ostream &o, const Rational &obj)
{
    return o << obj.numerator << '/' << obj.denominator;
}

std::istream &operator>>(std::istream &i, Rational &obj)
{
    char c;
    i >> obj.numerator;
    i >> c;
    i >> obj.denominator;
    return i;
}