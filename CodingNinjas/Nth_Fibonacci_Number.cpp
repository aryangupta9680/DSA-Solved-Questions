#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, current, last = 1, prev = 1;
    cin >> n;
    if ((n == 1) || (n == 2))
    {
        cout << 1;
    }
    else
    {
        for (i = 3; i <= n; i++)
        {
            current = last + prev;
            last = prev;
            prev = current;
        }
        cout << current;
    }
}