#include <iostream>
#include <cstring>

class Student {
  char* name;

  int age;

  void copy_array(const char* other_name) {
    name = new char[strlen(other_name) + 1];
    strcpy(name, other_name);
  }

  void free() {
    delete[] name;
  }

public:

  Student() : name(nullptr) { // name трябва да е nullptr, за да няма грешки при delete[] name
    age = -1;
  }

  Student(const char* _name, int _age) : age(_age) 
  { 
    copy_array(_name);
  }

  Student(const Student& other) : age(other.age) {
    copy_array(other.name);
  }

  Student(Student&& other) : name(other.name), age(other.age) {
     other.name = nullptr;
  }

  Student& operator=(const Student& other) {
  
    if(this != &other) {
      free();

      copy_array(other.name);
      age = other.age;
    }

    return *this;
  }

  Student& operator=(Student&& other) {
    
    if(this != &other) {
      free();
      name = other.name;
      age = other.age;

      other.name = nullptr;
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