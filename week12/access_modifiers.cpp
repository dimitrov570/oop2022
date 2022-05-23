#include <iostream>

class A {
  int privateA;

protected:
  int protectedA;

public:
  int publicA;

};

class B : public A {
  // inherited from A
  // int privateA; innacessible
  // int protectedA; protected
  // int publicA; public

  int privateB;

protected:
  int protectedB;

public:
  int publicB;

  void foo() {
    // privateA = 1; забранен достъп
    protectedA = 1;
    publicA = 1;
  }

};

class C : protected A {
  // inherited from A
  // int privateA; innacessible
  // int protectedA; protected
  // int publicA; protected

  int privateC;

protected:
  int protectedC;

public:
  int publicC;

  int COMMON_VAR;

    void foo() {
    // privateA = 1; забранен достъп
    protectedA = 1;
    publicA = 1;
  }
};

class D : private A {
  // inherited from A
  // int privateA; innacessible
  // int protectedA; private
  // int publicA; private

  int privateD;

protected:
  int protectedD;

public:
  int publicD;


  void foo() {
    // privateA = 1; забранен достъп
    protectedA = 1;
    publicA = 1;
  }
};

class F {

public:
  int COMMON_VAR;

};

class E : public C, public F {

  // C inherits A as protected

  // inherited from A
  // int privateA; inaccessible
  // int protectedA; protected
  // int publicA; protected

  // inherited from C
  // int privateC; inaccessible
  // int protectedC; protected
  // int publicC; public

  void foo() {
    // privateA = 1; забранен достъп
    protectedA = 1;
    publicA = 1;
    // privateC = 1; забранен достъп
    protectedC = 1;
    publicC = 1;

    
    F::COMMON_VAR;
  }

};

int main() {

  B obj_B;

  // obj_B.privateA;
  //obj_B.protectedA;
  obj_B.publicA;

  C obj_C;
  // obj_C.publicA;

  D obj_D;
  //obj_D.publicA;

  E obj_E;
  //obj_E.publicA;
  obj_E.publicC;

  return 0;
}