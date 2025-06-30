// First Method:
// Linked list Node
/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    Node *intersectPoint(Node *head1, Node *head2)
    {
        // count number of nodes
        Node *curr1 = head1, *curr2 = head2;
        int count1 = 0, count2 = 0;

        while (curr1)
        {
            count1++;
            curr1 = curr1->next;
        }

        while (curr2)
        {
            count2++;
            curr2 = curr2->next;
        }

        curr1 = head1;
        curr2 = head2;

        while (count1 > count2)
        {
            count1--;
            curr1 = curr1->next;
        }

        while (count2 > count1)
        {
            count2--;
            curr2 = curr2->next;
        }

        while (curr1 != curr2)
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return curr1;
    }
};





// Second Method:
// Linked list Node
/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    Node *intersectPoint(Node *head1, Node *head2)
    {
        // Second method:
        Node *curr1 = head1;
        while (curr1->next != NULL)
        {
            curr1 = curr1->next;
        }

        curr1->next = head1;

        Node *slow = head2, *fast = head2;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                break;
            }
        }

        slow = head2;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};