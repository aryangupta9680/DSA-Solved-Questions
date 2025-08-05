// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    int find(vector<int> &inorder, int target, int start, int end)
    {
        for (int i = start; i <= end; i++)
        {
            if (inorder[i] == target)
            {
                return i;
            }
        }

        return -1;
    }

    Node *Tree(vector<int> &inorder, vector<int> &preorder, int InStart, int InEnd, int index)
    {
        if (InStart > InEnd)
        {
            return NULL;
        }

        Node *root = new Node(preorder[index]);

        int pos = find(inorder, preorder[index], InStart, InEnd);

        root->left = Tree(inorder, preorder, InStart, pos - 1, index + 1);

        root->right = Tree(inorder, preorder, pos + 1, InEnd, index + (pos - InStart) + 1);

        return root;
    }

    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder)
    {
        int n = preorder.size();
        return Tree(inorder, preorder, 0, n - 1, 0);
    }
};