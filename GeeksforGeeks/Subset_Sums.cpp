class Solution
{
public:
    void print(vector<int> &arr, int index, int n, int sum, vector<int> &ans)
    {
        // base condition
        if (index == n)
        {
            ans.push_back(sum);
            return;
        }

        // Not included
        print(arr, index + 1, n, sum, ans);

        // Included
        print(arr, index + 1, n, sum + arr[index], ans);
    }

    vector<int> subsetSums(vector<int> &arr)
    {
        vector<int> ans;
        print(arr, 0, arr.size(), 0, ans);
        return ans;
    }
};