/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};
*/

class Solution
{
public:
    Node *ArrayToBST(vector<int> &nums, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }

        // find middle value
        int mid = start + (end - start) / 2;

        // Create Node
        Node *temp = new Node(nums[mid]);

        // Left
        temp->left = ArrayToBST(nums, start, mid - 1);

        // Right
        temp->right = ArrayToBST(nums, mid + 1, end);

        return temp;
    }

    Node *sortedArrayToBST(vector<int> &nums)
    {
        return ArrayToBST(nums, 0, nums.size() - 1);
    }
};