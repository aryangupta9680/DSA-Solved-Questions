// First Method
/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution
{
public:
    Node *find(Node *curr1, Node *curr2, Node *x)
    {
        if (x == NULL)
        {
            return NULL;
        }

        while (curr1 != x)
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return curr2;
    }

    Node *cloneLinkedList(Node *head)
    {
        Node *headCopy = new Node(0);
        Node *tailCopy = headCopy;
        Node *temp = head;
        while (temp)
        {
            tailCopy->next = new Node(temp->data);
            tailCopy = tailCopy->next;
            temp = temp->next;
        }

        tailCopy = headCopy;
        headCopy = headCopy->next;
        delete tailCopy;

        // for random pointer
        tailCopy = headCopy;
        temp = head;
        while (temp)
        {
            tailCopy->random = find(head, headCopy, temp->random);
            tailCopy = tailCopy->next;
            temp = temp->next;
        }

        return headCopy;
    }
};



// Second Method:
/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution
{
public:
    // second method:
    Node *cloneLinkedList(Node *head)
    {
        Node *headCopy = new Node(0);
        Node *tailCopy = headCopy;
        Node *temp = head;

        while (temp)
        {
            tailCopy->next = new Node(temp->data);
            tailCopy = tailCopy->next;
            temp = temp->next;
        }

        tailCopy = headCopy;
        headCopy = headCopy->next;
        delete tailCopy;

        tailCopy = headCopy;
        temp = head;

        unordered_map<Node *, Node *> m;
        // fill the value inside map
        while (temp)
        {
            m[temp] = tailCopy;
            temp = temp->next;
            tailCopy = tailCopy->next;
        }

        // assign random pointer to clone Linked List
        tailCopy = headCopy;
        temp = head;

        while (temp)
        {
            tailCopy->random = m[temp->random];
            tailCopy = tailCopy->next;
            temp = temp->next;
        }

        return headCopy;
    }
};



// Third Method:
/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution
{
public:
    // third method:
    Node *cloneLinkedList(Node *head)
    {
        Node *headCopy = new Node(0);
        Node *tailCopy = headCopy;
        Node *temp = head;

        while (temp)
        {
            tailCopy->next = new Node(temp->data);
            tailCopy = tailCopy->next;
            temp = temp->next;
        }

        tailCopy = headCopy;
        headCopy = headCopy->next;
        delete tailCopy;

        tailCopy = headCopy;
        temp = head;

        Node *curr1 = head, *curr2 = headCopy;
        Node *front1, *front2;

        while (curr1)
        {
            front1 = curr1->next;
            front2 = curr2->next;
            curr1->next = curr2;
            curr2->next = front1;
            curr1 = front1;
            curr2 = front2;
        }

        curr1 = head;
        while (curr1)
        {
            curr2 = curr1->next;
            if (curr1->random)
            {
                curr2->random = curr1->random->next;
            }

            curr1 = curr2->next;
        }

        curr1 = head;
        while (curr1->next)
        {
            front1 = curr1->next;
            curr1->next = front1->next;
            curr1 = front1;
        }

        return headCopy;
    }
};