/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    void correctBST(Node *root)
    {
        Node *curr = NULL;
        Node *first = NULL, *second = NULL;
        Node *last = NULL, *present = NULL;

        while (root)
        {
            // left doesn't exists
            if (!root->left)
            {
                last = present;
                present = root;
                if (last && last->data > present->data)
                {
                    if (!first)
                    {
                        first = last;
                    }
                    second = present;
                }
                root = root->right;
            }

            // left exists
            else
            {
                curr = root->left;
                while (curr->right && curr->right != root)
                {
                    curr = curr->right;
                }

                // Left subtree not traversed yet
                if (!curr->right)
                {
                    curr->right = root;
                    root = root->left;
                }

                // left subtree already traversed
                else
                {
                    curr->right = NULL;
                    last = present;
                    present = root;
                    if (last && last->data > present->data)
                    {
                        if (!first)
                        {
                            first = last;
                        }
                        second = present;
                    }
                    root = root->right;
                }
            }
        }

        int num = first->data;
        first->data = second->data;
        second->data = num;
    }
};