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

    // Human()
    // {
    //     cout << "Hello Human" << endl;
    // }

    // ~Human()
    // {
    //     cout << "Human Destructor is called" << endl;
    // }

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
    // Student(string name, int age, int roll_num, int fees)
    // {
    //     this->name = name;
    //     this->age = age;
    //     this->roll_num = roll_num;
    //     this->fees = fees;
    // }

    Student(string name, int age, int roll_num, int fees) : Human(name, age)
    {
        this->roll_num = roll_num;
        this->fees = fees;
    }

    void display()
    {
        cout << name << " " << age << " " << roll_num << " " << fees << endl;
    }

    // Student()
    // {
    //     cout << "Hello Student" << endl;
    // }

    // ~Student()
    // {
    //     cout << "Student Destructor is called" << endl;
    // }
};

int main()
{
    Student A1("Aryan", 19, 38, 100000);
    // A1.work();

    // Student A1;

    A1.display();

    return 0;
}