#include <iostream>
using namespace std;

bool linearsearch(int arr[], int X, int index, int n)
{
    // base condition
    if (index == n)
    {
        return false;
    }

    if (arr[index] == X)
    {
        return true;
    }

    return linearsearch(arr, X, index + 1, n);
}

int main()
{
    // Recursion in Linear Search
    int arr[] = {2, 3, 6, 7, 1, 5};
    int X = 17;
    cout << linearsearch(arr, X, 0, 6);

    return 0;
}