#include <iostream>
#include <vector>
using namespace std;

void print(int arr[], int index, int n, int sum, vector<int> &ans)
{
    // base condition
    if (index == n)
    {
        // first method to print
        // cout << sum << endl;

        // second method to print
        ans.push_back(sum);
        return;
    }

    // Not included
    print(arr, index + 1, n, sum, ans);

    // Included
    print(arr, index + 1, n, sum + arr[index], ans);
}

int main()
{
    int arr[] = {3, 4, 5};
    vector<int> ans;
    print(arr, 0, 3, 0, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}