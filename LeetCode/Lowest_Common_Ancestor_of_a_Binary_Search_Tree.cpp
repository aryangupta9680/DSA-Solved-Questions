/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *n1, TreeNode *n2)
    {
        if (!root)
        {
            return NULL;
        }

        // left
        if (root->val > n1->val && root->val > n2->val)
        {
            return lowestCommonAncestor(root->left, n1, n2);
        }

        // Right
        else if (root->val < n1->val && root->val < n2->val)
        {
            return lowestCommonAncestor(root->right, n1, n2);
        }

        else
        {
            return root;
        }
    }
};