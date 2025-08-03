/*
struct Node
{
    int data;
    Node* left;
    Node* right;
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

    vector<int> bottomView(Node *root)
    {
        int l = 0, r = 0;
        find(root, 0, l, r);

        vector<int> ans(r - l + 1);

        queue<Node *> q;
        queue<int> index;
        q.push(root);
        index.push(-1 * l);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            int pos = index.front();
            index.pop();

            ans[pos] = temp->data;

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

        return ans;
    }
};