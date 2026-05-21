#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int n = v.size();
    vector<int>ans;

    for(int i = 0; i < n-3;i++)
    {
        int j = i;
        int count = k;
        int maximum = INT_MIN;
        while(count > 0)
        {
            maximum = max(maximum, v[j]);
        }
        ans.push_back(maximum);
        j++;
        count--;
    }

    for(int i = 0; i < n;i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}