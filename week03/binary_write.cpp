#include <iostream>
#include <fstream>

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

  std::ofstream output_stream("output.bin", std::ios::out | std::ios::binary);

  if(output_stream.is_open()) {
  
    Unaligned unaligned_obj = {0x11, 0x22222222, 0x3333};
    // output_stream.write((const char *)&unaligned_obj, sizeof(unaligned_obj));

    Aligned aligned_obj = {0x11, 0x22, 0x3333, 0x44444444};
    Aligned aligned_array[] = {{11, 22, 33333, 44444}, {0x11, 0x22, 0x3333, 0x44444444}, {0x11, 0x22, 0x3333, 0x44444444}};
    
    output_stream.write((const char *)&aligned_obj, sizeof(aligned_obj));

    output_stream.close();
  }

  return 0;
}