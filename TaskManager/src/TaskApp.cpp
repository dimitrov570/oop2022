#include <iostream>
#include "TaskManager.hpp"
#include "TaskApp.hpp"
using namespace std;

void TaskApp::run()
{
    TaskManager tm;

    tm.loadDataFromFile("Data.bin");

    string buffer;
    do
    {
        cout << "> ";
        getline(cin, buffer);
        if(!buffer.compare("create new task"))
        {
            tm.addNewTask();
            cin.ignore();
        }
        else if(!buffer.compare("view tasks"))
        {
            tm.printTasks();
        }
        else if(!buffer.compare("create new label"))
        {
            tm.addNewLabel();
        }
        else if(!buffer.compare("sort tasks"))
        {
            tm.sort();
        }
        else if(!buffer.compare("remove label"))
        {
            tm.removeLabel();
        }
        else if(!buffer.compare("view labels"))
        {
            tm.printLabels();
        }
        else if(!buffer.compare("change task name"))
        {
            size_t id;
            string name;

            cout << "Insert task's id: ";
            cin >> id;
            cout << "Insert new name: ";
            cin.ignore();
            getline(cin, name);

            tm.changeName(id, name);
        }
        else if(!buffer.compare("change task description"))
        {
            size_t id;
            string description;

            cout << "Insert task's id: ";
            cin >> id;
            cout << "Insert new description: ";
            cin.ignore();
            getline(cin, description);

            tm.changeDescription(id, description);
        }
        else if(!buffer.compare("change task due date"))
        {
            size_t id;
            int day, month, year, hour, minute, second;

            cout << "Insert task's id: ";
            cin >> id;
            cout << "Insert new due date: ";
            
            cout << "   day: ";
            cin >> day;
            cout << "   month: ";
            cin >> month;
            cout << "   year: ";
            cin >> year;
            cout << "   hour: ";
            cin >> hour;
            cout << "   minute: ";
            cin >> minute;
            cout << "   second: ";
            cin >> second;
            
            Date new_date((uint8_t)day, (uint8_t)month, year);
            Time new_time((uint8_t)hour, (uint8_t)minute, (uint8_t)second);
            DateTime new_dateTime(new_date, new_time);
                    
            tm.changeDueDate(id, new_dateTime);
        }
        else if(!buffer.compare("change task label"))
        {
            size_t id;
            string label;

            cout << "Insert task's id: ";
            cin >> id;
            cout << "Insert new label: ";
            cin.ignore();
            getline(cin, label);
            
            int label_idx = tm.findLabelByName(label);
            if(label_idx < 0) throw underflow_error("No label found");

            tm.changeLabel(id, tm.getLabelByIdx(label_idx));
        }
        else if(!buffer.compare("change task weight"))
        {
            size_t id;
            int weight;

            cout << "Insert task's id: ";
            cin >> id;
            cout << "Insert new label: ";
            cin >> weight;

            if(weight < 1 || weight > 10) throw logic_error("Invalid weight");

            tm.changeWeight(id, (uint8_t)weight);
        }
    } 
    while (buffer.compare("exit"));
    
    tm.saveDataToFile("Data.bin");
}