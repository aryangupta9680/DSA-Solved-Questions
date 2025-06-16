#include <iostream>
using namespace std;

class Customer
{
    string name;
    int account_num;
    int balance;
    int *roi;

public:
    // Default Constructor
    Customer()
    {
        cout << "Constructor is called" << endl;
        name = "Aryan";
        account_num = 234;
        balance = 100;
        roi = new int[100];
    }

    // Parameterized Constructor
    // Customer(string a, int b, int c)
    // {
    //     name = a;
    //     account_num = b;
    //     balance = c;
    // }

    // this pointer
    // Customer(string name, int account_num, int balance)
    // {
    //     this->name = name;
    //     this->account_num = account_num;
    //     this->balance = balance;
    // }

    // Constructor Overloading
    Customer(string a, int b)
    {
        name = a;
        account_num = b;
        balance = 50;
    }

    // Inline Constructor
    inline Customer(string a, int b, int c) : name(a), account_num(b), balance(c)
    {
    }

    // Copy Constructor
    Customer(Customer &B)
    {
        name = B.name;
        account_num = B.account_num;
        balance = B.balance;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << account_num << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    Customer A1;
    Customer A2("Rohan", 543, 200);
    Customer A3("Mohan", 499);
    A1.display();
    A2.display();
    A3.display();
    Customer A4(A3);
    A4.display();
    // Customer A5;
    // A5 = A3;
    // A5.display();

    return 0;
}