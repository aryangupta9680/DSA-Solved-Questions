class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int zeroCount = 0;
        int ans = 0;

        for(int right = 0; right < n; right++) 
        {
            // Count zeros in current window
            if(nums[right] == 0) 
            {
                zeroCount++;
            }

            // If zeros exceed k, shrink window
            while(zeroCount > k) 
            {
                if(nums[left] == 0) 
                {
                    zeroCount--;
                }
                left++;
            }

            // Update maximum length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};