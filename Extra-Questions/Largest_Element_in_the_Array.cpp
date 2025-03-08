#include <iostream>
#include <limits.h> // For INT_MIN
using namespace std;

int main()
{
    int arr[5];
    cout << "Enter 5 elements: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    int ans = INT_MIN;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] > ans)
        {
            ans = arr[i];
        }
    }

    cout << "Largest element in the Array is : " << ans;
    return 0;
}