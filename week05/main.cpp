#include "OurString.hpp"
#include <iostream>

int main() {

  OurString str("hello");

  const char* data_arr = str.data();

  str.print(std::cout);
  std::cout << "\n\n";

  std::cout << "char at pos 2: " << str.at(2) << '\n';
  std::cout << "str.empty(): " << str.empty() << '\n';
  std::cout << "str.size(): " << str.size() << '\n';

  // str.clear();

  // std::cout << "After clear:\n";
  // std::cout << "str.empty(): " << str.empty() << '\n';
  // std::cout << "str.size(): " << str.size() << '\n';
  
  std::cout << "\n\n";

  str.setString("hello world");

  str.print(std::cout);
  std::cout << "\n\n";

  std::cout << "char at pos 2: " << str.at(2) << '\n';
  std::cout << "str.empty(): " << str.empty() << '\n';
  std::cout << "str.size(): " << str.size() << '\n';

  return 0;
}