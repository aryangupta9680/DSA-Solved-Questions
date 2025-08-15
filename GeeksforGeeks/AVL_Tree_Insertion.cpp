/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution
{
public:
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

    /*You are required to complete this method */
    Node *insertToAVL(Node *root, int key)
    {
        // doesn't exists
        if (!root)
        {
            return new Node(key);
        }

        // exists
        if (key < root->data) // left side
        {
            root->left = insertToAVL(root->left, key);
        }
        else if (key > root->data) // right side
        {
            root->right = insertToAVL(root->right, key);
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
};