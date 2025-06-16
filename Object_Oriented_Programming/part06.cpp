#include <iostream>
using namespace std;

class Customer
{
    string name;
    int *data;

public:
    Customer()
    {
        name = "Aryan";
        data = new int;
        *data = 10;
        cout << "Constructor is called" << endl;
    }

    // Destructor
    ~Customer()
    {
        delete data;
        cout << "Destructor is called" << endl;
    }
};

int main(){
    Customer A1;
    return 0;
}