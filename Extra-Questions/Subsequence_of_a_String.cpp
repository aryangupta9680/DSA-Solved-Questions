#include <iostream>
#include <vector>
using namespace std;

void subset(string &s, int index, int n, vector<string> &ans, string &temp)
{
    // base condition
    if (index == n)
    {
        ans.push_back(temp);
        return;
    }

    // Not included
    subset(s, index + 1, n, ans, temp);

    // Included
    temp.push_back(s[index]);
    subset(s, index + 1, n, ans, temp);
    temp.pop_back();
}

int main()
{
    string s = "abc";
    vector<string> ans; // final answer
    string temp;
    subset(s, 0, s.size(), ans, temp);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}