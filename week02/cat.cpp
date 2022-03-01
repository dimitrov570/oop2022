#include <iostream>
#include "Rational.hpp"
#include <string>
#include <fstream>

void cat_from_stdin() {
  std::string line;

  while(std::getline(std::cin, line)) {
    std::cout << line << '\n';
  }
}

void cat_from_file(char* filename) {
  std::ifstream input_stream;
  input_stream.open(filename, std::ios::in);
  char c;
  while(input_stream >> c) {
    std::cout << c;
  }
  
  input_stream.close();
}

int main(int argc, char** argv) {

  if(argc == 1) {
    cat_from_stdin();
  }

  for(int i = 1; i < argc; ++i) {
    cat_from_file(argv[i]);
  }

  
  return 0;
}