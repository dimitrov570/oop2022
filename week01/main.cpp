#include <iostream>
#define val 6

struct Unaligned {
  uint8_t x;
  uint32_t y;
  uint16_t z;
};

struct Aligned {
  uint8_t x;
  uint8_t h;
  uint16_t z;
  uint32_t y;
};

int main() {

  std::cout << sizeof(Aligned) << '\n';  
  std::cout << sizeof(Unaligned) << '\n';  

  return 0;
}