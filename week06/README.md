### Конструктор за копиране
Използва се за създаване на обект като се използва за образец някой друг обект.
```c++
    MyClass::MyClass(MyClass const& rhs): var(rhs.var) {}
    Rational::Rational(Rational const& rhs): numerator(rhs.numerator), denominator(rhs.denominator) {}
```

Извикване на конструктор за копиране:
```c++
    MyClass a;
    MyClass b = a;
    MyClass c(a);
```

Както и при конструктора по подразбиране, ако не е написан конструктор за копиране създава се автоматично такъв, който копира член-данните.

Конструктор за копиране се извиква и при подаване на обекти като параметри на функция и при връщане на обекти от функция.

### Конструктор за копиране и динамична памет

Разгледайте следния клас:
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

За така дефиниран клас какво ще се изведе при изпълнението на следния код:

```c++
    Person a;
    Person b = a;

    std::cout << a.getName() << '\n';

    b.setName("NewName");
    
    std::cout << a.getName() << '\n';
    std::cout << b.getName() << '\n';
```

Поради тази причина трябва да се напише конструктор за копиране, който няма просто да копира член-данните. 
Пример:
```c++
    Person(const Person& copyFrom)
    {
        int length = strlen(copyFrom.getName());
        name = new char[length + 1]; //+ 1 for '\0'
        strcpy(name, copyFrom.getName());
    }
```

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