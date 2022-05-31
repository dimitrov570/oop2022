#pragma once
#include <stdexcept>
#include <string>

// std::runtime_error has constructor with string parameter
// and overriden method what()
class DivisionByZeroError: public std::runtime_error
{

public:
    DivisionByZeroError(const std::string& errorMsg) : std::runtime_error(errorMsg) {}

};