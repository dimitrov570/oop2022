#pragma once
#include <string>
#include "DateTime.hpp"
#include "Label.hpp"
using namespace std;

class Task
{
private:
    size_t id;
    string name;
    string description;
    DateTime due_date;
    const Label* label; 
    uint8_t weight;
public:
    Task();
    Task(size_t, string, string, DateTime, const Label*, uint8_t);

    size_t getId() const;
    string getName() const;
    string getDescription() const;
    DateTime getDueDate() const;
    Label getLabel() const;
    uint8_t getWeight() const;

    void setId(size_t);
    void setName(const string&);
    void setDescription(const string&);
    void setDueDate(const DateTime&);
    void setLabel(const Label*);
    void setWeight(uint8_t);

    bool operator<(const Task&);

    friend istream& operator>>(istream&, Task&);
    friend ostream& operator<<(ostream&, const Task&);
};