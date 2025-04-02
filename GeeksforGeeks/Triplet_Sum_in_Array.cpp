class Solution
{
public:
    bool hasTripletSum(vector<int> &arr, int target)
    {
        int n = arr.size();

        // first method to sort the array
        // sort(arr.begin(), arr.end());

        // second method to sort the array
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

        for (int i = 0; i < n - 2; i++)
        {
            int ans = target - arr[i];
            int start = i + 1, end = n - 1;

            while (start < end)
            {
                if (arr[start] + arr[end] == ans)
                {
                    return 1;
                }
                else if (arr[start] + arr[end] > ans)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }

        return 0;
    }
};