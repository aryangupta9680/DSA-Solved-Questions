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
    void recoverTree(TreeNode *root)
    {
        TreeNode *curr = NULL;
        TreeNode *first = NULL, *second = NULL;
        TreeNode *last = NULL, *present = NULL;

        while (root)
        {
            // left doesn't exists
            if (!root->left)
            {
                last = present;
                present = root;
                if (last && last->val > present->val)
                {
                    if (!first)
                    {
                        first = last;
                    }
                    second = present;
                }
                root = root->right;
            }

            // left exists
            else
            {
                curr = root->left;
                while (curr->right && curr->right != root)
                {
                    curr = curr->right;
                }

                // Left subtree not traversed yet
                if (!curr->right)
                {
                    curr->right = root;
                    root = root->left;
                }

                // left subtree already traversed
                else
                {
                    curr->right = NULL;
                    last = present;
                    present = root;
                    if (last && last->val > present->val)
                    {
                        if (!first)
                        {
                            first = last;
                        }
                        second = present;
                    }
                    root = root->right;
                }
            }
        }

        int num = first->val;
        first->val = second->val;
        second->val = num;
    }
};