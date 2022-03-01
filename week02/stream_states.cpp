#include <iostream>

int main() {

  int x;
  std::cin >> x; // пробвайте с въвеждане на число, буква или eof (ctrl + Z за windows, ctrl + D за linux)

  std::cout << "good: " << std::cin.good() << '\n';
  std::cout << "eof: " << std::cin.eof() << '\n';
  std::cout << "fail: " << std::cin.fail() << '\n';
  std::cout << "bad: " << std::cin.bad() << '\n';

  std::cin.clear();
  
  std::cout << "\nAfter clear:\n\n";
  
  std::cout << "good: " << std::cin.good() << '\n';
  std::cout << "eof: " << std::cin.eof() << '\n';
  std::cout << "fail: " << std::cin.fail() << '\n';
  std::cout << "bad: " << std::cin.bad() << '\n';

  return 0;
}