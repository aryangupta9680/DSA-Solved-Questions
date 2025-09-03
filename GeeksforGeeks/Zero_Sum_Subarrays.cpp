class Solution
{
public:
    int findSubarray(vector<int> &arr)
    {
        int n = arr.size();
        int total = 0; // total number of subarrays whose sum is 0

        // map
        // Prefix sum, count
        unordered_map<int, int> m;
        int PrefixSum = 0;
        // initialize by 0,1
        m[0] = 1;

        for (int i = 0; i < n; i++)
        {
            PrefixSum += arr[i];
            if (m.count(PrefixSum))
            {
                total += m[PrefixSum];
                m[PrefixSum]++;
            }
            else
            {
                m[PrefixSum] = 1;
            }
        }

        return total;
    }
};