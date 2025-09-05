class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int total = INT_MAX, start = 0, end = 0;
        int sum = 0, n = nums.size();

        while (end < n)
        {
            sum += nums[end]; // add number to the sum

            // window ki length ko decrease kr sakta hu
            while (sum >= target)
            {
                total = min(total, end - start + 1);
                sum -= nums[start];
                start++;
            }

            // window length ko increase karo
            end++;
        }

        return total == INT_MAX ? 0 : total;
    }
};