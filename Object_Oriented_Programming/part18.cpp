#include <iostream>
using namespace std;

class Human
{
public:
    string name;

    void display()
    {
        cout << "Name: " << name << endl;
    }
};

class Engineer : public virtual Human
{
public:
    string specialization;

    void work()
    {
        cout << "Specialization: " << specialization << endl;
    }
};

class Youtuber : public virtual Human
{
public:
    int subscribers;

    void contentcreator()
    {
        cout << "Subscribers: " << subscribers << endl;
    }
};

class Teacher : public Engineer, public Youtuber
{
public:
    int salary;

    Teacher(string specialization, int subscribers, string name, int salary)
    {
        this->specialization = specialization;
        this->subscribers = subscribers;
        this->name = name;
        this->salary = salary;
    }
};

int main()
{
    Teacher A1("CSE", 3000, "Rohan", 60000);
    A1.display();
    return 0;
}