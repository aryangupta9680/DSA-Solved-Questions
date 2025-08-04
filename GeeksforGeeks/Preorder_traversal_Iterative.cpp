// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
public:
    vector<int> preOrder(Node *root)
    {
        stack<Node *> s;
        s.push(root);
        vector<int> ans;

        while (!s.empty())
        {
            Node *temp = s.top();
            s.pop();
            ans.push_back(temp->data);

            if (temp->right)
            {
                s.push(temp->right);
            }

            if (temp->left)
            {
                s.push(temp->left);
            }
        }

        return ans;
    }
};