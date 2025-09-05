class Solution
{
public:
    string minWindow(string s, string t)
    {
        int total = t.size();
        // char , count
        // unordered_map<char, int>m;

        vector<int> m(256, 0);
        for (int i = 0; i < t.size(); i++)
        {
            m[t[i]]++;
        }

        int start = 0, end = 0, ans = INT_MAX, index = -1;
        // ans store minimum length of substring
        // index store starting index of our answer
        int n = s.size();
        while (end < n)
        {
            m[s[end]]--;        // decrease the count of char
            if (m[s[end]] >= 0) // if count is not negative so decrease the total
            {
                total--;
            }

            // Can we decrease the size of window
            while (!total && start <= end)
            {
                // update the length of substring
                if (ans > end - start + 1)
                {
                    ans = end - start + 1;
                    index = start;
                }

                m[s[start]]++;       // increase the count of character
                if (m[s[start]] > 0) // if count is positive then increase the total
                {
                    total++;
                }

                start++;
            }

            // increase the size of window
            end++;
        }

        if (index == -1)
        {
            return "";
        }

        string str = "";
        for (int i = index; i < index + ans; i++)
        {
            str += s[i];
        }

        return str;
    }
};