#include <iostream>
using namespace std;

// First Method:
// void print(int arr[], int index, int n)
// {
//     if (index == n)
//     {
//         return;
//     }

//     cout << arr[index] << " ";
//     print(arr, index + 1, n); // output: 3 4 1 2 8
// }

// void print(int arr[], int index, int n)
// {
//     if (index == n)
//     {
//         return;
//     }

//     print(arr, index + 1, n); // output: 8 2 1 4 3
//     cout << arr[index] << " ";
// }

// Second Method:
// void print(int arr[], int index, int n)
// {
//     if(index==n)
//     {
//         return;
//     }

//     cout << arr[index] << " ";
//     print(arr,index+1, n); // output: 3 4 1 2 8
// }

// void print(int arr[], int index, int n)
// {
//     if(index==n)
//     {
//         return;
//     }

//     print(arr,index+1, n); // output: 8 2 1 4 3
//     cout << arr[index] << " ";
// }

// Third Method:
// void print(int arr[], int index)
// {
//     cout << arr[index] << " ";
// }

// Fourth Method:
void print(int arr[], int index)
{
    if (index == -1)
    {
        return;
    }

    print(arr, index - 1); // output: 3 4 1 2 8
    cout << arr[index] << " ";
}

// void print(int arr[], int index)
// {
//     if(index==-1)
//     {
//         return;
//     }

//     cout << arr[index] << " ";
//     print(arr, index-1); // outputs: 8 2 1 4 3
// }

int main()
{
    int arr[] = {3, 4, 1, 2, 8};

    // First Method:
    // print(arr, 0, 5);

    // Second Method:
    // print(arr, 0, 5);

    // Third Method:
    // for (int i = 0; i < 5; i++)
    // {
    //     print(arr, i);
    // }

    // Fourth Method:
    // print(arr, 4);

    return 0;
}