// Function to insert a node in a BST.

/*
struct Node {
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
    Node *insert(Node *root, int key)
    {
        // base case
        if (!root)
        {
            Node *temp = new Node(key);
            return temp;
        }

        if (key < root->data)
        {
            root->left = insert(root->left, key);
        }

        else if (key > root->data)
        {
            root->right = insert(root->right, key);
        }

        return root;
    }
};