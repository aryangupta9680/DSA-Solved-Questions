/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *ArrayToBST(vector<int> &nums, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }

        // find middle value
        int mid = start + (end - start) / 2;

        // Create Node
        TreeNode *temp = new TreeNode(nums[mid]);

        // Left
        temp->left = ArrayToBST(nums, start, mid - 1);

        // Right
        temp->right = ArrayToBST(nums, mid + 1, end);

        return temp;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return ArrayToBST(nums, 0, nums.size() - 1);
    }
};