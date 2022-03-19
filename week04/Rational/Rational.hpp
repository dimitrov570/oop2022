#pragma once
#include <numeric>
#include <iostream>

class Rational
{
private:
    int numerator;
    int denominator;

public:
    Rational(int n = 0, int d = 1);

    int getNumerator(/* Rational const * const this */) const;
    int getDenominator(/* Rational const * const this */) const;
    
    bool setNumerator(/* Rational * const this, */ int);
    bool setDenominator(/* Rational * const this, */ int);

    
    Rational add(/* Rational const * const this, */ const Rational& rhs) const;
    Rational subtract(/* Rational const * const this, */ const Rational& rhs) const;
    Rational multiply(/* Rational const * const this, */ const Rational& rhs) const;
    Rational divide(/* Rational const * const this, */ const Rational& rhs) const;
    
    void print(/* Rational const * const this, */ std::ostream& os) const;

    void serialize(/* Rational const * const this, */ std::ostream& os) const;

    static Rational read(std::istream& is);
    static Rational deserialize(std::istream& is);

private:
    void simplify();
};
