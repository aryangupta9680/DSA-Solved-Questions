#include <iostream>
using namespace std;

int main()
{
    // variable ke liye heap memory allocate karani ho
    int *ptr = new int;
    // cout << ptr << endl;
    *ptr = 5; // value assign
    // cout << *ptr << endl;

    float *ptr1 = new float;
    cout << ptr1 << endl;
    *ptr1 = 78.54;
    cout << *ptr1 << endl;

    // for array
    int n;
    cout << "Enter size: ";
    cin >> n;
    int *p = new int[n];

    // values
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }

    // print the values
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << endl;
    }

    // delete keyword
    delete ptr;
    delete ptr1;
    delete[] p;

    return 0;
}