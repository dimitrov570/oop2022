#include <iostream>
#include "Optional.hpp"
#include <vector>
#include <exception>
#include <stdexcept>
#include "DivisionByZero.hpp"

#define BAD_INPUT 3

int error_code = 0;

Optional<double> divide(int a, int b)
{
    if(b == 0)
    {
        return Optional<double>(DIVISION_BY_ZERO, true, 0);
    }
    double result = (double)a / b;
    return Optional<double>(0, false, result);
}

void testDivide()
{
    int a = 10;
    int b = 0;

    int exitStatus;
    Optional<double> result = divide(a, b);
    if(result.hasError())
    {
        if(result.getErrorCode() == DIVISION_BY_ZERO)
        {
            std::cout << "Division by zero!\n";
        }
    }
    else 
    {
        std::cout  << "result is: " << result.getResult() << '\n';
    }
}


double divideWithThrow(int a, int b)
{
    if(b == 0)
    {
        throw DIVISION_BY_ZERO;
    }

    return (double)a / b;
}

double callDivide(int a, int b)
{
    return divideWithThrow(a, b); 
}

void testDivideWithThrow()
{
    int a = 10;
    int b = 0;

    try 
    {
        double result = callDivide(a, b);
        std::cout << "Result is: " << result << '\n';
    }
    catch(Optional<double> optional) // тук няма да се прихване
    {
        std::cout << "Caught optional\n";
    }
    catch(int error) // тук ще се прихване
    {
        if(error == DIVISION_BY_ZERO)
        {
            std::cout << "Division by zero!\n";
        }
    }
    catch(double error) // до тук няма да дойде
    {
        std::cout << "Caught double\n";
    }
}

double divideWithException(int a, int b)
{
    if (b == 0)
    {
        //throw std::runtime_error("Division by zero\n");
        throw DivisionByZero("Thrown at divideWithException(int a, int b)\n");
    }
    return (double)a / b;
}

void testDivideWithException()
{
    int a = 10;
    int b = 0;

    try
    {
        double result = divideWithException(a, b);
    }
    catch(DivisionByZero err)
    {
        /*
        err.add("Been in testDivideWithException()");
        throw err;
        */
       std::cout << "You tried to divide by zero!\n";
    }
    catch(...)
    {
        std::cout << "Unknown error!\n";
    }

}

int insertNumber(int& res)
{
    std::cout << "Insert number between 0 and 10\n";
    std::cin >> res;

    if(res < 0 || res > 10)
    {
        return BAD_INPUT;
    }

    return 0;
}

int main()
{

    // testDivide();
    // testDivideWithThrow();
    // testDivideWithException();
    return 0;
}