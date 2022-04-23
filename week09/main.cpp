#include <iostream>

struct Point2D {
  int x;
  int y;
};

class Rectangle {

  Point2D first;
  Point2D second;

};


class Person {
  // members

public:
  Person() {
    std::cout << "Person() ";
  }
};

class Student {

  Person* bff;

public:

  Student() {
    std::cout << "Student() ";
  }

};

class Room {


};


class House {

//  Room room;
//  Room rooms[10];
};


class Data {

public:

  Data() {
    std::cout << "Data() ";
  }
  
  Data(int) {
    std::cout << "Data(int) ";
  }

  Data(const Data&) {
    std::cout << "Data(const Data&) ";
  }

  Data& operator=(const Data&) {
    std::cout << "Data::operator=(const Data&) ";
    return *this;
  }

  ~Data() {
    std::cout << "~Data() ";
  }

};

class MyClass {

  Data data;

public:

  MyClass() : data(Data(1)) {
    std::cout << "MyClass() ";
  }

  MyClass(const MyClass& other) : data(other.data) {
    std::cout << "MyClass(const MyClass&) ";
  }

  MyClass& operator=(const MyClass& other) {
    data = other.data; // data.operator=(other.data) 
    std::cout << "MyClass::operator=(const MyClass&) ";
    return *this;
  }

  ~MyClass() {
    std::cout << "~MyClass() ";
  }

};

int main() {

  std::cout << "\n------------------------------------\n";
  {
    MyClass myClass_object;
    std::cout << '\n';
  }
  
  std::cout << "\n------------------------------------\n";

  {
    MyClass myClass_object;
    std::cout << '\n';
    MyClass myClass_object2 = myClass_object;
    std::cout << '\n';
  }
  
  std::cout << "\n------------------------------------\n";

  {
    MyClass myClass_object;
    std::cout << '\n';
    MyClass myClass_object2;
    std::cout << '\n';
    myClass_object2 = myClass_object;
    std::cout << '\n';
  }

  std::cout << "\n------------------------------------\n";
  Student student;

  return 0;
}