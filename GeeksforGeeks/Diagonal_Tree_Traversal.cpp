/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution
{
public:
    void find(Node *root, int pos, int &l)
    {
        if (!root)
        {
            return;
        }

        l = max(pos, l);

        find(root->left, pos + 1, l);
        find(root->right, pos, l);
    }

    void findDiagonal(Node *root, int pos, vector<vector<int>> &ans)
    {
        if (!root)
        {
            return;
        }

        ans[pos].push_back(root->data);
        findDiagonal(root->left, pos + 1, ans);
        findDiagonal(root->right, pos, ans);
    }

    vector<int> diagonal(Node *root)
    {
        int l = 0;
        find(root, 0, l);
        vector<vector<int>> ans(l + 1);
        findDiagonal(root, 0, ans);

        vector<int> result;
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                result.push_back(ans[i][j]);
            }
        }

        return result;
    }
};