#pragma once
#include <exception>
#include <string>

class DivisionByZero : public std::exception
{
    std::string error;

public:

    DivisionByZero(const char* errorMsg) : error(errorMsg) {}

    const char* what() const throw() override
    {
        return error.c_str();
    }

    void add(const char* add)
    {
        error.append(add);
    }

};