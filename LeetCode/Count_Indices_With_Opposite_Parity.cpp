class Solution
{
public:
    vector<int> countOppositeParity(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 != 0)
            {
                int count = 0;
                for (int j = i + 1; j < n; j++)
                {
                    if (nums[j] % 2 == 0)
                    {
                        count++;
                    }
                }

                ans.push_back(count);
            }
            else
            {
                int count = 0;
                for (int j = i + 1; j < n; j++)
                {
                    if (nums[j] % 2 != 0)
                    {
                        count++;
                    }
                }
                ans.push_back(count);
            }
        }

        return ans;
    }
};