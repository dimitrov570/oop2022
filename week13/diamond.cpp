#include <iostream>
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


int main()
{
    D obj(1,2,3, 4);
    //obj.print();

    //((A)obj).print();



    return 0;
}