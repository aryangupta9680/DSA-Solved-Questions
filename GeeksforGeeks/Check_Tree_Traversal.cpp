// Back-end complete function Template for C++
class Node
{
public:
    int data;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    int find(int inorder[], int target, int start, int end)
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

    Node *CreateTree1(int inorder[], int preorder[], int InStart, int InEnd, int index, bool &valid)
    {
        if (InStart > InEnd)
        {
            return NULL;
        }

        Node *root = new Node(preorder[index]);

        int pos = find(inorder, preorder[index], InStart, InEnd);

        if (pos == -1)
        {
            valid = 0;
            return NULL;
        }

        root->left = CreateTree1(inorder, preorder, InStart, pos - 1, index + 1, valid);

        root->right = CreateTree1(inorder, preorder, pos + 1, InEnd, index + (pos - InStart) + 1, valid);

        return root;
    }

    Node *CreateTree2(int inorder[], int postorder[], int InStart, int InEnd, int index, bool &valid)
    {
        if (InStart > InEnd)
        {
            return NULL;
        }

        Node *root = new Node(postorder[index]);

        int pos = find(inorder, postorder[index], InStart, InEnd);

        if (pos == -1)
        {
            valid = 0;
            return NULL;
        }

        root->right = CreateTree2(inorder, postorder, pos + 1, InEnd, index - 1, valid);

        root->left = CreateTree2(inorder, postorder, InStart, pos - 1, index - (InEnd - pos) - 1, valid);

        return root;
    }

    bool check(Node *root1, Node *root2)
    {
        if (!root1 && !root2)
            return 1;

        if (!root1 || !root2)
            return 0;

        if (root1->data != root2->data)
            return 0;

        return check(root1->left, root2->left) && check(root1->right, root2->right);
    }

    bool checktree(int preorder[], int inorder[], int postorder[], int n)
    {
        bool valid = 1;
        Node *tree1 = CreateTree1(inorder, preorder, 0, n - 1, 0, valid);
        Node *tree2 = CreateTree2(inorder, postorder, 0, n - 1, n - 1, valid);

        if (!valid)
            return 0;

        if (!tree1 || !tree2)
            return 0;

        return check(tree1, tree2);
    }
};
