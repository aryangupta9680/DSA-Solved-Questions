class Solution
{
public:
    void permutations(vector<int> &arr, vector<vector<int>> &ans, int index)
    {
        // base condition
        if (index == arr.size())
        {
            ans.push_back(arr);
            return;
        }

        vector<bool> use(21, 0);
        for (int i = index; i < arr.size(); i++)
        {
            if (use[arr[i] + 10] == 0)
            {
                swap(arr[index], arr[i]);
                permutations(arr, ans, index + 1);
                swap(arr[index], arr[i]);
                use[arr[i] + 10] = 1;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        permutations(nums, ans, 0);
        return ans;
    }
};