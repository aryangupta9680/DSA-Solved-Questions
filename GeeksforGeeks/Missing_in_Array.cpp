// User function template for C++
class Solution
{
public:
    int missingNumber(vector<int> &arr)
    {
        long int n = arr.size() + 1;
        long int sum = 0;

        for (int i = 0; i < n - 1; i++)
        {
            sum += arr[i];
        }

        long int ans;
        ans = (n * (n + 1)) / 2;

        return ans - sum;
    }
};