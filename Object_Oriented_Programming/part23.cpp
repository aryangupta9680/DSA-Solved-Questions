// Exceptions Handling

#include <iostream>
using namespace std;

class Customer
{
    string name;
    int balance, account_num;

public:
    Customer(string name, int balance, int account_num)
    {
        this->name = name;
        this->balance = balance;
        this->account_num = account_num;
    }

    // deposit
    void deposit(int amount)
    {
        if (amount <= 0)
        {
            throw "Amount should be greater than 0";
        }

        balance += amount;
        cout << amount << " is credited successfully!" << endl;
    }

    // withdraw
    void withdraw(int amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << amount << " is debited successfully!" << endl;
        }
        else if (amount < 0)
        {
            throw "Amount should be greater than 0";
        }
        else
        {
            throw "Your balance is low";
        }
    }
};

int main()
{
    Customer C1("Mohan", 5000, 345);
    try
    {
        C1.deposit(100);
        C1.withdraw(6000);
        C1.deposit(100);
    }
    catch (const char *e)
    {
        cout << "Exception occurred: " << e << endl;
    }

    return 0;
}