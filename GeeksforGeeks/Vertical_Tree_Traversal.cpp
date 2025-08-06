/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
    void find(Node *root, int pos, int &l, int &r)
    {
        if (!root)
        {
            return;
        }

        l = min(l, pos);
        r = max(r, pos);

        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    vector<vector<int>> verticalOrder(Node *root)
    {
        int l = 0, r = 0;
        find(root, 0, l, r);

        vector<vector<int>> positive(r + 1);
        vector<vector<int>> negative(abs(l) + 1);

        queue<Node *> q;
        queue<int> index;

        q.push(root);
        index.push(0);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            int pos = index.front();
            index.pop();

            if (pos >= 0)
            {
                positive[pos].push_back(temp->data);
            }
            else
            {
                negative[abs(pos)].push_back(temp->data);
            }

            if (temp->left)
            {
                q.push(temp->left);
                index.push(pos - 1);
            }

            if (temp->right)
            {
                q.push(temp->right);
                index.push(pos + 1);
            }
        }

        vector<vector<int>> ans;

        for (int i = negative.size() - 1; i >= 0; i--)
        {
            if (!negative[i].empty())
            {
                ans.push_back(negative[i]);
            }
        }

        for (int i = 0; i < positive.size(); i++)
        {
            if (!positive[i].empty())
            {
                ans.push_back(positive[i]);
            }
        }

        return ans;
    }
};