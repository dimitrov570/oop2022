#include "Person.hpp"
#include <iostream>
#include <cstring>

Person::Person(const char* Name, int Age) : age(Age)
{
    int nameLength = strlen(Name);
    name = new char[nameLength + 1];
    strcpy(name, Name);
}

Person::Person(const Person& copyFrom)
{
    int nameLength = strlen(copyFrom.name);
    name = new char[nameLength + 1];
    strcpy(name, copyFrom.name);
    age = copyFrom.age;
}

Person& Person::operator=(const Person& rhs)
{
    if(this != &rhs)
    {
        delete[] name;
        int nameLength = strlen(rhs.name);
        name = new char[nameLength + 1];
        strcpy(name, rhs.name);
        age = rhs.age;
    }
    return *this;
}

Person::~Person()
{
    delete[] name;
}

const char* Person::getName() const
{
    return name;
}

int Person::getAge() const
{
    return age;
}

void Person::print() const
{
    std::cout << "Name: " << name << "; age: " << age;
}

void Person::println() const
{
    std::cout << "Name: " << name << "; age: " << age << '\n';
}

bool Person::setName(const char* newName)
{
    int nameLength = strlen(newName);
    if(nameLength > 0)
    {
        delete[] name;
        name = new char[nameLength + 1];
        strcpy(name, newName);
        return true;
    }
    return false;
}

bool Person::setAge(int newAge)
{
    if(newAge >= 0)
    {
        age = newAge;
        return true;
    }
    return false;
}


bool Person::operator<(const Person& rhs) const
{
    return this->age < rhs.age;
}