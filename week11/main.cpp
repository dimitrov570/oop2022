#include <iostream>
#include <string>

class Student {
  char* name;

  int age;

  void allocate_name(const char* other_name) {
    name = new char[strlen(other_name) + 1];
    strcpy(name, other_name);
  }

  void free() {
    delete[] name;
  }

public:

  Student() = default;


  Student(const char* _name, int _age) : age(_age) 
  { 
    allocate_name(_name);
  }

  Student(const Student& other) : age(other.age) {
    allocate_name(other.name);
  }

  Student(Student&& other) : name(other.name), age(other.age) {
    other.name = nullptr;
  }

  Student& operator=(Student&& other) {
    if(this != &other) {
      free();
      name = other.name;
      age = other.age;
    }
    return *this;
  }


  ~Student()
  {
    free();
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

  int a = 4;
  int b = a;

  return 0;
}