// Method 1:
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.
class Solution
{
public:
    void Total(Node *root, int &sum)
    {
        if (root == NULL)
        {
            return;
        }

        sum += root->data;
        Total(root->left, sum);
        Total(root->right, sum);
    }

    int sumBT(Node *root)
    {
        int sum = 0;
        Total(root, sum);
        return sum;
    }
};



// Method 2:
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.
class Solution
{
public:
    int sumBT(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        return (root->data + sumBT(root->left) + sumBT(root->right));
    }
};