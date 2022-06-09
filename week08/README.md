# Оператори

## Характеристики на операторите
- асоциативност
- приоритет
- позиция спрямо аргументите (префиксен, инфиксен, постфиксен)  
#
Тези характеристики не могат да се променят. Обаче, могат да се предефинират операторите, така че да работят с потребителски дефинирани класове.  
Операторите за вградените стойности не могат да се предефинират. При предефинирането поне един параметър трябва да е потребителски дефиниран клас.  
Повече информация [тук](https://en.cppreference.com/w/cpp/language/operators).  

Операторите :: (scope resolution), . (member access), .* (member access through pointer to member), и ?: (ternary conditional) не могат да бъдат предефинирани. 

Съществуват 2 начина за предефиниране на операторите:
- чрез методи на класа (член-функции)
- чрез обикновени функции

### Предефиниране чрез методи на класа
Понеже методите на класа като първ аргумент получават обекта, чрез който са извикани, дефинираните като методи на класа двуместни оператори ще работят само, когато обект от този клас е първия аргумент при извикване.

Примерно, ако за класа ``Rational`` предефинираме ``operator+``, който приема цяло число, като метод на класа(член-функция), по следния начин:
```c++
    Rational operator+(int x) const 
    {
        return Rational(numerator + denominator*x, denominator);
    }
``` 
тогава:
```c++
    Rational r(1,2);
    r + 2; //ще работи
    2 + r; //няма да работи
```
В случая ``r + 2`` се превежда до ``r.operator+(2)``.

### Предефиниране чрез обикновени функции
За да работят изрази като ``2 + r`` налага се да се предефинира оператора, така че той да приема като първи аргумент ``int``, а като втори ``Rational``. Понеже член-функциите винаги приемат като първи аргумент обекта, чрез който са извикани, налага се операцията да се предефинира чрез външна за класа функция. Пример:
```c++
Rational operator+(int x, const Rational& r)
{
    return Rational(r.getNumerator() + r.getDenominator()*x, r.getDenominator());
}
```
Тук трябва да се обърне внимание на това, че понеже функцията не е метод на класа, не могат да се достъпят ``private`` членовете директно.

### Оператор за присвояване (operator=)
Ако не е дефиниран, автоматично се генерира такъв, който просто копира стойностите на член-данните. В класа ``Rational`` не се използват външни ресурси, затова няма нужда да се предефинира този оператор, както и конструктор за копиране и деструктор.

Разгледайте класа ``Person``:
```c++
class Person
{
    char *name;

public:
    Person(const char* Name = "Anonymous") 
    {
        int length = strlen(Name);
        name = new char[length + 1]; //+ 1 for '\0'
        strcpy(name, Name);
    }

    Person(const Person& copyFrom)
    {
        int length = strlen(copyFrom.name);
        name = new char[length + 1]; //+ 1 for '\0'
        strcpy(name, copyFrom.name);
    }

    const char* getName() const 
    {
        return name;
    }

    void setName(const char* newName) 
    {
        if(name != nullptr) 
        {
            delete[] name;
        }
        int length = strlen(newName);
        name = new char[length + 1]; //+ 1 for '\0'
        strcpy(name, newName);
    }
};
```
Тук автоматично генерираният оператор за присвояване ще копира член-данните и възниква същия проблем както и при конструктора за копиране. Затова се налага да се предефинира.  
Обаче, понеже това не е конструктор, обекта вече е създаден и първо трябва да се погрижи да се освободят ресурсите, преди да се заделят нови.
```c++
    Person& operator=(const Person& rhs)
    {
        delete[] name;
        int length = strlen(rhs.name);
        name = new char[length + 1]; //+ 1 for '\0'
        strcpy(name, rhs.name);
        
        return *this;
    }
```

Какво ще се случи при изпълнението на:
```c++
    Person a("Some Name");
    a = a;
```

Затова трябва да се провери дали обекта, който е подаден като аргумент, не е обекта, чрез който се извиква оператора за присвояване:
```c++
    Person& operator=(const Person& rhs)
    {
        if(this != &rhs)
        {
            delete[] name;
            int length = strlen(rhs.name);
            name = new char[length + 1]; //+ 1 for '\0'
            strcpy(name, rhs.name);
        }

        return *this;
    }
```

- Защо типът на връщаната стойност е ``Person&``?

### Префиксни и постфиксни ``--`` и ``++``
- Префиксни
    ```c++
        Rational& operator++()
        {
            numerator += denominator;
            return *this;
        }

        Rational& operator--()
        {
            numerator -= denominator;
            return *this;
        }
    ```
- Постфиксни

    ```c++
        Rational operator++(int)
        {
            Rational r = *this; //запазва се старата стойност
            numerator += denominator; //променя се стойността
            return r; //връща се старата стойност
        }

        Rational operator--(int)
        {
            Rational r = *this; //запазва се старата стойност
            numerator -= denominator; //променя се стойността
            return r; //връща се старата стойност
        }
    ```

Параметъра при постфиксните е фиктивен, не се използва, а само указва, че това е постфиксна операция.
Защо типовете на връщаните стойности се различават?

### Преобразуване на тип
Метода ``toDouble()`` от ``Rational`` можем да го заместим с оператор за преобразуване на тип:
```
    operator double() 
    {
         return (double)numerator / denominator;
    }
``` 

# Приятелски класове и функции

Класове и външни функции, които имат достъп до `private` и `protected` членовете на клас, който ги дефинира като такива.

Пример за класа [Student](https://github.com/dimitrov570/oop2021/tree/main/week05/Student):  
В .hpp файл:
```c++
#pragma once
#include <iostream>

class Student
{
    //...
    friend std::ostream& operator<<(std::ostream& o, const Student& student);
    //...
};
```

В .cpp файл:
```c++
#include "Student.hpp"
#include <iostream>
#include <cstring>

//...
std::ostream& operator<<(std::ostream& o, const Student& student)
{
    return o << "Name: " << student.name << "; FN: " << student.facultyNumber << "; age: " << student.age << '\n';
}
//...
```

В main.cpp:
```c++
#inlcude <iostream>
#include "Student.hpp"

int main()
{

    Student ivan("Ivan", 10, 20);
    std::cout << ivan;

    return 0;
}
```
Резултата от изпълнението на тази програма ще бъде:   ``Name: Ivan; FN: 10; age: 20``
