#include <iostream>
using namespace std;

class Engineer
{
public:
    string specialization;

    void work()
    {
        cout << "Specialization: " << specialization << endl;
    }

    Engineer()
    {
        cout << "Hello Engineer!" << endl;
    }
};

class Youtuber
{
public:
    int subscribers;

    void contentcreator()
    {
        cout << "Subscribers: " << subscribers << endl;
    }

    Youtuber()
    {
        cout << "Hello Youtuber!" << endl;
    }
};

class Teacher : public Engineer, public Youtuber
{
public:
    string name;

    Teacher()
    {
        cout << "Hello Teacher!" << endl;
    }

    Teacher(string specialization, int subscribers, string name)
    {
        this->specialization = specialization;
        this->subscribers = subscribers;
        this->name = name;
    }

    void show()
    {
        cout << "Name: " << name << endl;
        work();
        contentcreator();
    }
};

int main()
{
    Teacher A1;

    // Teacher A1("CSE", 100000, "Rohan");
    // A1.show();
    return 0;
}