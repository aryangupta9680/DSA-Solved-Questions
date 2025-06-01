#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    vector<int> temp(end - start + 1);
    int left = start, right = mid + 1, index = 0;

    while ((left <= mid) && (right <= end))
    {
        if (arr[left] <= arr[right])
        {
            temp[index] = arr[left];
            left++, index++;
        }

        else
        {
            temp[index] = arr[right];
            right++, index++;
        }
    }

    // left array is not empty yet
    while (left <= mid)
    {
        temp[index] = arr[left];
        left++, index++;
    }

    // right array is not empty yet
    while (right <= end)
    {
        temp[index] = arr[right];
        right++, index++;
    }

    index = 0;
    // put these value in arr
    while (start <= end)
    {
        arr[start] = temp[index];
        start++, index++;
    }
}

void mergesort(int arr[], int start, int end)
{
    if (start == end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    // left side
    mergesort(arr, start, mid);

    // right side
    mergesort(arr, mid + 1, end);

    // merge
    merge(arr, start, mid, end);
}

int main()
{
    int arr[] = {9, 4, 2, 7, 5, 8, 3, 3, 10, 6};
    mergesort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}