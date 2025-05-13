#include <iostream>
using namespace std;

bool BinarySearch(int arr[], int start, int end, int X)
{
    if (start > end)
    {
        return false;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == X)
    {
        return true;
    }

    else if (arr[mid] > X)
    {
        return BinarySearch(arr, start, mid - 1, X);
    }

    else
    {
        return BinarySearch(arr, mid + 1, end, X);
    }
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12};
    int X = 10;
    cout << BinarySearch(arr, 0, 5, X) << endl;

    return 0;
}