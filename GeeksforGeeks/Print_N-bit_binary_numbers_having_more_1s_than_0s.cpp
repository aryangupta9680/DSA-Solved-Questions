class Solution
{
public:
    void find(int n, vector<string> &ans, string &temp, int one, int zero)
    {
        // base condition
        if (n == temp.size())
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back('1');
        find(n, ans, temp, one + 1, zero);
        temp.pop_back();

        if (zero < one)
        {
            temp.push_back('0');
            find(n, ans, temp, one, zero + 1);
            temp.pop_back();
        }
    }

    vector<string> NBitBinary(int n)
    {
        vector<string> ans;
        string temp;
        find(n, ans, temp, 0, 0);
        return ans;
    }
};