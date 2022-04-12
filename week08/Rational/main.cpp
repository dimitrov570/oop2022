#include "Rational.hpp"

int main()
{
    Rational r;
    
    std::cin >> r; // operator>>(std::cin, r);

    std::cout << r; // operator<<(std::cout, r);

    Rational q(3,4);

    r = r * q; // -> r = operator*(r, q) -> r (оператор за присвояване) (резултат от operator*(r, q))

    r *= q; // само се сменят стойностите на r => по-бързо

    Number nr(3);

    Rational r2(2, 2);

    std::cout << "\n\n" << (nr + r2).x;
    
    return 0;
}