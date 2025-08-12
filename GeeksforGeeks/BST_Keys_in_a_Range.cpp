int n1, n2; // global variable
class Solution
{
public:
    void Find(Node *root, vector<int> &ans)
    {
        if (!root)
        {
            return;
        }

        // Left
        if (root->data > n1 && root->data > n2)
        {
            Find(root->left, ans);
        }

        // Right
        else if (root->data < n1 && root->data < n2)
        {
            Find(root->right, ans);
        }

        else
        {
            Find(root->left, ans);
            ans.push_back(root->data);
            Find(root->right, ans);
        }
    }

    vector<int> printNearNodes(Node *root, int low, int high)
    {
        vector<int> ans;
        n1 = low, n2 = high;
        Find(root, ans);
        return ans;
    }
};