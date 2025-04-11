class Solution
{
public:
    string sortVowels(string s)
    {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        for (int i = 0; i < s.size(); i++)
        {
            // lower
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                lower[s[i] - 'a']++;
                s[i] = '#';
            }
            // upper
            else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                upper[s[i] - 'A']++;
                s[i] = '#';
            }
        }

        string vowel;

        // upper
        for (int i = 0; i < 26; i++)
        {
            char c = 'A' + i;
            while (upper[i])
            {
                vowel += c;
                upper[i]--;
            }
        }

        // lower
        for (int i = 0; i < 26; i++)
        {
            char c = 'a' + i;
            while (lower[i])
            {
                vowel += c;
                lower[i]--;
            }
        }

        // first point index of string s and second point index of string vowel
        int first = 0, second = 0;
        while (second < vowel.size())
        {
            if (s[first] == '#')
            {
                s[first] = vowel[second];
                second++;
            }

            first++;
        }

        return s;
    }
};