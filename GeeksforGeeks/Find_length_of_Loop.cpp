/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return false; // Loop doesn't exist
        }

        Node *slow = head, *fast = head;

        // detect the loop
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
            {
                break; // loop exist
            }
        }

        if (fast == NULL || fast->next == NULL)
        {
            return false; // loop doesn't exist
        }

        int count = 1;
        slow = fast->next;

        while (slow != fast)
        {
            count++;
            slow = slow->next;
        }

        return count;
    }
};