class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int target = nums[0] + nums[1];
        int total = 1;

        for (int i = 2; i < n - 1;i += 2) 
        {
            int currentSum = nums[i] + nums[i + 1];
            if (currentSum == target) 
            {
                total++;
            }
            else 
            {
                break;
            }
        }

        return total; 
    }
};