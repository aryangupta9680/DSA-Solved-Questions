// Method 1:
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution
{
public:
    void inorder(Node *root, vector<int> &ans)
    {
        if (!root)
        {
            return;
        }

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node *root)
    {
        vector<int> ans;
        inorder(root, ans);

        for (int i = 1; i < ans.size(); i++)
        {
            if (ans[i] <= ans[i - 1])
            {
                return 0;
            }
        }

        return 1;
    }
};





// Method 2:
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution
{
public:
    bool BST(Node *root, int &prev)
    {
        if (!root)
        {
            return 1;
        }

        bool l = BST(root->left, prev);

        if (l == 0)
        {
            return 0;
        }

        if (root->data <= prev)
        {
            return 0;
        }

        prev = root->data;

        return BST(root->right, prev);
    }

    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node *root)
    {
        int prev = INT_MIN;
        return BST(root, prev);
    }
};
