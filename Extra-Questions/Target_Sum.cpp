#include <iostream>
using namespace std;

bool find(int arr[], int index, int n, int target)
{
    // base condition
    if (target == 0)
    {
        return 1;
    }
    if (index == n || target < 0)
    {
        return 0;
    }

    return find(arr, index + 1, n, target) || find(arr, index + 1, n, target - arr[index]);
}

int main()
{
    int arr[] = {2, 3, 6, 8, 9};
    int target = 20;
    cout << find(arr, 0, 5, target);
    return 0;
}