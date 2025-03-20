#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key)
{
    int mid, start = 0, end = n - 1, ans = -1;

    while (start <= end)
    {
        // find mid
        mid = start + (end - start) / 2;

        // arr[mid]==key
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }

        // arr[mid]<key
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }

        // arr[mid]>key
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int arr[1000];
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter " << n << " elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    cout << BinarySearch(arr, n, key);

    return 0;
}