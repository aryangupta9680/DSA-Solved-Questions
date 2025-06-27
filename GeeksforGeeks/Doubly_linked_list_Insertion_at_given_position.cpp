/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution
{
public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data)
    {
        if (pos == 0)
        {
            // Linked List does not exist
            if (head == NULL)
            {
                head = new Node(data);
            }

            // Linked List exist
            else
            {
                Node *temp = new Node(data);
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
        }
        else
        {
            Node *curr = head;
            // go to the node after which I have to insert
            while (pos--)
            {
                curr = curr->next;
            }

            // insert at end
            if (curr->next == NULL) // Last Node
            {
                Node *temp = new Node(data);
                temp->prev = curr;
                curr->next = temp;
            }

            // Insert at middle
            else
            {
                Node *temp = new Node(data);
                temp->next = curr->next;
                temp->prev = curr;
                curr->next = temp;
                temp->next->prev = temp;
            }
        }

        return head;
    }
};