#pragma once
#include "Date.hpp"
#include "Time.hpp"
#include <iostream>
using namespace std;

class DateTime
{
private:
    Date date;
    Time time;

public:
    DateTime();
    DateTime(Date, Time);

    Date getDate() const;
    Time getTime() const;
    
    void setDate(Date);
    void setTime(Time);    
    
    void printDateTime() const;

    DateTime timeTo(const DateTime&) const;
    bool operator<(const DateTime&) const;

    friend ostream& operator<<(ostream&, const DateTime&);
    friend istream& operator>>(istream&, DateTime&);
};

