#include <iostream>
#include <string>
#include <fstream>

// програмата чете от стандартния вход и пише върху файл подаден като аргумент на програмата

int main(int argc, char** argv) {

  if(argc != 2) {
    return 1;
  }

  char* filename = argv[1];

  std::ofstream output_stream;
  output_stream.open(filename, std::ios_base::out | std::ios_base::app);
  
  std::string line;

  while(std::getline(std::cin, line)) {
    output_stream << line << '\n';
  }

  output_stream.close();
  
  return 0;
}