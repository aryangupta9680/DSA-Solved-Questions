#include <iostream>
using namespace std;

bool checkpal(string str, int start, int end)
{
    // base condition 
    if(start>=end)
    {
        return 1;
    }

    // not matched
    if (str[start] != str[end])
    {
        return 0;
    }

    // matched
    else
    {
        return checkpal(str, start+1, end-1);
    }
}

int main()
{
    // check pallindrome
    string str = "naman";
    cout << checkpal(str, 0, 4);

    return 0;
}