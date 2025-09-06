class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int maxElement = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            maxElement = max(maxElement, nums[i]);
        }

        long long total = 0;
        int start = 0, end = 0, count = 0;

        while (end < n)
        {
            if (nums[end] == maxElement)
            {
                count++;
            }

            while (count == k)
            {
                total += n - end;
                if (nums[start] == maxElement)
                {
                    count--;
                }

                start++;
            }

            end++;
        }

        return total;
    }
};