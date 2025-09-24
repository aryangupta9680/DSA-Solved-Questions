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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // base case
        if (!root)
        {
            return NULL;
        }

        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }

        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }

        else
        {
            // leaf node
            if (!root->left && !root->right)
            {
                delete root;
                return NULL;
            }

            // 1 child exists
            else if (!root->right) // left child exists
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            else if (!root->left) // right child exists
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }

            // 2 child exists
            else
            {
                // find the greatest element from left
                TreeNode *child = root->left;
                TreeNode *parent = root;

                // right most node tak jaana hai
                while (child->right)
                {
                    parent = child;
                    child = child->right;
                }

                if (root != parent)
                {
                    parent->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                    delete root;
                    return child;
                }

                else
                {
                    child->right = root->right;
                    delete root;
                    return child;
                }
            }
        }
    }
};