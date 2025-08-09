#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

Node *insert(Node *root, int target)
{
    // base case
    if (!root)
    {
        Node *temp = new Node(target);
        return temp;
    }

    if (target < root->data)
    {
        root->left = insert(root->left, target);
    }

    else
    {
        root->right = insert(root->right, target);
    }

    return root;
}

void inorder(Node *root)
{
    if (!root)
    {
        return;
    }

    // left side
    inorder(root->left);

    // Node
    cout << root->data << " ";

    // right side
    inorder(root->right);
}

int main()
{
    int arr[] = {6, 7, 4, 1, 3, 8};
    Node *root = NULL;

    // Insertion
    for (int i = 0; i < 6; i++)
    {
        root = insert(root, arr[i]);
    }

    // Traverse
    inorder(root);

    return 0;
}