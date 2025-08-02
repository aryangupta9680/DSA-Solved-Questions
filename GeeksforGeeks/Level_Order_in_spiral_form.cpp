/* A binary tree node has data, pointer to left child
   and a pointer to right child
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution
{
public:
    vector<int> findSpiral(Node *root)
    {
        stack<Node *> s1; // Right to Left
        stack<Node *> s2; // Left to Right
        vector<int> ans;
        s1.push(root);

        while (!s1.empty() || !s2.empty())
        {
            // Right to Left
            if (!s1.empty())
            {
                while (!s1.empty())
                {
                    Node *temp = s1.top();
                    s1.pop();
                    ans.push_back(temp->data);
                    // Right
                    if (temp->right)
                    {
                        s2.push(temp->right);
                    }
                    // Left
                    if (temp->left)
                    {
                        s2.push(temp->left);
                    }
                }
            }

            // Left to Right
            else
            {
                while (!s2.empty())
                {
                    Node *temp = s2.top();
                    s2.pop();
                    ans.push_back(temp->data);
                    // Left
                    if (temp->left)
                    {
                        s1.push(temp->left);
                    }
                    // Right
                    if (temp->right)
                    {
                        s1.push(temp->right);
                    }
                }
            }
        }

        return ans;
    }
};