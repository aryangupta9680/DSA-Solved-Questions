#include <iostream>
using namespace std;

void print1(int num, int N)
{
    // Base Case
    if (N == num)
    {
        cout << num << endl;
        return;
    }

    cout << num << " ";
    print1(num + 1, N);
}

void print2(int N)
{
    // Base Case
    if (N == 1)
    {
        cout << 1 << " ";
        return;
    }

    print2(N - 1);
    cout << N << " ";
}

void printeven1(int num, int N)
{
    if (num == N)
    {
        cout << num << " ";
        return;
    }

    // if (num > N)
    // {
    //     return;
    // }

    cout << num << " ";
    printeven1(num + 2, N);
}

void printeven2(int N)
{
    if (N == 2)
    {
        cout << 2 << " ";
        return;
    }

    printeven2(N - 2);
    cout << N << " ";
}

int main()
{
    // Print number from 1 to N
    // int N;
    // cout << "Enter number: ";
    // cin >> N;
    // print1(1, N);

    // print2(N);

    cout << endl;
    // print even number from 1 to N
    cout << "Even numbers: " << endl;
    int N;
    cout << "Enter number: ";
    cin >> N;
    if (N % 2 == 1)
    {
        N--;
    }
    // printeven1(2, N);

    printeven2(N);

    return 0;
}