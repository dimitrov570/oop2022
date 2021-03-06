# Наследяване

Наследяването позволява да се създават нови класове, които да имат член-данни и методи на някой друг клас автоматично. 

Наследяването и композицията на класове са различни неща.

Класът, чиято имплементация използваме за създаване на нов клас се нарича родителски (базов) клас, а новосъздаденият клас се нарича наследник (подклас). 


Синтаксис
```c++
class B : A
{
    //...
};
```
Означава, че класът B наследява класа A. Класът B вече съдържа член-данните от класа А.

Съществуват три модификатора за достъп до компоненти на клас:
- private
- protected
- public

### private компоненти
Private компоненти на клас могат да се достъпват само в класа, в който са дефинирани и от приятелите на този клас.

### protected компоненти
Protected компоненти на клас могат да се достъпват както в класа, в който са дефинирани и неговите приятели, така и в класовете наследници и техните приятели.

### public компоненти
Public компонентите могат да се достъпват от всякъде.

Съществува възможност да се укаже с каква видимост да се наследяват член-данните и методите на базовия клас. Трябва да се добави желаният модификатор за достъп преди името на класа, който ще се наследява. Ако е изоставен, по подразбиране е `private`. Пример:
```c++
class B : protected A
{
    //...
};
```
Това означава (в примера), че всички компоненти, които са `protected` и `public` в базовия клас (A) стават `protected` в класа наследник (B), а до `private` компонентите на базовия клас няма достъп класа наследник. 
Повече информация за това има в следната таблица, която показва с какъв модификатор за достъп са наследените компоненти в класа наследник в зависимост от това какъв е модификатора за достъп до тях в базовия клас и какъв е видът на наследяването (`private`, `protected` или `public`):

|  **Вид наследяване**\\**Достъп в базовия клас** | *__public__* | *__protected__* | *__private__* | 
| -- | -- | -- | -- | 
| *__public__* | public | protected | забранен достъп |
| *__protected__* | protected | protected | забранен достъп |
| *__private__* | private | private | забранен достъп |

Приятелството не се наследява, т.е. приятелите на базовия клас не са приятели на класа наследник, освен ако не са експлицитно декларирани като приятели и в класа наследник.

## Наследяване и голямата четворка

### Конструктори
Конструктора на класа наследник ще извика конструктора по подразбиране на базовия клас, преди инициализацията на собствените член-данни. Ако искаме да извикаме някой друг конструктор на базовия клас, трябва да го направим в инициализиращия списък на конструктора на класа наследник.
```c++
    B(/* arguments */) : A(/* arguments for A */)
    {
        //...
    }
```

### Конструктор за копиране
Ако не е дефиниран конструктор за копиране в класа наследник, тогава ще се генерира такъв, който ще извика конструктора за копиране на базовия клас. Ако ще дефинираме конструктор за копиране в класа наследник, тогава трябва да се извика конструктора за копиране на базовия клас в инициализиращия списък, иначе ще се извика конструктора по подразбиране на базовия клас.

### Оператор за присвояване (operator=)
Ако не е дефиниран `operator=` в класа наследник, тогава ще се генерира такъв, който ще извика `operator=` на базовия клас. Ако ще дефинираме `operator=` на класа наследник, тогава трябва да се извика оператора на базовия клас по следния начин:

```c++
class B : A
{
    // ...
    B& operator=(const B& rhs)
    {
        A::operator=(rhs);
        // ...
    }
    // ...
};
```

#### Конструктора за копиране и оператора за присвояване в клас наследник трябва да се дефинират само ако в класа наследник се работи с ресурси, които трябва да се копират по специфичен начин (като динамична памет). Ако няма такива ресурси или всичките се обработват в базовия клас, тогава автоматично генерираните конструктор за копиране и оператор за присвояване ще извикат съответните от базовия клас, които да се справят с ресурсите и няма нужда от тяхното експлицитно дефиниране в класа наследник.

### Деструктори
Деструктора на класа наследник автоматично ще извика деструктора на базовия клас.

## overriding

В класа наследник е възможно да се дефинират член-данни или методи със същото име както и в базовия клас. Това се нарича `overriding`. Каква е разликата между `overloading` и `overriding`? В такъв случай, ако искаме да достъпим компонентите на базовия клас, трябва да им се указва пълното име, т.е. ако базовия клас е с име `A` и искаме да извикаме негов метод `foo()` от класа наследник, но метода `foo()` е дефиниран и в класа наследник, тогава за да го достъпим трябва да пишем `A::foo()`. 

## Наследяване и шаблони на класове (template)
За следващите примери, приемете че `A` и `B` са шаблони на класове, а `C` е обикновен клас. Тогава съществуват следните възможности
- обикновен клас наследява клас създаден от шаблон на клас
```c++
    class C : public A<int>;
```
- шаблон на клас наследява обикновен клас
```c++
    template <typename T>
    class A : C;
```
- шаблон на клас наследява клас създаден от шаблон на клас
```c++
    template <typename T>
    class B : A<int>;
```
- шаблон на клас наследява шаблон на клас
```c++
    template <typename T>
    class B : A<T>;
```

## Преобразуване на типове (cast-ване)
Възможно е имплицитно (неявно) преобразуване от клас наследник към базов клас.

Пример (`B` наследява `A`):
```c++
    B obj;
    A copyObj = obj;
```
Обаче, чрез `copyObj` могат да се достъпват само компонентите от класа `A`.