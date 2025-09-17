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
class Box
{
public:
    bool BST;
    int sum;
    int max, min;
    Box()
    {
        BST = 1;
        sum = 0;
        min = INT_MAX;
        max = INT_MIN;
    }
};

class Solution
{
public:
    Box *find(TreeNode *root, int &Totalsum)
    {
        // root doesn't exist
        if (!root)
        {
            return new Box();
        }

        // root exists
        Box *Lefthead = find(root->left, Totalsum);
        Box *Righthead = find(root->right, Totalsum);

        if (Lefthead->BST && Righthead->BST && Lefthead->max < root->val && Righthead->min > root->val)
        {
            Box *head = new Box();
            head->sum = Lefthead->sum + Righthead->sum + root->val;
            head->min = min(root->val, Lefthead->min);
            head->max = max(root->val, Righthead->max);
            Totalsum = max(Totalsum, head->sum);
            return head;
        }
        else
        {
            Lefthead->BST = 0;
            return Lefthead;
        }
    }

    int maxSumBST(TreeNode *root)
    {
        int sum = 0;
        find(root, sum);
        return sum;
    }
};