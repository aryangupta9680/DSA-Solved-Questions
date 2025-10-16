/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    void KSmallest(Node *root, int &ans, int &k)
    {
        if (!root)
        {
            return;
        }

        KSmallest(root->left, ans, k);
        k--;
        if (k == 0)
        {
            ans = root->data;
        }
        if (k <= 0)
        {
            return;
        }
        KSmallest(root->right, ans, k);
    }

    int kthSmallest(Node *root, int k)
    {
        int ans = -1;
        KSmallest(root, ans, k);
        return ans;
    }
};