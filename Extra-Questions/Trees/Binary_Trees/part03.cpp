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

void PreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

Node *BinaryTree()
{
    int x;
    cin >> x;

    if (x == -1)
    {
        return NULL;
    }

    Node *temp = new Node(x);

    // left side
    cout << "Enter the left child of " << x << ": ";
    temp->left = BinaryTree();

    // right side
    cout << "Enter the right child of " << x << ": ";
    temp->right = BinaryTree();

    return temp;
}

int main()
{
    // Create Tree
    cout << "Enter the root Node: ";
    Node *root;
    root = BinaryTree();

    // Tree Traversal
    // PreOrder Print
    cout << "PreOrder: ";
    PreOrder(root);
    cout << endl;

    // InOrder Print
    cout << "InOrder: ";
    InOrder(root);
    cout << endl;

    // PostOrder Print
    cout << "PostOrder: ";
    PostOrder(root);
    cout << endl;

    return 0;
}