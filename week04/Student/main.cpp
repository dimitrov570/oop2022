#include <iostream>
#include "Student.hpp"

void foo() {
  
  Student s("foo", 3);

}

int main() {

  { 
    Student s("scope_main", 3);
  }

  char* ivan = new char[strlen("Ivan") + 1];
  strcpy(ivan, "Ivan");

  Student s(ivan, 12345);

  ivan[0] = 'o';

  // ако в конструктора на Student просто се присвояваше this->name = name
  // тук щеше да изведе 'ovan'
  std::cout << s.name << '\n';

  foo();

  delete[] ivan;
    
  std::cout << s.name << '\n';

  return 0;
}