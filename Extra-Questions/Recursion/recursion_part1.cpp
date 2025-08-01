#include <iostream>
using namespace std;

void fun0(int n)
{
    cout << "Happy Birthday!!!";
    cout << endl;
}

void fun1(int n)
{
    cout << n << " days are left for birthday.";
    cout << endl;
    fun0(n - 1);
}

void fun2(int n)
{
    cout << n << " days are left for birthday.";
    cout << endl;
    fun1(n - 1);
}

void fun3(int n)
{
    cout << n << " days are left for birthday.";
    cout << endl;
    fun2(n - 1);
}

void fun(int n)
{
    // base case
    if (n == 0)
    {
        cout << "Happy Birthday!!!" << endl;
        return;
    }

    cout << n << " days left for birthday." << endl;
    fun(n - 1);
}

int main()
{
    // Iterative approach
    // int n;
    // cout << "Enter number: ";
    // cin >> n;

    // for (int i = n; i > 0; i--)
    // {
    //     cout << i << " days left for birthday." << endl;
    // }

    // cout << "Happy Birthday!!!" << endl;

    // Function approach
    // fun3(3);

    // Recursion approach
    int n;
    cout << "Enter number: ";
    cin >> n;
    fun(n);

    return 0;
}