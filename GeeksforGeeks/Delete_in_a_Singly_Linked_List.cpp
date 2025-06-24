// First Method:
/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    /* Function to delete a node from a linked list */
    Node *deleteNode(Node *head, int x)
    {
        if (x == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        x--;

        Node *curr = head;
        Node *prev = NULL;
        while (x--)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;

        return head;
    }
};



// Second Method: using recursion
/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    /* Function to delete a node from a linked list */
    Node *deleteNode(Node *curr, int x)
    {
        // base case
        if (x == 1)
        {
            Node *temp = curr->next;
            delete curr;
            return temp;
        }

        curr->next = deleteNode(curr->next, x - 1);
        return curr;
    }
};