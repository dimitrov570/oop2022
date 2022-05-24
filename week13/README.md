# Виртуални функции

Нека разгледаме следните два класа: `Person` и `Student`, който го наследява. Разглеждаме само `.hpp` файловете, абстрахирайки се от имплементацията.

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

Това, както видяхме от примера преди, ще изпечата само `Person` частта на обектите (име и години). Ако искаме да се извежда цялата информация имаме следния вариант: при всяка итерация на цикъла да проверяваме какъв е типът на обекта, към който сочи указателя, и да преобразуваме указателя до този тип. Един вариант за това е да добавим променлива (примерно enum) в Person, която да казва от какъв тип е обекта.

```c++

enum Type {
    PERSON,
    STUDENT,
    TEACHER
};

class Person
{
protected:

    char* name;
    int age;
    Type type;

public:
    Person(const char* Name, int Age);
    Person(const Person& copyFrom);
    Person& operator=(const Person& rhs);
    ~Person();

    Type getType() const;    
    const char* getName() const;
    int getAge() const;

    void print() const;
    void println() const;

    bool setName(const char*);
    bool setAge(int);

    bool operator<(const Person& rhs) const;
};
```

И след това да проверяваме от какъв тип е и да преобразуваме: 
 
 Пример:
```c++
    for(Person* ptr : teachersAndStudents)
    {
        if(ptr->getType() == STUDENT)
        {
            ((Student*)ptr)->println();
        }
        else if (ptr->getType() == TEACHER)
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

# Абстрактни класове

Абстрактен клас е клас, който има поне една чисто виртуална (pure virtual) функция. Чисто виртуална функция се създава като се напише ` = 0;` при декларацията на функцията. Пример:

```c++
    class A {

    public:
        virtual void foo() const = 0;
    }

```

Това означава, че тази функция е чисто виртуална и чисто виртуалните фунцкии най-често не се имплементират, а се override-ват в клас-наследник. Ако в клас-наследник не се override-ва тя си остава чисто виртуална и в него и той ще е абстрактен клас. Обаче, не е забранено да се имплементира чисто виртуална функция. Повече за това може да намерите на следните адреси:
- https://stackoverflow.com/questions/2089083/pure-virtual-function-with-implementation
- https://stackoverflow.com/questions/12918637/why-does-it-make-sense-to-give-definition-for-a-pure-virtual-function

Override-ване на чисто виртуална функция става по следния начин:
```c++
    class B: public A {

    public:
        void foo() const override {
            // code
        }
    }
```

#### Обекти от абстрактен клас не могат да бъдат създавани.

Ако искаме да направим някой клас абстрактен, но не искаме да направим нито една функция чисто виртуална, тогава може да направим деструктора на този клас чисто виртуален, но трябва задължително да го имплементираме. Пример:

```c++
    class A {

    public:
        void foo() const;

        virtual ~A() = 0;
    }

    A::~A() {

    }

```

# Множествено наследяване

C++ ни позволява да правим множествено наследяване, т.е. даден клас да наследява повече от един клас. Конструкторите на базовите класове ще се извикат в реда, в който са наследени, а деструкторите в обратен ред.

Нека разгледаме следните класове:

```c++
    class A
    {
    protected:
        int varA;

    public:

        A(int _varA = 0) : varA(_varA) {}

        void print()
        {
            std::cout << "class A: varA - " << varA;
        }

    };

    class B : public A
    {
        int varB;

    public:

        B(int _varA, int _varB) : A(_varA), varB(_varB) {}

        void print()
        {
            A::print();
            std::cout << "class B: varB - " << varB;
        }

    };

    class C : public A
    {
        int varC;

    public:

        C(int _varA, int _varC) : A(_varA), varC(_varC) {}

        void print()
        {
            A::print();
            std::cout << "class C: varC - " << varC;
        }

    };

    class D : public B, public C
    {
        int varD;

    public:

        D(int _varA, int _varB, int _varC, int _varD) : B(_varA, _varB), C(_varA, _varC), varD(_varD) {}

        void print()
        {
            B::print();
            std::cout << '\n';
            C::print();
            std::cout << '\n';
            std::cout << "class D: varD - " << varD;
        }

    };
```

Тук вече класът `D` ще съдържа два пъти класа `A`, един път през `B` и един път през `C`. Ако се опитаме в класа `D` да достъпим нещо от `A`, като например променливата `varA`, компилатора няма да знае коя да достъпи, дали тази наследена от `B` или тази от `C`. Това се нарича проблема на диаманта (diamond problem).

## Diamond problem

За да имаме еднозначност, трябва частта наследена от `A`, да е еднозначна, т.е. в класа `D` тя да се наследи само един път. Това постигаме с това, че при `B` и `C` наследяваме `A` "виртуално". Синтаксиса се следният:
```c++
    class C : virtual public A {
        // ...
    };

    class B : virtual public A {
        // ...
    }
```

Така вече имаме единствено `A`, но извикването на конструктора на `A` вече трябва да го направим експлицитно в класа `D`, не да очакваме, че това ще стане през класа `B` или `C`. 

```c++
    D(int _varA, int _varB, int _varC, int _varD) : A(_varA), B(_varA, _varB), C(_varA, _varC), varD(_varD) {}
```

Вече можем да достъпваме членовете от `A` в `D` без да имаме проблем с нееднозначността.

Целият код изглежда така:
```c++
    class A
    {
    protected:
        int varA;

    public:

        A(int _varA = 0) : varA(_varA) {}

        void print()
        {
            std::cout << "class A: varA - " << varA;
        }

    };

    class B : virtual public A
    {
        int varB;

    public:

        B(int _varA, int _varB) : A(_varA), varB(_varB) {}

        void print()
        {
            A::print();
            std::cout << "class B: varB - " << varB;
        }

    };

    class C : virtual public A
    {
        int varC;

    public:

        C(int _varA, int _varC) : A(_varA), varC(_varC) {}

        void print()
        {
            A::print();
            std::cout << "class C: varC - " << varC;
        }

    };

    class D : public B, public C
    {
        int varD;

    public:

        D(int _varA, int _varB, int _varC, int _varD) : A(_varA), B(_varA, _varB), C(_varA, _varC), varD(_varD) {}

        void print()
        {
            B::print();
            std::cout << '\n';
            C::print();
            std::cout << '\n';
            std::cout << "class D: varD - " << varD;
        }

    };

```