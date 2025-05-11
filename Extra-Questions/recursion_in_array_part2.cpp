#include <iostream>
using namespace std;

// first method
// int sum(int arr[], int index)
// {
//     return arr[index];
// }

// second method
int sum(int arr[], int index, int n)
{
    if (index == n)
    {
        return 0;
    }

    return arr[index] + sum(arr, index + 1, n);
}

int main()
{
    // find sum of all elements in an array

    int arr[] = {3, 4, 1, 2, 8};

    // first method
    // int total = 0;
    // for (int i = 0; i < 5; i++)
    // {
    //     total += sum(arr, i);
    // }
    // cout << total << endl;

    // second method
    cout << sum(arr, 0, 5);

    return 0;
}