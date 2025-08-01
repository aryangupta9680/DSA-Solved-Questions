#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }

    return n * fact(n - 1);
}

int sum(int n)
{
    // Base Case
    if (n == 1)
    {
        return 1;
    }

    return n + sum(n - 1);
}

int power(int num, int n)
{
    if (n == 0)
    {
        return 1;
    }

    return num * power(num, n - 1);
}

int squaresum(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * n + squaresum(n - 1);
}

int main()
{
    // factorial of a number n
    // int n;
    // cout << "Enter number: ";
    // cin >> n;
    // if (n < 0)
    // {
    //     cout << "Factorial is not possible";
    //     return 0;
    // }
    // cout << fact(n);

    // sum of first n natural number
    // int n = 6;
    // cout << sum(n);

    // power of a number
    // int num;
    // cout << "Enter num: ";
    // cin >> num;
    // int n;
    // cout << "Enter n: ";
    // cin >> n;
    // cout << power(num, n);

    // sum of square of n natural number
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << squaresum(n);

    return 0;
}