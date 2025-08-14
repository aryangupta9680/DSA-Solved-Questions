// Method 1:
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Box
{
public:
    bool BST;
    int size;
    int max, min;
    Box(int data)
    {
        BST = 1;
        size = 1;
        min = data;
        max = data;
    }
};

class Solution
{
public:
    Box *find(Node *root, int &Totalsize)
    {
        // Leaf Node
        if (!root->left && !root->right)
        {
            Totalsize = max(Totalsize, 1);
            return new Box(root->data);
        }

        // only Right side exists
        else if (!root->left && root->right)
        {
            Box *head = find(root->right, Totalsize);

            if (head->BST && head->min > root->data)
            {
                head->size++;
                head->min = root->data;
                Totalsize = max(Totalsize, head->size);
                return head;
            }

            else
            {
                head->BST = 0;
                return head;
            }
        }

        // only left side exists
        else if (root->left && !root->right)
        {
            Box *head = find(root->left, Totalsize);

            if (head->BST && head->max < root->data)
            {
                head->size++;
                head->max = root->data;
                Totalsize = max(Totalsize, head->size);
                return head;
            }

            else
            {
                head->BST = 0;
                return head;
            }
        }

        // Both side exists
        else
        {
            Box *Lefthead = find(root->left, Totalsize);
            Box *Righthead = find(root->right, Totalsize);

            if (Lefthead->BST && Righthead->BST && Lefthead->max < root->data && Righthead->min > root->data)
            {
                Box *head = new Box(root->data);
                head->size += Lefthead->size + Righthead->size;
                head->min = Lefthead->min;
                head->max = Righthead->max;
                Totalsize = max(Totalsize, head->size);
                return head;
            }

            else
            {
                Lefthead->BST = 0;
                return Lefthead;
            }
        }
    }

    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        int Totalsize = 0;
        find(root, Totalsize);
        return Totalsize;
    }
};






// Method 2:
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Box
{
public:
    bool BST;
    int size;
    int max, min;
    Box()
    {
        BST = 1;
        size = 0;
        min = INT_MAX;
        max = INT_MIN;
    }
};

class Solution
{
public:
    Box *find(Node *root, int &Totalsize)
    {
        // root doesn't exist
        if (!root)
        {
            return new Box();
        }

        // root exists
        Box *Lefthead = find(root->left, Totalsize);
        Box *Righthead = find(root->right, Totalsize);

        if (Lefthead->BST && Righthead->BST && Lefthead->max < root->data && Righthead->min > root->data)
        {
            Box *head = new Box();
            head->size = Lefthead->size + Righthead->size + 1;
            head->min = min(root->data, Lefthead->min);
            head->max = max(root->data, Righthead->max);
            Totalsize = max(Totalsize, head->size);
            return head;
        }
        else
        {
            Lefthead->BST = 0;
            return Lefthead;
        }
    }

    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        int Totalsize = 0;
        find(root, Totalsize);
        return Totalsize;
    }
};