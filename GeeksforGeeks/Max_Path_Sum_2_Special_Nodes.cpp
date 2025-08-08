/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    int PathSum(Node *root, int &sum)
    {
        if (!root)
        {
            return 0;
        }

        // Leaf node (special node)
        if (!root->left && !root->right)
        {
            return root->data;
        }

        int left = PathSum(root->left, sum);
        int right = PathSum(root->right, sum);

        // left and right both exist
        if (root->left && root->right)
        {
            sum = max(sum, root->data + left + right);
            return (root->data + max(left, right));
        }

        // only left exists
        if (root->left)
        {
            return (root->data + left);
        }

        // only right exists
        if (root->right)
        {
            return (root->data + right);
        }
    }

    int maxPathSum(Node *root)
    {
        int sum = INT_MIN;
        int val = PathSum(root, sum);

        // if root has both left and right
        if (root->left && root->right)
        {
            return sum;
        }

        // if root is a special node
        return max(sum, val);
    }
};