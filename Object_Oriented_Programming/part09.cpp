// Static Member functions
#include <iostream>
using namespace std;

class Customer
{
    string name;
    int acc_num, balance;
    static int total_customers;
    static int total_balance;

public:
    Customer(string name, int acc_num, int balance)
    {
        this->name = name;
        this->acc_num = acc_num;
        this->balance = balance;
        total_customers++;
        total_balance += balance;
    }

    // Static Member functions
    static void access_static()
    {
        cout << "Total number of customers: " << total_customers << endl;
        cout << "Total balance: " << total_balance << endl;
    }

    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            total_balance += amount;
        }
    }

    void withdraw(int amount)
    {
        if (amount <= balance && amount > 0)
        {
            balance -= amount;
            total_balance -= amount;
        }
    }

    void display_total_customers()
    {
        cout << total_customers << endl;
    }
};

int Customer::total_customers = 0;
int Customer::total_balance = 0;

int main()
{
    Customer A1("Aryan", 67, 1000);
    Customer A2("Mohan", 53, 2000);
    Customer A3("Rohan", 27, 3000);
    A1.deposit(800);
    A2.withdraw(600);
    Customer::access_static();
    return 0;
}