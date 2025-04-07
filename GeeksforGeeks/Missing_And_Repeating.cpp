class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        int n = arr.size();

        // decrease value by 1
        for (int i = 0; i < n; i++)
        {
            arr[i]--;
        }

        // occurrence
        for (int i = 0; i < n; i++)
        {
            arr[arr[i] % n] += n;
        }

        vector<int> ans(2);

        for (int i = 0; i < n; i++)
        {
            // repeating number
            if (arr[i] / n == 2)
            {
                ans[0] = i + 1;
            }

            // missing number
            else if (arr[i] / n == 0)
            {
                ans[1] = i + 1;
            }
        }

        return ans;
    }
};