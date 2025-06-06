#include <iostream>
using namespace std;

int subset(int arr[], int index, int sum, int n)
{
    // base condition
    if (index == n)
    {
        return sum == 0;
    }

    return subset(arr, index + 1, sum, n) + subset(arr, index + 1, sum - arr[index], n);
}

int main()
{
    int arr[] = {2, 5, 6, 1};
    int sum = 8;
    cout << subset(arr, 0, sum, 4);

    return 0;
}