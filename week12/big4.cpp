#include <iostream>

class A {

public:
  A() {
    std::cout << "A()\n";
  }
  
  A(int) {
    std::cout << "A(int)\n";
  }

  A& operator=(const A&) {
    std::cout << "A::operator=()\n";
    return *this;
  }

  ~A() {
    std::cout << "~A()\n";
  }

  void print() const {
    std::cout << "A::print()\n";
  }
  

};

class B : public A {

public:
  
  int publicB;

  B() : A(4) {
    std::cout << "B()\n";
  }
  
  B(int) {
    std::cout << "B(int)\n";
  }

  B& operator=(const B& other) {
    A::operator=(other);
    std::cout << "B::operator=()\n";
    return *this;
  }

  ~B() {
    std::cout << "~B()\n";
  }

  void print() const {
    A::print();
    std::cout << "B::print()\n";
  }

};

int main() {

  B obj_B;

//  obj_B.print();
  
  B* ptr_B = &obj_B;

  ptr_B->print();
  ptr_B->publicB;

  std::cout << "------------------------\n";

  A* ptr_A = &obj_B;
  //ptr_A->publicB;

  A obj_A = obj_B;

  ptr_A->print();

  return 0;
}