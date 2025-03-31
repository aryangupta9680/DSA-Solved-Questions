class Solution
{
public:
    bool isProduct(vector<int> arr, long long x)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int start = 0, end = n - 1;

        while (start < end)
        {
            long long product = (long long)arr[start] * arr[end];
            if (product == x)
            {
                return 1;
            }

            else if (product < x)
            {
                start++;
            }

            else
            {
                end--;
            }
        }

        return 0;
    }
};