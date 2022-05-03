#include <iostream>
#include "Pair/Pair.hpp"

// void swap(int& a, int& b) {
//   int temp = a;
//   a = b;
//   b = temp;
// }


template <typename T>
void swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
T max(T& a, T& b) {
  return a > b ? a : b;
}

// int max(int& a, int& b) {
//   return a >= b ? a : b;
// }

template <typename T, typename K>
void foo(T a, T b, K c) {
  //
}

int main() {

  int a = 3;
  int b = 4;
  double c = 4.5;
  int d = a > b ? a : b;


  Pair<> f(3, 3);
  Pair<> g(2, 2);

//  max(f, g); - no operator > for Pair<>

  return 0;
}