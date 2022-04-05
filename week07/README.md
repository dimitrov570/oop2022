# Голяма четворка
- конструктор по подразбиране
- конструктор за копиране
- оператор за присвояване
- деструктор

# Enum
- enum
```c++
#include <iostream>

enum Gender /*: uint8_t или int или някоя друга целочислена променлива */
{
    Male = 6,
    Female = 4000
};

int main()
{
    Gender gender = Female; //стойностите са видими в областта, където е дефиниран enum-а
    
    int a = gender; //възможно е имплицитно cast-ване

    std::cout << a << '\n';

    switch (gender)
    {
    case Gender::Male:
        std::cout << "Male";
        break;
    case Gender::Female:
        std::cout << "Female";
        break;
    default:
        break;
    }

    return 0;
}


```
- enum class  

```c++
#include <iostream>

enum class Gender /*: uint8_t или int или някоя друга целочислена променлива */
{
    Male = 6,
    Female = 4000
};

int main()

    /*
    стойностите НЕ са видими в областта, където е дефиниран enum-а
    налага се да се укаже областта (името на enum-а)
    */
    Gender gender = Gender::Female; 
    
    int a = (int)gender; //НЕ е възможно е имплицитно cast-ване

    std::cout << a << '\n';

    switch (gender)
    {
    case Gender::Male:
        std::cout << "Male";
        break;
    case Gender::Female:
        std::cout << "Female";
        break;
    default:
        break;
    }

    return 0;
}


```

Може да се изостави присвояването на целочислени стойности. Тогава автоматично ще получат нарастващи стойности, започвайки от 0.
```c++
enum class Gender /*: uint8_t или int или някоя друга целочислена променлива */
{
    Male, //ще има стойност 0
    Female //ще има стойност 1
};

```

## Задачa
Имплементирайте клас `Student`, който да пази следните данни за студенти:
- име като динамичен масив от тип `char`
- факултетен номер
- години
- най-добър приятел (друг Student)  
- специалност (enum (SI, KN, I, M))

Дефинирайте, които смятате за необходими методи от голямата четворка и селектори и мутатори.  