#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    // print the address of a
    // cout << &a << endl;
    int *ptr = &a;
    cout << ptr << endl; // address of a
    // cout << "Size of ptr is: " << sizeof(ptr) << endl;
    // cout << &ptr << endl;
    cout << *ptr << endl; // value inside a

    int b = 20;
    ptr = &b;
    cout << ptr << endl;
    cout << *ptr << endl;
    b = 30;
    cout << *ptr << endl;

    // float m = 2.5;
    // float *ptr1 = &m;
    // cout << ptr1 << endl;
    // cout << "Size of ptr is: " << sizeof(ptr1) << endl;

    return 0;
}