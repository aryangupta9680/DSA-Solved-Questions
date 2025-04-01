#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool divide(vector<int> arr)
{
    int prefix = 0, total_sum = 0, n = arr.size();
    // Total sum
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        prefix += arr[i];
        if (total_sum == (2 * prefix))
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << divide(v);

    return 0;
}