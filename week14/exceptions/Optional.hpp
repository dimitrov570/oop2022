#pragma once

#define DIVISION_BY_ZERO 233

template <typename T>
class Optional 
{
    bool isError;
    int errorCode;
    T result;

public:
    Optional(int errorCode, bool isError = true, T result = 0) : errorCode(errorCode), isError(isError), result(result)
    {}


    bool hasError() const
    {
        return isError;
    }

    T getResult() const
    {
        return result;
    }

    int getErrorCode() const
    {
        return errorCode;
    }
};