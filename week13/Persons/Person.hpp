#pragma once

class Person
{
protected:

    char* name;
    int age;

public:
    Person(const char* Name, int Age);
    Person(const Person& copyFrom);
    Person& operator=(const Person& rhs);
    virtual ~Person();
    
    const char* getName() const;
    int getAge() const;

    virtual void print() const;
    virtual void println() const;

    bool setName(const char*);
    bool setAge(int);

    bool operator<(const Person& rhs) const;

};