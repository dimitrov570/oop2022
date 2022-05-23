#include <iostream>

class A
{   
    int privateVarA;

protected:
    int protectedVarA;

public:
    int publicVarA;
    
    A()
    {
        std::cout << "A()\n";
    }

    void print()
    {
        std::cout << "privateVarA: " << privateVarA << '\n';
        std::cout << "protectedVarA: " << protectedVarA << '\n';
        std::cout << "publicVarA: " << publicVarA << '\n';
    }

    A(int x, int y, int z) : privateVarA(x), protectedVarA(y), publicVarA(z)
    {
     //   std::cout << "A(int, int, int)\n";
    }

    ~A()
    {
     //   std::cout << "~A()\n";
    }
};

class B : public A
{
    int privateVarB;
public:
    B() : A(1, 2, 3), privateVarB(0)
    {
    //  A::privateVarA; - забранен достъп
    //  A::protectedVarA; позволен достъп
    //  A::publicVarA; позволен достъп
    //  std::cout << "B()\n";
    }

    B& operator=(const B& rhs)
    {
        if (this != &rhs)
        {
            A::operator=(rhs);
            privateVarB = rhs.privateVarB;
        }
        return *this;
    }

    void print()
    {
        A::print();
        std::cout << "privateVarB: " << privateVarB << '\n';
    }


    ~B()
    {
     //   std::cout << "~B()\n";
    }
};

class C : public B
{
    int privateVarC;

public:
    C()
    {
     //   std::cout << "C()\n";
    }
    
    ~C()
    {
     //   std::cout << "~C()\n";
    }
};

template <typename T>
class D
{
public:
    T templateVar;

    D(T c) : templateVar(c)
    {

    }
};

template <>
class D<int> : public D<char>
{
public:
    int addedVar;

    D(char c, int v) : D<char>(c), addedVar(v)
    {

    }
};


int main()
{
    D<int> dObj('d', 30);

    std::cout<< dObj.templateVar << '\n';

    std::cout<< dObj.addedVar << '\n';

    return 0;
}