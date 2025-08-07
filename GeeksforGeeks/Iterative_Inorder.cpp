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
    vector<int> inOrder(Node *root)
    {
        stack<Node *> s;
        stack<bool> visited;
        s.push(root);
        visited.push(0);
        vector<int> ans;

        while (!s.empty())
        {
            Node *temp = s.top();
            s.pop();
            bool flag = visited.top();
            visited.pop();

            // first time visit
            if (flag == 0)
            {
                // Right
                if (temp->right)
                {
                    s.push(temp->right);
                    visited.push(0);
                }

                // Node
                s.push(temp);
                visited.push(1);

                // Left
                if (temp->left)
                {
                    s.push(temp->left);
                    visited.push(0);
                }
            }

            // second time visit
            else
            {
                ans.push_back(temp->data);
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
};*/
class Solution
{
public:
    vector<int> inOrder(Node *root)
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
                    curr->right = root; // Make link to come back later
                    root = root->left;
                }

                // Left subtree already traversed
                else
                {
                    curr->right = NULL; // Remove the link
                    ans.push_back(root->data);
                    root = root->right;
                }
            }
        }

        return ans;
    }
};