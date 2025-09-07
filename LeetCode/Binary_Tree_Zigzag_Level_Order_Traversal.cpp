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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        if (!root)
        {
            return ans;
        }

        stack<TreeNode *> s1; // Right to Left
        stack<TreeNode *> s2; // Left to Right
        s1.push(root);

        while (!s1.empty() || !s2.empty())
        {
            // Right to Left
            if (!s1.empty())
            {
                while (!s1.empty())
                {
                    vector<int> level;
                    while (!s1.empty())
                    {
                        TreeNode *temp = s1.top();
                        s1.pop();
                        level.push_back(temp->val);
                        // Left
                        if (temp->left)
                        {
                            s2.push(temp->left);
                        }
                        // Right
                        if (temp->right)
                        {
                            s2.push(temp->right);
                        }
                    }
                    ans.push_back(level);
                }
            }

            // Left to Right
            else
            {
                while (!s2.empty())
                {
                    vector<int> level;
                    while (!s2.empty())
                    {
                        TreeNode *temp = s2.top();
                        s2.pop();
                        level.push_back(temp->val);
                        // Right
                        if (temp->right)
                        {
                            s1.push(temp->right);
                        }
                        // Left
                        if (temp->left)
                        {
                            s1.push(temp->left);
                        }
                    }
                    ans.push_back(level);
                }
            }
        }

        return ans;
    }
};