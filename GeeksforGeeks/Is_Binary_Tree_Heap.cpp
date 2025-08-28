// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution
{
public:
    int Count(Node *root)
    {
        if (!root)
        {
            return false;
        }

        return (1 + Count(root->left) + Count(root->right));
    }

    bool CBT(Node *root, int index, int total_nodes)
    {
        if (!root)
        {
            return true;
        }

        if (index >= total_nodes)
        {
            return false;
        }

        // left side CBT && Right side CBT
        return CBT(root->left, 2 * index + 1, total_nodes) && CBT(root->right, 2 * index + 2, total_nodes);
    }

    bool MaxHeap(Node *root)
    {
        // one node exists only
        if (root->left)
        {
            if (root->data < root->left->data)
            {
                return false;
            }

            if (!MaxHeap(root->left))
            {
                return false;
            }
        }

        if (root->right)
        {
            if (root->data < root->right->data)
            {
                return false;
            }

            return MaxHeap(root->right);
        }

        return true;
    }

    bool isHeap(Node *tree)
    {
        // Count nodes in the tree
        int num = Count(tree);

        // Complete Binary Tree hai ya nahi
        bool ans = CBT(tree, 0, num);
        if (ans == 0)
        {
            return false;
        }

        // Every Parent >= its child
        return MaxHeap(tree);
    }
};