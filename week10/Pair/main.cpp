#include <iostream>
#include "Pair.hpp"
#include <vector>


int main() {

  Pair<> my_pair(1, 2);

  std::cout << my_pair.getFirst() << " : " << my_pair.getSecond() << '\n';
  
  std::cout << my_pair << '\n';

  Pair<int, int> my_pair2(2, 3.5); // 3.5 ще се кастне към 3

  std::cout << my_pair2 << '\n';

  return 0;
}