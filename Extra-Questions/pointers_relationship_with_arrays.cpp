#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    // Print the address of first element or index = 0
    // cout << arr << endl;
    // cout << arr+0 << endl;
    // cout << &arr[0] << endl;
    // cout << ptr << endl;

    // Print the address of second element or index = 1
    // cout << arr+1 << endl;
    // cout << &arr[1] << endl;

    // Print the value of index = 0
    // cout << arr[0] << endl;
    // cout << *arr << endl;
    // cout << *(arr + 0) << endl;
    // cout << *ptr << endl;

    // Print all the addresses
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr+i << endl;
    // }

    // Print all the values
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << *(arr+i) << endl;
    // }

    // Print all the addresses using pointers
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << ptr+i << endl;
    // }

    // Print all the values using pointers
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << ptr[i] << endl;
    // }

    // Arithmetic operations (ptr++, ptr--, ptr = ptr+1)
    // Print all the values
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << *ptr << endl;
    //     ptr++;
    // }

    // Addition
    ptr = ptr + 3;
    cout << *ptr << endl;

    // Subtraction
    ptr = ptr - 2;
    cout << *ptr << endl;

    // in array
    // arr = arr + 3; // Not allowed

    return 0;
}