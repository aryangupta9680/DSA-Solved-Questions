#include <iostream>
using namespace std;

// first method
// int minelement(int arr[], int index)
// {
//     return arr[index];
// }

// second method
int minelement(int arr[], int index, int n)
{
    if (index == n - 1)
    {
        return arr[index];
    }

    return min(arr[index], minelement(arr, index + 1, n));
}

int main()
{
    // find minimum element in an array

    int arr[] = {3, 4, 1, 2, 8};

    // first method
    // int num = arr[0];
    // for (int i = 0; i < 5; i++)
    // {
    //     num = min(num, minelement(arr, i));
    // }
    // cout << num << endl;

    // second method
    cout << minelement(arr, 0, 5);

    return 0;
}