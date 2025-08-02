/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node *root)
    {
        if (!root)
        {
            return;
        }

        Node *temp = root->right;
        root->right = root->left;
        root->left = temp;

        mirror(root->left);
        mirror(root->right);
    }
};