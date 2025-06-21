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
        if (amount > 0)
        {
            balance += amount;
            cout << amount << " is credited successfully!" << endl;
        }
        else
        {
            cout << "Amount should be greater than 0" << endl;
        }
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
            cout << "Amount should be greater than 0" << endl;
        }
        else
        {
            cout << "Your balance is low" << endl;
        }
    }
};

int main()
{
    Customer C1("Mohan", 5000, 345);
    C1.deposit(100);
    C1.withdraw(6000);
    return 0;
}