#pragma once
#include "Person.hpp"

class Student : public Person
{
    int facultyNumber;

public:
    Student(const char* _name, int _age, int _fn);

    int getFacultyNumber() const;

    void print() const override;
    void println() const override;
};