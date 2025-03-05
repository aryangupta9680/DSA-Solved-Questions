#include <bits/stdc++.h>
int reverseInteger(int n)
{
    int rem, ans = 0;
    while (n)
    {
        rem = n % 10;
        n /= 10;
        if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10))
        {
            return -1;
        }
        ans = ans * 10 + rem;
    }

    return ans;
}