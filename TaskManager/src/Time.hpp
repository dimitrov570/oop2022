#pragma once
#include <cstdint>
#include <iostream>
using namespace std;

class Time
{
public:
    uint8_t h;
    uint8_t m;
    uint8_t s;

    Time();
    Time(uint8_t, uint8_t, uint8_t);

    friend ostream& operator<<(ostream&, const Time&);
    friend istream& operator>>(istream&, Time&);
};