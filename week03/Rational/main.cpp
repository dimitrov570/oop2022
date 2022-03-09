#include <iostream>
#include <fstream>
#include "Rational.hpp"

int main() {

  Rational r1 = {2, 3};
  
  Rational rational_array[] = {{2,3}, {4,5}, {6,7}, {8,9}};

  std::ofstream output_text_file_stream("Rationals.txt", std::ios::out);

  if(output_text_file_stream.is_open()) {
    
    for(int i = 0; i < sizeof(rational_array) / sizeof(rational_array[0]); ++i) {
      print(output_text_file_stream, rational_array[i]);
      output_text_file_stream << '\n';
    }

    output_text_file_stream.close();  
  }

  std::ifstream input_text_file_stream("Rationals.txt", std::ios::in);
  
  if(input_text_file_stream.is_open()) {
    Rational r2 = read(input_text_file_stream);

    // std::cout << r2.numerator << '/' << r2.denominator << '\n';

    input_text_file_stream.close();
  }


  std::ofstream output_bin_file_stream("Rationals.bin", std::ios::out | std::ios::binary);

  if(output_bin_file_stream.is_open()) 
  {
    for(int i = 0; i < sizeof(rational_array) / sizeof(rational_array[0]); ++i) {
      serialize(output_bin_file_stream, rational_array[i]);
    }

    output_bin_file_stream.close();
  }


  std::ifstream input_bin_file_stream("Rationals.bin", std::ios::in | std::ios::binary);
  
  if (input_bin_file_stream.is_open()) {
    // Преместваме позицията за четене на третото число във файла
    input_bin_file_stream.seekg(2 * sizeof(Rational), std::ios_base::beg);

    Rational r3 = deserialize(input_bin_file_stream);

    std::cout << r3.numerator << '/' << r3.denominator << '\n';
  }

  return 0;
}