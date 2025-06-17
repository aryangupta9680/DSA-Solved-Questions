// Static data member
#include <iostream>
using namespace std;

class Customer
{
    string name;
    int acc_num, balance;
    // static int total_customers;

public:
    static int total_customers;

    Customer(string name, int acc_num, int balance)
    {
        this->name = name;
        this->acc_num = acc_num;
        this->balance = balance;
        total_customers++;
    }

    void display()
    {
        cout << name << " " << acc_num << " " << balance << " " << total_customers << endl;
    }

    void display_total_customers()
    {
        cout << total_customers << endl;
    }
};

int Customer::total_customers = 0;

int main()
{
    Customer A1("Aryan", 67, 1000);
    Customer A2("Mohan", 53, 2000);
    // A1.display();
    // A2.display();
    Customer A3("Rohan", 27, 3000);
    // A3.display();
    // A2.display_total_customers();
    // A3.display_total_customers();

    Customer::total_customers = 5;
    A1.display_total_customers();
    return 0;
}