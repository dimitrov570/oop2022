#include <iostream>
#include "OurString.hpp"

int main() {

  OurString str1("string 1");

  OurString str2 = str1;

  std::cout << "str1: " << str1.data() << '\n';
  std::cout << "str2: " << str2.data() << '\n';

  std::cout << "str1 size: " << str1.size() << '\n';
  std::cout << "str2 size: " << str2.size() << '\n';
  
  str1.setString("changed string 1");

  std::cout << "str1: " << str1.data() << '\n';
  std::cout << "str2: " << str2.data() << '\n';
  std::cout << "str1 size: " << str1.size() << '\n';
  std::cout << "str2 size: " << str2.size() << '\n';

  std::cout << "\n\n";

  str2.setString("string 2");

  OurString str3("string 3");

  str3 = str2;
  
  std::cout << "str2: " << str2.data() << '\n';
  std::cout << "str3: " << str3.data() << '\n';
  std::cout << "str2 size: " << str2.size() << '\n';
  std::cout << "str3 size: " << str3.size() << '\n';

  str2.setString("changed string 2");
  std::cout << "str2: " << str2.data() << '\n';
  std::cout << "str3: " << str3.data() << '\n';
  std::cout << "str2 size: " << str2.size() << '\n';
  std::cout << "str3 size: " << str3.size() << '\n';

  str3 = str3;
  std::cout << "str3: " << str3.data() << '\n';
  std::cout << "str3 size: " << str3.size() << '\n';

  return 0;
}