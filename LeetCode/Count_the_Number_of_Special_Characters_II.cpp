class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>small(26, -1);
        vector<int>capital(26, -1);

        for(int i = 0; i < word.size();i++)
        {
            if(islower(word[i])) 
            {
                small[word[i] - 'a'] = i;
            }
            else 
            {
                int idx = word[i] - 'A';
                if(capital[idx] == -1) 
                {
                    capital[idx] = i;
                }
            }
        }

        int count = 0;
        for(int i = 0; i < 26; i++) 
        {
            if(small[i] != -1 && capital[i] != -1 && small[i] < capital[i]) 
            {
                count++;
            }
        }

        return count;
    }
};