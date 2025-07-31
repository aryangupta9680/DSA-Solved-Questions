/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */
class Solution
{
public:
    void postOrderTraversal(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        postOrderTraversal(root->left, ans);
        postOrderTraversal(root->right, ans);
        ans.push_back(root->data);
    }

    // Function to return a list containing the postorder traversal of the tree.
    vector<int> postOrder(Node *root)
    {
        vector<int> ans;
        postOrderTraversal(root, ans);
        return ans;
    }
};