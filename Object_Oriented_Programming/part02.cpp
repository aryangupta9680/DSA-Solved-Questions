#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int age, roll_num;
    string grade;

public:
    // setter and getter functions
    void setname(string s)
    {
        if (s.size() == 0)
        {
            cout << "Invalid name!" << endl;
            return;
        }
        name = s;
    }

    void setage(int a)
    {
        if (a < 0 || a > 100)
        {
            cout << "Invalid age!" << endl;
            return;
        }
        age = a;
    }

    void setroll_num(int r)
    {
        roll_num = r;
    }

    void setgrade(string g)
    {
        grade = g;
    }

    void getname()
    {
        cout << "Name: " << name << endl;
    }

    void getage()
    {
        cout << "Age: " << age << endl;
    }

    int getroll_num()
    {
        return roll_num;
    }

    string getgrade(int pin)
    {
        if (pin == 123456)
        {
            return grade;
        }

        return "Invalid pin!";
    }
};

int main()
{
    Student s1;
    s1.setname("");
    s1.setage(19);
    s1.setroll_num(2517);
    s1.setgrade("A+");
    s1.getage();
    cout << "Roll Number: " << s1.getroll_num() << endl;
    cout << s1.getgrade(123456) << endl;

    return 0;
}