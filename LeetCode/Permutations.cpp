// First Method:

// class Solution
// {
// public:
//     void permutation(vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, vector<bool> &visited)
//     {
//         // base condition
//         if (visited.size() == temp.size())
//         {
//             ans.push_back(temp);
//             return;
//         }

//         for (int i = 0; i < visited.size(); i++)
//         {
//             if (visited[i] == 0)
//             {
//                 visited[i] = 1;
//                 temp.push_back(arr[i]);
//                 permutation(arr, ans, temp, visited);
//                 visited[i] = 0;
//                 temp.pop_back();
//             }
//         }
//     }

//     vector<vector<int>> permute(vector<int> &nums)
//     {
//         vector<vector<int>> ans;
//         vector<int> temp;
//         vector<bool> visited(nums.size(), 0);
//         permutation(nums, ans, temp, visited);
//         return ans;
//     }
// };

// Second Method:
class Solution
{
public:
    void permutation(vector<int> &arr, vector<vector<int>> &ans, int index)
    {
        // base condition
        if (arr.size() == index)
        {
            ans.push_back(arr);
            return;
        }

        for (int i = index; i < arr.size(); i++)
        {
            swap(arr[i], arr[index]);
            permutation(arr, ans, index + 1);
            swap(arr[i], arr[index]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        permutation(nums, ans, 0);
        return ans;
    }
};