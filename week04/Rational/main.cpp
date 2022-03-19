#include <iostream>
#include <fstream>
#include "Rational.hpp"

void print() {
  int a = 4;
  std::cout << "Hello world" << a;
}

int main() {

  Rational r;

  Rational r1(1, 3);
  Rational r2(3);

  r1.setDenominator(5);

  std::cout << r1.getNumerator() << '\n';

  Rational result = r1.add(r2);

  result.print(std::cout);
  std::cout << '\n';
  
  return 0;
}