#pragma once
#include <cstdint>
#include <iostream>
using namespace std;

class Date
{
public:
    int year;
    uint8_t day;
    uint8_t month;

    Date();
    Date(uint8_t, uint8_t, int);

    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);
};