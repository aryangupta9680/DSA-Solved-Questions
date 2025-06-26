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

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */
class Solution
{
public:
    Node *deleteK(Node *head, int k)
    {
        if (k == 1)
        {
            return NULL;
        }

        Node *curr = head, *prev = NULL;
        int count = 1;

        while (curr != NULL)
        {
            // k==count, delete this node
            if (k == count)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                count = 1;
            }

            // k!=count, skip this node
            else
            {
                prev = curr;
                curr = curr->next;
                count++;
            }
        }

        return head;
    }
};