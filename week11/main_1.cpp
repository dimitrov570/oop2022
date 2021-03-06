#include <iostream>
#include <string>


class Student {

  int age;
  std::string name;

public:

  Student() = default;

  Student(const char* _name, int _age) : name(_name), age(_age) { 
 
  }

  Student(Student&& other) : name(std::move(other.name)), age(other.age) {
    
  }

  Student& operator=(Student&& other) {
    if(this != &other) {
      name = std::move(other.name);
      age = other.age;
     }
    return *this;
  }

};

Student makeStudent(const char* name, int age) {
  Student st(name, age);
  // st
  return st;
}


int main() {

  Student st;
  st = makeStudent("ivan", 33);

  return 0;
}