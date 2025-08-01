// Method 1:
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution
{
public:
    void CountLeaf(Node *root, int &count)
    {
        if (root == NULL)
        {
            return;
        }

        if (!root->left && !root->right)
        {
            count++;
            return;
        }

        CountLeaf(root->left, count);
        CountLeaf(root->right, count);
    }

    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node *root)
    {
        int count = 0;
        CountLeaf(root, count);
        return count;
    }
};



// Method 2:
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution
{
public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        if (!root->left && !root->right)
        {
            return 1;
        }

        return (countLeaves(root->left) + countLeaves(root->right));
    }
};