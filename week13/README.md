# Виртуални функции

Нека разгледаме следните два класа: `Person` и `Student` който го наследява. Разглеждаме само `.hpp` файловете, абстрахирайки се от имплементацията.

- `Person.hpp`:
```c++
class Person
{
protected:

    char* name;
    int age;

public:
    Person(const char* Name, int Age);
    Person(const Person& copyFrom);
    Person& operator=(const Person& rhs);
    ~Person();
    
    const char* getName() const;
    int getAge() const;

    void print() const;
    void println() const;

    bool setName(const char*);
    bool setAge(int);

    bool operator<(const Person& rhs) const;
};
```

- `Student.hpp`:
```c++
class Student : public Person
{
    int facultyNumber;

public:
    Student(const char* _name, int _age, int _fn);

    int getFacultyNumber() const;

    void print() const;
    void println() const;
};
```

Ще разгледаме само имплементациите на методите `println()` в двата класа:
```c++
void Person::println() const
{
    std::cout << "Name: " << name << "; age: " << age << '\n';
}

void Student::println() const 
{
    Person::print();
    std::cout << "; fn: " << facultyNumber << '\n';
}
```

Сега нека разгледаме следния код и да видим какъв е изхода от него:
```c++
int main()
{ 
    Student student("Ivan Ivanov", 22, 888888);
    student.println();

    std::cout << "----------------------\n";

    Student* ptrOfTypeStudent = &student;
    ptrOfTypeStudent->println();

    std::cout << "----------------------\n";

    Student& referenceOfTypeStudent = student;
    referenceOfTypeStudent.println();

    return 0;
}
```

Изхода е както се очаква:
```
Name: Ivan Ivanov; age: 22; fn: 888888
----------------------
Name: Ivan Ivanov; age: 22; fn: 888888
----------------------
Name: Ivan Ivanov; age: 22; fn: 888888
```

Понеже `Student` е наследник на `Person`, можем да имаме указатели и референции от тип `Person` към обекти от тип `Student`, което ни позволява да направим следното нещо:

```c++
int main()
{ 
    Student student("Ivan Ivanov", 22, 888888);
    student.println();

    std::cout << "----------------------\n";

    Person* ptrOfTypePerson = &student;
    ptrOfTypePerson->println();

    std::cout << "----------------------\n";

    Person& referenceOfTypePerson = student;
    referenceOfTypePerson.println();

    return 0;
}
```

Изхода от тази програма е:
```
Name: Ivan Ivanov; age: 22; fn: 888888
----------------------
Name: Ivan Ivanov; age: 22
----------------------
Name: Ivan Ivanov; age: 22
```

В този случай, когато извикваме метода `println()` чрез указател и референция от тип `Person` извиква се метода `println()` от класа `Person`, а не от `Student`. Методът, който ще се извиква се определя по време на компилация и това нещо се нарича `static (early) binding`.

Нека добавим още един клас `Teacher`, който също да наследява `Person`:
```c++
class Teacher : public Person
{

int salary;

public:
    Teacher(const char*, int, int);

    int getSalary() const;

    void print() const;
    void println() const;
};
```

Нека имаме вектор от указатели от тип `Person` (`std::vector<Person*> teachersAndStudents`), които да сочат към обекти от тип `Student` и `Teacher`. Ако искаме да изпечатаме данните за тях на стандартния изход, ще напишем следното:
```c++
    for(Person* ptr : teachersAndStudents)
    {
        ptr->println();
    }
```

Това, както видяхме от примера преди, ще изпечата само `Person` частта на обектите (име и години). Ако искаме да се извежда цялата информация имаме следния вариант: при всяка итерация на цикъла да проверяваме какъв е типът на обекта, към който сочи указателя, и да преобразуваме указателя то този тип. Типа на обекта можем да проверяваме с помощта на  [typeid](https://en.cppreference.com/w/cpp/language/typeid). Пример:
```c++
    for(Person* ptr : vec)
    {
        if(typeid(*ptr) == typeid(Student))
        {
            ((Student*)ptr)->println();
        }
        else if (typeid(*ptr) == typeid(Teacher))
        {
            ((Teacher*)ptr)->println();
        }
    }
```
Вече получаваме очаквания резултат. Но, ако се наложи да се премахне някой клас или да се добавя нови, навсякъде, където има такъв код ще трябва да се добавя или премахва нещо, което не е удобно. 

Затова в `C++` съществуват виртуални функции. Слагайки ключовата дума `override` пред нейната декларация, правим я вирутална. За класа `Person` това изглежда по следния начин:
```c++
class Person
{
protected:

    char* name;
    int age;

public:
    Person(const char* Name, int Age);
    Person(const Person& copyFrom);
    Person& operator=(const Person& rhs);
    ~Person();
    
    const char* getName() const;
    int getAge() const;

    virtual void print() const;  // ТУК
    virtual void println() const; // И ТУК

    bool setName(const char*);
    bool setAge(int);

    bool operator<(const Person& rhs) const;
};
```
Тези фунцкии са виртуални и за всеки клас, наследник на `Person` и без да се пише ключовата дума `virtual` при тях. Когато се пренаписва виртуална функция, в клас наследник, може да се сложи (опционално) ключовата дума `override` след нейната декларация, да се укаже, че се пренаписва. Пример:
```c++
class Student : public Person
{
    int facultyNumber;

public:
    Student(const char* _name, int _age, int _fn);

    int getFacultyNumber() const;

    void print() const override; // ТУК
    void println() const override; // И ТУК
};
```
Какво ни позволяват виртуалните функции? Позволяват ни `dynamic (late) binding`. Това означава, че определянето кой метод да се извика става по време на изпълнение (runtime), а не по време на компилация. Тук кой метод ще се извика зависи от типа на обекта, към който сочи указателя, чрез който го извикваме, а не от типа на указателя. Същото важи и за референции.
Вече с виртуални функции следният код:
```c++
int main()
{ 
    Student student("Ivan Ivanov", 22, 888888);
    student.println();

    std::cout << "----------------------\n";

    Person* ptrOfTypePerson = &student;
    ptrOfTypePerson->println();

    std::cout << "----------------------\n";

    Person& referenceOfTypePerson = student;
    referenceOfTypePerson.println();

    return 0;
}
```
извежда:
```
Name: Ivan Ivanov; age: 22; fn: 888888
----------------------
Name: Ivan Ivanov; age: 22; fn: 888888
----------------------
Name: Ivan Ivanov; age: 22; fn: 888888
```

И примера с вектора от студенти и преподаватели:
```c++
    for(Person* ptr : teachersAndStudents)
    {
        ptr->println();
    }
```
вече извежда пълната информация за обектите, без да се налага да се преобразува типът на указателите.

### Как работят виртуалните функции?
По стандарт не е дефинирано как да се имплементират, но повечето компилатори използват така наречените виртуални таблици. Всеки обект освен член-данните си пази и указател към виртуална таблица за класа към който принадлежи. Виртуалните таблици пазят указатели, които сочат към кодовете на виртуалните функции. Когато се извиква някой виртуален метод чрез указател или референция към обект, с помощта на указателя към виртуалната таблица (който се пази в обекта) се поглежда във виртуалната таблица и от указателя към метода в нея се разбира къде се намира кода за съответния метод. Това ни позволява да имаме `dynamic binding` в C++. Ако някой метод не е пренаписан в класа наследник, тогава указателя във виртуална таблица за този метод ще сочи към кода на метода от базовия клас. 

Повече информация и илюстрация за виртуалните таблици може да намерите [тук](https://www.learncpp.com/cpp-tutorial/the-virtual-table/).

#

Най-често задавани въпроси относно виртуални функции може да намерите [тук](https://isocpp.org/wiki/faq/virtual-functions).

# Полиморфизъм

## Виртуален деструктор

Когато има поне една виртуална функция в някой клас и деструктора трябва да е виртуален, за да се извика правилния деструктор когато трием обекти от динамичната памет чрез указател от базов клас.

# Абстрактни класове