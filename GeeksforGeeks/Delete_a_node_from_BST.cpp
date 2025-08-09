class Solution
{
public:
    // Function to delete a node from BST.
    Node *deleteNode(Node *root, int X)
    {
        // base case
        if (!root)
        {
            return NULL;
        }

        if (root->data > X)
        {
            root->left = deleteNode(root->left, X);
            return root;
        }

        else if (root->data < X)
        {
            root->right = deleteNode(root->right, X);
            return root;
        }

        else
        {
            // leaf node
            if (!root->left && !root->right)
            {
                delete root;
                return NULL;
            }

            // 1 child exists
            else if (!root->right) // left child exists
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            else if (!root->left) // right child exists
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }

            // 2 child exists
            else
            {
                // find the greatest element from left
                Node *child = root->left;
                Node *parent = root;

                // right most node tak jaana hai
                while (child->right)
                {
                    parent = child;
                    child = child->right;
                }

                if (root != parent)
                {
                    parent->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                    delete root;
                    return child;
                }

                else
                {
                    child->right = root->right;
                    delete root;
                    return child;
                }
            }
        }
    }
};