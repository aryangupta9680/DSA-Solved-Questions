#include <sstream> 

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string>ans;
        stringstream ss(s);
        string word;   
        while (ss >> word) 
        {
            ans.push_back(word);             
        }

        string temp = "";
        
        for(int i = ans.size()-1; i >= 0;i--)
        {
            temp += ans[i];
            if(i != 0)
            {
                temp += " ";
            }
        }

        return temp;
    }
};