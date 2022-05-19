#include "TaskManager.hpp"
#include <ctime>
#include <fstream>
#include <stdexcept>

#define GREEN   "\033[32m"      /* Green */
#define RED     "\033[31m"      /* Red */
#define RESET   "\033[0m"

TaskManager::TaskManager()
{
    id_counter = 0;
    labels.push_back(Label("Done"));
    labels.push_back(Label("In progress"));
    labels.push_back(Label("Open"));
}

void TaskManager::saveDataToFile(const char* str) const
{
    ofstream file(str, ios::out | ios::binary | ios::trunc);

    // write id_counter
    file.write((const char*)&id_counter, sizeof(id_counter));

    // write labels count
    int length = labels.size();
    file.write((const char*)&length, sizeof(length));
    
    // write labels
    for (int i = 0; i < labels.size(); i++)
    {
        length = labels[i].name.size();
        file.write((const char*)&length, sizeof(length));
        file.write(labels[i].name.c_str(), length);
    }
    
    // write tasks count
    length = tasks.size();
    file.write((const char*)&length, sizeof(length));

    // write tasks
    for (int i = 0; i < tasks.size(); i++)
    {
        // write task id
        size_t id = tasks[i].getId();
        file.write((const char*)&id, sizeof(id));
    
        // write task name
        length = tasks[i].getName().size();
        file.write((const char*)&length, sizeof(length));
        file.write(tasks[i].getName().c_str(), length);
        
        // write description
        length = tasks[i].getDescription().size();
        file.write((const char*)&length, sizeof(length));
        file.write(tasks[i].getDescription().c_str(), length);
        
        // write due date
        Date date = tasks[i].getDueDate().getDate();
        Time time = tasks[i].getDueDate().getTime();
        file.write((const char*)&date.day, sizeof(date.day));
        file.write((const char*)&date.month, sizeof(date.month));
        file.write((const char*)&date.year, sizeof(date.year));
        file.write((const char*)&time.h, sizeof(time.h));
        file.write((const char*)&time.m, sizeof(time.m));
        file.write((const char*)&time.s, sizeof(time.s));

        // write label
        length = tasks[i].getLabel().name.size();
        file.write((const char*)&length, sizeof(length));
        file.write(tasks[i].getLabel().name.c_str(), length);
        
        // write weight
        uint8_t weight = tasks[i].getWeight();
        file.write((const char*)&weight, sizeof(weight));
    }
    
    file.close();
}
void TaskManager::loadDataFromFile(const char* str)
{
    ifstream file(str, ios::out | ios::binary);
    
    if(!file.is_open()) return;

    // read id_counter
    file.read((char*)&id_counter, sizeof(id_counter));
    
    // read labels count
    int length;
    file.read((char*)&length, sizeof(length));
    
    // read labels
    for (int i = 0; i < length; i++)
    {
        string label_name;
        int label_len;
        file.read((char*)&label_len, sizeof(label_len));
        
        char* temp = new char[label_len + 1];
        file.read(temp, label_len);
        temp[label_len] = '\0';
        label_name = temp;
        delete[] temp;
        
        if(findLabelByName(label_name) != -1) continue;

        labels.push_back(Label(label_name));
    }


    // read tasks count
    file.read((char*)&length, sizeof(length));
    
    // read tasks
    for (int i = 0; i < length; i++)
    {
        tasks.push_back(Task());

        // read task's id
        size_t id;
        file.read((char*)&id, sizeof(id));
        tasks[i].setId(id);

        // read task's name
        int name_len;
        string name;
        file.read((char*)&name_len, sizeof(name_len));
        
        char* temp = new char[name_len + 1];
        file.read(temp, name_len);
        temp[name_len] = '\0';
        name = temp;
        delete[] temp;

        
        tasks[i].setName(name);

        // read task's description
        int description_len;
        string description;
        file.read((char*)&description_len, sizeof(description_len));
        
        temp = new char[description_len + 1];
        file.read(temp, description_len);
        temp[description_len] = '\0';
        description = temp;
        delete[] temp;
        
        tasks[i].setDescription(description);

        // read task's due date
        Date date(0, 0, 0);
        Time time(0, 0, 0);
        file.read((char*)&date.day, sizeof(date.day));
        file.read((char*)&date.month, sizeof(date.month));
        file.read((char*)&date.year, sizeof(date.year));
        file.read((char*)&time.h, sizeof(time.h));
        file.read((char*)&time.m, sizeof(time.m));
        file.read((char*)&time.s, sizeof(time.s));

        tasks[i].setDueDate(DateTime(date, time));

        // read task's label
        int label_len;
        string label_name;
        file.read((char*)&label_len, sizeof(label_len));
        
        temp = new char[label_len + 1];
        file.read(temp, label_len);
        temp[label_len] = '\0';
        label_name = temp;
        delete[] temp;

        // check if such label exists
        for (int j = 0; j < labels.size(); j++)
        {
            if(!label_name.compare(labels[j].name))
            {
                tasks[i].setLabel(&labels[j]); 
            }
        }

        // read weight
        uint8_t weight;
        file.read((char*)&weight, sizeof(weight));
        tasks[i].setWeight(weight);
    }

    file.close(); 
}

Task TaskManager::getTaskById(size_t id) const
{
    return tasks[id];
}
Label* TaskManager::getLabelByIdx(int label_idx)
{
    Label* label = &labels[label_idx];
    return label;
}

void TaskManager::changeName(size_t id, const string& name)
{
    if(id < 0 || id > id_counter) throw logic_error("Bad ID");
    tasks[id].setName(name);
}
void TaskManager::changeDescription(size_t id, const string& description)
{
    if(id < 0 || id > id_counter) throw logic_error("Bad ID");
    tasks[id].setDescription(description);
}
void TaskManager::changeDueDate(size_t id, const DateTime& due_date)
{
    if(id < 0 || id > id_counter) throw logic_error("Bad ID");
    tasks[id].setDueDate(due_date);
}
void TaskManager::changeLabel(size_t id, const Label* label)
{
    if(id < 0 || id > id_counter) throw logic_error("Bad ID");
    tasks[id].setLabel(label);
}
void TaskManager::changeWeight(size_t id, uint8_t weight)
{
    if(id < 0 || id > id_counter) throw logic_error("Bad ID");
    tasks[id].setWeight(weight);
}

void TaskManager::printLabels()
{
    for (int i = 0; i < labels.size(); i++)
    {
        if(i != 0) cout << " | ";
        cout << labels[i].name;
    }
    cout << endl;
}
void TaskManager::printTasks()
{
    time_t t = time(0);
    tm* now = localtime(&t);
    
    Date currentDate((uint8_t)now->tm_mday, (uint8_t)(now->tm_mon + 1), now->tm_year + 1900);
    Time currentTime((uint8_t)now->tm_hour, (uint8_t)now->tm_min, (uint8_t)now->tm_sec);

    DateTime currentDateTime(currentDate, currentTime);
    
    cout << endl;
    for (int i = 0; i < tasks.size(); i++)
    {
        cout << "id: " << tasks[i].getId() << endl;
        cout << "name: " << tasks[i].getName() << endl;
        cout << "description: " << endl;
        cout << tasks[i].getDescription() << endl;
        cout << "due to: ";
        
        if(tasks[i].getDueDate() < currentDateTime && (tasks[i].getLabel().name.compare("Done"))) 
        {
            cout << RED;
        }
        else cout << GREEN;
        
        cout << tasks[i].getDueDate() << RESET << endl;
        cout << "label: " << tasks[i].getLabel().name << endl;
        cout << "weight: " << (unsigned int)(tasks[i].getWeight()) << endl;
        cout << endl;
    } 
}
void TaskManager::addNewTask()
{
    string name, description, label;
    
    int weight, day, month, year, hour, minute, second;
    
    cout << "Insert name: ";
    getline(cin, name);
    cout << "Insert description: " << endl;
    getline(cin, description);
    cout << "Insert deadline: " << endl;
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
    cout << "Insert label: ";
    cin.ignore();
    getline(cin, label);
    
    int label_idx = findLabelByName(label);
    if(label_idx < 0 ) throw underflow_error("No label found");
    
    cout << "Insert weight: ";
    cin >> weight;
    if(weight < 1 || weight > 10) throw logic_error("Invalid weight");

    Task new_task;
    new_task.setId(id_counter);
    new_task.setName(name);
    new_task.setDescription(description);

    Date new_date((uint8_t)day, (uint8_t)month, year);
    Time new_time((uint8_t)hour, (uint8_t)minute, (uint8_t)second);
    DateTime new_dateTime(new_date, new_time);
    
    new_task.setDueDate(new_dateTime);
    new_task.setLabel(getLabelByIdx(label_idx));
    new_task.setWeight(weight);

    tasks.push_back(new_task);
    ++id_counter;
}
void TaskManager::addNewLabel()
{
    string name;
    
    cout << "Insert label: ";
    getline(cin, name);

    int label_idx = findLabelByName(name);

    if(label_idx != -1) throw logic_error("This label already exists");

    labels.push_back(Label(name));
}
void TaskManager::sort()
{
    for (int i = 0; i < tasks.size() - 1; i++)
    {
        for (int j = 0; j < tasks.size() - i - 1; j++)
        {
            if(tasks[j].getWeight() > tasks[j + 1].getWeight())
            {
                swap(tasks[j], tasks[j + 1]);
            }
        } 
    }
    
}
void TaskManager::removeLabel()
{
    string label;
    cout << "Insert label: ";
    getline(cin, label);

    int label_idx = findLabelByName(label);
    if(label_idx < 0) throw underflow_error("Index is out of range");
    
    if(!labels[label_idx].name.compare("Done") || 
       !labels[label_idx].name.compare("Open") ||
       !labels[label_idx].name.compare("In progress"))
    {
        throw logic_error("You cannot erase built-in labels");
    }
    
    for (size_t i = 0; i < tasks.size(); i++)
    {
        if(!tasks[i].getLabel().name.compare(label))
        {
            changeLabel(i, &labels[findLabelByName("Open")]);
        }
    }

    labels.erase(labels.begin() + label_idx);
}

int TaskManager::findLabelByName(const string& name) const
{
    for (int i = 0; i < labels.size(); i++)
    {
        if(!labels[i].name.compare(name))
        {
            return i;
        }
    }

    return -1;
}

istream& operator>>(istream& is, TaskManager& tm)
{
    for (int i = 0; i < tm.tasks.size(); i++)
    {
        is >> tm.tasks[i];
    }
    
    return is;
}
ostream& operator<<(ostream& os, const TaskManager& tm)
{
    for (int i = 0; i < tm.tasks.size(); i++)
    {
        os << tm.tasks[i];
    }

    return os;
}