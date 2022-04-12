#pragma once
#include <iostream>

class Rational
{
private:
    int numerator;
    int denominator;

public:
    Rational(int n = 0, int d = 1);

    int getNumerator() const;
    int getDenominator() const;
    double toDouble() const;
    void print() const;

    bool setNumerator(int);
    bool setDenominator(int);

    //cast to double
    operator double() const;

    Rational& operator++(); // prefix
    Rational operator++(int); // postfix
    Rational& operator--(); // prefix
    Rational operator--(int); // postfix

    Rational operator+(const Rational& rhs) const;
    Rational operator-() const; // unary
    Rational operator-(const Rational& rhs) const; // binary
    Rational operator*(const Rational& rhs) const;  
    Rational operator/(const Rational& rhs) const;
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const Rational& rhs);

    Rational operator+(int x) const; 

    //operator + with first argument int
    friend Rational operator+(int x, const Rational& r);

    // operator<<
    friend std::ostream& operator<<(std::ostream& o, const Rational& obj);

    // operator>>
    friend std::istream& operator>>(std::istream& i, Rational& obj);

    friend class Number;  // ----------------------------
                                                    //   |
private:                                            //   |
                                                    //   |
    void simplify();                                //   |
};                                                  //   |
                                                    //   |
                                                    //   |
class Number {                                      //   |
                                                    //   |
public:                                             //   |
    int x;                                          //   |
                                                    //   |
    Number(int _x) : x(_x) {}                       //   |
                                                    //   |
                                                    //   |
    Number operator+(const Rational& r) {           //   |
                                                    //   |
        return x + (r.numerator / r.denominator);// <----- достъп до private членовете на Rational
    }
};