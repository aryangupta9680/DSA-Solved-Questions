#include <iostream>
using namespace std;

class Student
{
public:
    void print()
    {
        cout << "Student" << endl;
    }
};

class Male
{
public:
    void Maleprint()
    {
        cout << "Male" << endl;
    }
};

class Female
{
public:
    void Femaleprint()
    {
        cout << "Female" << endl;
    }
};

class Boy : public Student, public Male
{
public:
    void Boyprint()
    {
        cout << "Boy" << endl;
    }
};

class Girl : public Student, public Female
{
public:
    void Girlprint()
    {
        cout << "Girl" << endl;
    }
};

int main()
{
    Girl G1;
    G1.Girlprint();
    G1.print();

    Boy B1;
    B1.Boyprint();
    B1.print();
    B1.Maleprint();
    return 0;
}