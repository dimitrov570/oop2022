#include "Person.hpp"

class Teacher : public Person
{

int salary;

public:
    Teacher(const char*, int, int);

    int getSalary() const;

    void print() const override;
    void println() const override;
};