class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        // unordered map
        unordered_map<int, int> m; // store remainder with their count
        m[0] = 1;

        int rem, PrefixSum = 0, total = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            PrefixSum += nums[i];
            rem = PrefixSum % k;

            if (rem < 0) // if remainder is negative, make it positive
            {
                rem = rem + k;
            }

            if (m.count(rem))
            {
                total += m[rem];
                m[rem]++;
            }
            else
            {
                m[rem] = 1;
            }
        }

        return total;
    }
};