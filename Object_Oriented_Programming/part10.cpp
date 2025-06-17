// Encapsulation and Abstraction
#include <iostream>
using namespace std;

class Customer
{
    string name;
    int acc_num, balance, age;

public:
    Customer(string name, int acc_num, int balance, int age)
    {
        this->name = name;
        this->acc_num = acc_num;
        this->balance = balance;
        this->age = age;
    }

    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
        else
        {
            cout << "Invalid amount!" << endl;
        }
    }

    void withdraw(int amount)
    {
        if (amount <= balance && amount > 0)
        {
            balance -= amount;
        }
    }

    void update_age(int age)
    {
        if (age > 0 && age < 100)
        {
            this->age = age;
        }
        else
        {
            cout << "Invalid age!" << endl;
        }
    }

    void display()
    {
        cout << name << " " << acc_num << " " << balance << " " << age << endl;
    }
};

int main()
{
    Customer A1("Aryan", 67, 1000, 15);
    Customer A2("Mohan", 53, 2000, 27);
    Customer A3("Rohan", 27, 3000, 38);
    A1.update_age(19);
    A1.deposit(500);
    A1.display();
    return 0;
}