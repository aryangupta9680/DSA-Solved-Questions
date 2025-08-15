#include <iostream>
using namespace std;

class Node
{
public:
    int data, height;
    Node *left, *right;
    Node(int value)
    {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

int getheight(Node *root)
{
    if (!root)
    {
        return 0;
    }

    return root->height;
}

int getbalance(Node *root)
{
    return getheight(root->left) - getheight(root->right);
}

// Right Rotation
Node *rightRotation(Node *root)
{
    Node *child = root->left;
    Node *childRight = child->right;
    child->right = root;
    root->left = childRight;

    // update height
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    return child;
}

// Left Rotation
Node *leftRotation(Node *root)
{
    Node *child = root->right;
    Node *childLeft = child->left;
    child->left = root;
    root->right = childLeft;

    // update height
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    return child;
}

Node *insert(Node *root, int key)
{
    // doesn't exists
    if (!root)
    {
        return new Node(key);
    }

    // exists
    if (key < root->data) // left side
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data) // right side
    {
        root->right = insert(root->right, key);
    }
    else
    {
        return root; // Duplicates elements are not allowed
    }

    // update height
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // Balancing check
    int balance = getbalance(root);

    // Left Left case
    if (balance > 1 && key < root->left->data)
    {
        return rightRotation(root);
    }

    // Right Right case
    else if (balance < -1 && root->right->data < key)
    {
        return leftRotation(root);
    }

    // Left Right case
    else if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // Right Left case
    else if (balance < -1 && root->right->data > key)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    // No unbalancing case
    else
    {
        return root;
    }
}

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

int main()
{
    // Duplicates elements are not allowed
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);

    cout << "Preorder: " << endl;
    PreOrder(root);

    cout << endl;

    cout << "Inorder: " << endl;
    InOrder(root);

    return 0;
}