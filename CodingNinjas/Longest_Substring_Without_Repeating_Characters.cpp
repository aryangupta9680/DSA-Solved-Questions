#include <bits/stdc++.h>
int uniqueSubstrings(string input)
{
    vector<bool> count(256, 0);

    int first = 0, second = 0, len = 0;
    while (second < input.size())
    {
        // Repeating character
        while (count[input[second]])
        {
            count[input[first]] = 0;
            first++;
        }

        count[input[second]] = 1;
        len = max(len, second - first + 1);
        second++;
    }

    return len;
}