class Solution
{
public:
    int minChar(string &s)
    {
        // Reverse of string s
        string rev = s;
        reverse(rev.begin(), rev.end());
        int size = s.size();
        s += '$'; // seperator
        s += rev; // reverse

        int n = s.size();
        vector<int> lps(n, 0);
        int prefix = 0, suffix = 1;

        while (suffix < s.size())
        {
            // Matched
            if (s[prefix] == s[suffix])
            {
                lps[suffix] = prefix + 1;
                prefix++, suffix++;
            }

            // Not Matched
            else
            {
                if (prefix == 0)
                {
                    suffix++;
                }

                else
                {
                    prefix = lps[prefix - 1];
                }
            }
        }

        // answer
        return size - lps[n - 1];
    }
};