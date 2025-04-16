// Using KMP Algorithm

class Solution
{
public:
    int longestPrefixSuffix(string &s)
    {
        vector<int> lps(s.size(), 0);
        int prefix = 0, suffix = 1;

        while (suffix < s.size())
        {
            if (s[prefix] == s[suffix])
            {
                lps[suffix] = prefix + 1;
                suffix++;
                prefix++;
            }

            else
            {
                if (prefix == 0)
                {
                    lps[suffix] = 0;
                    suffix++;
                }

                else
                {
                    prefix = lps[prefix - 1];
                }
            }
        }

        return lps[s.size() - 1];
    }
};