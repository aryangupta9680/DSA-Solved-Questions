class Solution
{
public:
    void lpsfind(vector<int> &lps, string &s)
    {
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
    }

    int KMP_MATCH(string haystack, string needle)
    {
        vector<int> lps(needle.size(), 0);
        lpsfind(lps, needle);

        int first = 0, second = 0;
        while (second < needle.size() && first < haystack.size())
        {
            // Match
            if (haystack[first] == needle[second])
            {
                first++;
                second++;
            }

            // Not Match
            else
            {
                if (second == 0)
                {
                    first++;
                }
                else
                {
                    second = lps[second - 1];
                }
            }
        }

        // answer exist
        if (second == needle.size())
        {
            return 1;
        }

        return 0;
    }

    int repeatedStringMatch(string a, string b)
    {
        if (a == b)
        {
            return 1;
        }

        int repeat = 1;
        string temp = a;

        while (temp.size() < b.size())
        {
            temp += a;
            repeat++;
        }

        // KMP Pattern Search
        if (KMP_MATCH(temp, b) == 1)
        {
            return repeat;
        }

        // temp+a, KMP Pattern Search
        if (KMP_MATCH(temp + a, b) == 1)
        {
            return repeat + 1;
        }

        return -1;
    }
};