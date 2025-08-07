// Method 1:
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





// Method 2: Using Morris Traversal
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
        vector<int> ans;

        while (root)
        {
            // Left subtree doesn't exist
            if (!root->left)
            {
                ans.push_back(root->data);
                root = root->right;
            }

            // Left subtree exists
            else
            {
                Node *curr = root->left;
                while (curr->right && curr->right != root)
                {
                    curr = curr->right;
                }

                // Left subtree not yet traversed
                if (curr->right == NULL)
                {
                    ans.push_back(root->data);
                    curr->right = root; // Make link to come back later
                    root = root->left;
                }

                // Left subtree already traversed
                else
                {
                    curr->right = NULL; // Remove the link
                    root = root->right;
                }
            }
        }

        return ans;
    }
};