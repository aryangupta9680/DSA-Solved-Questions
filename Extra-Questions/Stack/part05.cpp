#include <iostream>
#include <stack>
using namespace std;

bool check(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        // opening bracket
        if (str[i] == '(')
        {
            s.push(str[i]);
        }

        // closing bracket
        else
        {
            if (s.empty())
            {
                return 0;
            }
            else
            {
                s.pop();
            }
        }
    }

    return s.empty();
}

int main()
{
    string str = "((()))";
    cout << check(str) << endl;
    return 0;
}