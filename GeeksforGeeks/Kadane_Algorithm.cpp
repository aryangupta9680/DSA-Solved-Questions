class Solution
{
public:
    int maxSubarraySum(vector<int> &arr)
    {
        int n = arr.size();
        int maximum = INT_MIN, prefix = 0;
        for (int i = 0; i < n; i++)
        {
            prefix += arr[i];
            maximum = max(maximum, prefix);
            if (prefix < 0)
            {
                prefix = 0;
            }
        }

        return maximum;
    }
};