// Method 1:
// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution
{
public:
    vector<int> postOrder(Node *root)
    {
        stack<Node *> s;
        s.push(root);
        vector<int> ans;

        while (!s.empty())
        {
            Node *temp = s.top();
            s.pop();
            ans.push_back(temp->data);

            // Left
            if (temp->left)
            {
                s.push(temp->left);
            }

            // Right
            if (temp->right)
            {
                s.push(temp->right);
            }
        }

        reverse(ans.begin(), ans.end());
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
};*/
class Solution
{
public:
    vector<int> postOrder(Node *root)
    {
        vector<int> ans;

        while (root)
        {
            // Right subtree doesn't exist
            if (!root->right)
            {
                ans.push_back(root->data);
                root = root->left;
            }

            // Right subtree exists
            else
            {
                Node *curr = root->right;
                while (curr->left && curr->left != root)
                {
                    curr = curr->left;
                }

                // Right subtree not yet traversed
                if (curr->left == NULL)
                {
                    ans.push_back(root->data);
                    curr->left = root; // Make link to come back later
                    root = root->right;
                }

                // Right subtree already traversed
                else
                {
                    curr->left = NULL; // Remove the link
                    root = root->left;
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
