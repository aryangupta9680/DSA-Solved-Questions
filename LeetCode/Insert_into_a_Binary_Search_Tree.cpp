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
    TreeNode *insertIntoBST(TreeNode *root, int key)
    {
        // base case
        if (!root)
        {
            TreeNode *temp = new TreeNode(key);
            return temp;
        }

        if (key < root->val)
        {
            root->left = insertIntoBST(root->left, key);
        }

        else if (key > root->val)
        {
            root->right = insertIntoBST(root->right, key);
        }

        return root;
    }
};