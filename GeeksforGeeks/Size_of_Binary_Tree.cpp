// Method 1
/*
Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    void Total(Node *root, int &count)
    {
        if (root == NULL)
        {
            return;
        }

        count++;
        Total(root->left, count);
        Total(root->right, count);
    }

    int getSize(Node *root)
    {
        int count = 0;
        Total(root, count);
        return count;
    }
};




// Method 2:
/*
Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    int getSize(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        return (1 + getSize(root->left) + getSize(root->right));
    }
};