// User function Template for C++

class Solution
{
public:
    vector<int> makeBeautiful(vector<int> arr)
    {
        stack<int> s;

        for (int i = 0; i < arr.size(); i++)
        {
            // stack can be negative
            if (s.empty())
            {
                s.push(arr[i]);
            }

            // non-negative number
            else if (arr[i] >= 0)
            {
                // non-negative number
                if (s.top() >= 0)
                {
                    s.push(arr[i]);
                }
                // negative number
                else
                {
                    s.pop();
                }
            }

            // negative number
            else
            {
                // negative number
                if (s.top() < 0)
                {
                    s.push(arr[i]);
                }
                // non-negative number
                else
                {
                    s.pop();
                }
            }
        }

        vector<int> ans(s.size());
        int i = s.size() - 1;
        while (!s.empty())
        {
            ans[i] = s.top();
            i--;
            s.pop();
        }

        return ans;
    }
};