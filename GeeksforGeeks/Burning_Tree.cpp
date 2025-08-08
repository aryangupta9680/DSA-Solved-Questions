/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
public:
    int Burn(Node *root, int &timer, int target)
    {
        // doesn't exist
        if (!root)
        {
            return 0;
        }

        // exist
        // target node
        if (root->data == target)
        {
            return -1;
        }

        int left = Burn(root->left, timer, target);
        int right = Burn(root->right, timer, target);

        // burn ki condition
        if (left < 0)
        {
            timer = max(timer, abs(left) + right);
            return left - 1;
        }

        if (right < 0)
        {
            timer = max(timer, left + abs(right));
            return right - 1;
        }

        // height ko return karna hai
        return (1 + max(left, right));
    }

    void find(Node *root, int target, Node *&BurnNode)
    {
        if (!root)
        {
            return;
        }

        if (root->data == target)
        {
            BurnNode = root;
            return;
        }

        find(root->left, target, BurnNode);
        find(root->right, target, BurnNode);
    }

    int Height(Node *root)
    {
        if (!root)
        {
            return 0;
        }

        return (1 + max(Height(root->left), Height(root->right)));
    }

    int minTime(Node *root, int target)
    {
        int timer = 0;
        Burn(root, timer, target);

        // height of target node ki if we consider it as root node
        Node *BurnNode = NULL;
        find(root, target, BurnNode);

        int high = Height(BurnNode) - 1;

        return max(timer, high);
    }
};