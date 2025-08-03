// Method 1:
/* A binary tree node

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
    vector<int> leftView(Node *root)
    {
        vector<int> ans;

        if (!root)
        {
            return ans;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            ans.push_back(q.front()->data);

            while (n--)
            {
                Node *temp = q.front();
                q.pop();
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }

        return ans;
    }
};




// Method 2
/* A binary tree node

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
    void Lview(Node *root, int level, vector<int> &ans)
    {
        if (!root)
        {
            return;
        }

        if (level == ans.size())
        {
            ans.push_back(root->data);
        }

        Lview(root->left, level + 1, ans);
        Lview(root->right, level + 1, ans);
    }

    vector<int> leftView(Node *root)
    {
        vector<int> ans;

        if (!root)
        {
            return ans;
        }

        Lview(root, 0, ans);

        return ans;
    }
};