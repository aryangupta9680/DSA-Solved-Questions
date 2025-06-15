#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int age, roll_num;
    string grade;
};

int main()
{
    Student s1;
    s1.name = "Aryan";
    s1.age = 19;
    s1.roll_num = 2517;
    s1.grade = "A+";
    cout << s1.name << endl;
    cout << s1.age << endl;
    cout << s1.roll_num << endl;
    cout << s1.grade << endl;

    Student s2;
    s2.name = "Rohan";
    s2.age = 18;
    s2.roll_num = 2157;
    s2.grade = "B";
    cout << s2.name << endl;
    cout << s2.age << endl;
    cout << s2.roll_num << endl;
    cout << s2.grade << endl;

    return 0;
}