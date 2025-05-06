#include <iostream>
using namespace std;

void print(int n)
{
    // Base Case
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    cout << n << " ";
    print(n - 1);
}

void even(int n)
{
    if (n == 2)
    {
        cout << 2 << endl;
        return;
    }

    cout << n << " ";
    even(n - 2);
}

int main()
{
    // Print n to 1
    // Iterative approach
    // int n = 5;
    // for (int i = n; i > 0; i--)
    // {
    //     cout << i << " ";
    // }

    // using recursion
    // int n = 5;
    // print(n);

    // Print even number from n to 1
    int n = 10;
    even(n);

    return 0;
}