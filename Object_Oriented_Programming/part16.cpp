#include <iostream>
using namespace std;

class Human
{
protected:
    string name;
    int age;

public:
    void work()
    {
        cout << "I am working" << endl;
    }

    Human()
    {
        cout << "Hello Human" << endl;
    }

    Human(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void display()
    {
        cout << name << " " << age << endl;
    }
};

class Student : public Human
{
private:
    int roll_num, fees;

public:
    Student(string name, int age, int roll_num, int fees) : Human(name, age)
    {
        this->roll_num = roll_num;
        this->fees = fees;
    }

    void display()
    {
        cout << name << " " << age << " " << roll_num << " " << fees << endl;
    }
};

class Teacher : public Human
{
private:
    int salary;

public:
    Teacher(string name, int age, int salary)
    {
        this->name = name;
        this->age = age;
        this->salary = salary;
    }

    void display()
    {
        cout << name << " " << age << " " << salary << endl;
    }
};

int main()
{
    Student A1("Mohan", 48, 38, 35000);
    A1.display();
    Teacher A2("Rohan", 19, 1000);
    A2.display();

    return 0;
}