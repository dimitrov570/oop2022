#include "Student.hpp"
#include <iostream>

Student::Student(const char* _name, int _age, int _fn) : Person(_name, _age), facultyNumber(_fn)
{}

int Student::getFacultyNumber() const 
{
    return facultyNumber;
}

void Student::print() const 
{
    Person::print();
    std::cout << "; fn: " << facultyNumber;
}

void Student::println() const 
{
    Person::print();
    std::cout << "; fn: " << facultyNumber << '\n';
}