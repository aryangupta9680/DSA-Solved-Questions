#include <iostream>
#include <limits.h> // For INT_MAX
using namespace std;

int main()
{
    int arr[5];
    cout << "Enter 5 elements: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    int ans = INT_MAX;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] < ans)
        {
            ans = arr[i];
        }
    }

    cout << ans;
    return 0;
}