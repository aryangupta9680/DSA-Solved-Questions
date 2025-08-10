// User function Template for C++

/*
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

// Function to find ceil of a given input in BST. If input is more
// than the max key in BST, return -1
void KSum(Node *root, int &s, int &k)
{
    if (!root)
    {
        return;
    }

    KSum(root->left, s, k);
    k--;

    if (k >= 0)
    {
        s += root->data;
    }

    if (k <= 0)
    {
        return;
    }

    KSum(root->right, s, k);
}

int sum(Node *root, int k)
{
    int s = 0;
    KSum(root, s, k);
    return s;
}