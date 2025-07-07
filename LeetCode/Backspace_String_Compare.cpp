class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> temp1;
        stack<char> temp2;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '#')
            {
                if (!temp1.empty())
                {
                    temp1.pop();
                }
            }
            else
            {
                temp1.push(s[i]);
            }
        }

        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == '#')
            {
                if (!temp2.empty())
                {
                    temp2.pop();
                }
            }
            else
            {
                temp2.push(t[i]);
            }
        }

        return temp1 == temp2;
    }
};