#include <iostream>
using namespace std;

class Human
{
public:
    string name;
    int age, weight;
};

class student : private Human
{
private:
    int roll_num, fees;

public:
    student(string name, int age, int weight, int roll_num, int fees)
    {
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->roll_num = roll_num;
        this->fees = fees;
    }

    void display()
    {
        cout << name << " age is " << age << " weight is " << weight << " roll no. is " << roll_num << " and fees is " << fees;
    }
};

class Teacher : public Human
{
    int salary, id;
};

int main()
{
    student A("Mohan", 19, 60, 24, 100000);
    A.display();
    Teacher B;
    B.name = "Rohan";

    return 0;
}