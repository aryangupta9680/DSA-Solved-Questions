/* Node is as follows:

struct Node
{
    int data, height;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

*/
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

Node *deleteNode(Node *root, int key)
{
    if (!root)
    {
        return NULL;
    }

    // left side
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }

    // Right side
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }

    else
    {
        // Leaf Node
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }

        // Only one child exists
        else if (root->left && !root->right) // left child exists
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        else if (!root->left && root->right) // right child exists
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // Both child exists
        else
        {
            // right side smallest element
            Node *curr = root->right;
            while (curr->left)
            {
                curr = curr->left;
            }

            root->data = curr->data;
            root->right = deleteNode(root->right, curr->data);
        }
    }

    // update the height
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // check balance
    int balance = getbalance(root);

    // left side
    if (balance > 1)
    {
        // LL
        if (getbalance(root->left) >= 0)
        {
            return rightRotation(root);
        }

        // LR
        else
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }

    // right side
    else if (balance < -1)
    {
        // RR
        if (getbalance(root->right) <= 0)
        {
            return leftRotation(root);
        }

        // RL
        else
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }

    else
    {
        return root;
    }
}