/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void KSmallest(TreeNode *root, int &ans, int &k)
{
    if (!root)
    {
        return;
    }

    KSmallest(root->left, ans, k);
    k--;
    if (k == 0)
    {
        ans = root->val;
    }
    if (k <= 0)
    {
        return;
    }
    KSmallest(root->right, ans, k);
}

int Solution::kthsmallest(TreeNode *A, int B)
{
    int ans;
    KSmallest(A, ans, B);
    return ans;
}
