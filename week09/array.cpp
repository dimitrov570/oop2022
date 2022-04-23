#include <iostream>

class MyClass
{
private:
  /* data */
public:
  MyClass() {
    std::cout << "MyClass() ";
  }


  ~MyClass() {
    std::cout << "~MyClass() ";
  }
};


const int ARRAY_SIZE = 5;

int main() {

  // EXAMPLE WITH STATIC ARRAY

  MyClass* array[ARRAY_SIZE];

  std::cout << array[0] << '\n';
  
  MyClass obj;

  array[0] = &obj;

  
  std::cout << array[0] << '\n';
  
  std::cout << &obj << '\n';
  

  std::cout << array[1] << '\n';

  array[1] = new MyClass();

  std::cout << array[1] << '\n' ;

  // delete[] array;           ???????????

  // for(int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {     ????????????
  //   delete array[i];
  // }

  delete array[1];

  std::cout << "\n\n------------------------------------\n\n";

  // EXAMPLE WITH DYNAMIC ARRAY

  MyClass* dynamic_array = new MyClass[ARRAY_SIZE];

  // for(int i = 0; i < sizeof(dynamic_array) / sizeof(dynamic_array[0]); ++i) {
  //   delete dynamic_array[i];
  // }

  delete[] dynamic_array;

  return 0;
}