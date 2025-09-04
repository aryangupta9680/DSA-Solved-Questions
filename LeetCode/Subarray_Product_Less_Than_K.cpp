class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int product = 1, start = 0, end = 0, n = nums.size(), count = 0;

        while (end < n)
        {
            product *= nums[end];
            while (product >= k && start <= end)
            {
                product /= nums[start];
                start++;
            }

            count += (end - start) + 1;
            end++;
        }

        return count;
    }
};