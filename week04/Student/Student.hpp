#pragma once
#include <iostream>
#include <cstring>

struct Student
{
  char* name;
  int fn;

  Student(char* name, int fn) : fn(fn), name(name) {
    std::cout << name << ": " << "Student()\n";
  }

  ~Student() {
    std::cout << name << ": " << "~Student()\n";

    delete[] name;
  }

};
