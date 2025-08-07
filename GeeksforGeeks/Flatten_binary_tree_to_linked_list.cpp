// User function Template for C++

class Solution
{
public:
    void flatten(Node *root)
    {
        while (root)
        {
            // left part doesn't exist
            if (!root->left)
            {
                root = root->right;
            }

            // left part exists
            else
            {
                Node *curr = root->left;
                while (curr->right)
                {
                    curr = curr->right;
                }

                curr->right = root->right;
                root->right = root->left;
                root->left = NULL;
                root = root->right;
            }
        }
    }
};