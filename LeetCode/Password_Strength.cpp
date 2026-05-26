class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char>st(password.begin(), password.end());
        int ans = 0;
        
        for(char ch : st) 
        {
            if(ch >= 'a' && ch <= 'z')
            {
                ans += 1;
            }
            else if(ch >= 'A' && ch <= 'Z')
            {
                ans += 2;
            }
            else if(ch >= '0' && ch <= '9')
            {
                ans += 3;
            }
            else
            {
                ans += 5;
            }
        }
        
        return ans;
    }
};