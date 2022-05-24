#include "Teacher.hpp"
#include <iostream>

Teacher::Teacher(const char* _name, int _age, int _salary) : Person(_name, _age), salary(_salary)
{}

int Teacher::getSalary() const
{
    return salary;
}

void Teacher::print() const
{
    Person::print();
    std::cout << "; salary: " << salary;
}

void Teacher::println() const
{
    Person::print();
    std::cout << "; salary: " << salary << '\n';
}