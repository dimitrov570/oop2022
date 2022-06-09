#include "Time.hpp"
#include <iostream>
using namespace std;

Time::Time()
{
    h = (uint8_t)0;
    m = (uint8_t)0;
    s = (uint8_t)0;
}
Time::Time(uint8_t hour, uint8_t minute, uint8_t second)
{
    h = hour;
    m = minute;
    s = second;
}

ostream& operator<<(ostream& os, const Time& time)
{
    if(time.h / 10 != 0) os << (unsigned int)time.h << ":";
    else os << "0" << (unsigned int)time.h << ":";

    if(time.m / 10 != 0) os << (unsigned int)time.m << ":";
    else os << "0" << (unsigned int)time.m << ":";

    if(time.s / 10 != 0) os << (unsigned int)time.s;
    else os << "0" << (unsigned int)time.s;
    
    return os;
}
istream& operator>>(istream& is, Time& time)
{
    int hour;
    int minute;
    int second;
    
    is >> hour; 
    is >> minute;
    is >> second;

    time.h = (uint8_t)hour;
    time.m = (uint8_t)minute;
    time.s = (uint8_t)second;
    return is; 
}