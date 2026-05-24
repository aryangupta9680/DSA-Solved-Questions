class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;
        for(int x : nums) 
        {
            if(x == 0) zeroCount++;
        }

        int total = 0;

        for(int i = n - zeroCount; i < n; i++) 
        {
            if(nums[i] != 0) total++;
        }

        return total;
    }
};