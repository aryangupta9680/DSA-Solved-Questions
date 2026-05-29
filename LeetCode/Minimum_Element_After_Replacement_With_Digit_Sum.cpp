class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0; i < n;i++)
        {
            int sum = 0;
            while(nums[i] != 0)
            {
                int rem = nums[i] % 10;
                sum += rem;
                nums[i] /= 10;
            }
            ans.push_back(sum);
        }

        int minimum = INT_MAX;
        for(int i = 0; i < n;i++)
        {
            minimum = min(minimum, ans[i]);
        }

        return minimum;
    }
};