// First Method:
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        // Detect the loop
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        Node *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                break;
            }
        }

        if (fast == NULL || fast->next == NULL)
        {
            return;
        }

        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        while (slow->next != fast)
        {
            slow = slow->next;
        }

        slow->next = NULL;
    }
};

/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/




// Second Method
class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        // Second Method:
        // Detect the loop
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        Node *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                break;
            }
        }

        if (fast == NULL || fast->next == NULL)
        {
            return;
        }

        // Find length of loop
        slow = fast->next;
        int count = 1;
        while (slow != fast)
        {
            count++;
            slow = slow->next;
        }

        slow = head, fast = head;

        while (count--)
        {
            fast = fast->next;
        }

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // bring slow to last node
        while (slow->next != fast)
        {
            slow = slow->next;
        }

        slow->next = NULL;
    }
};