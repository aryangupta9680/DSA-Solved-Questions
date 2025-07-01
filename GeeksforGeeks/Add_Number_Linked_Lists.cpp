/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    // Reverse a Linked List
    Node *Reverse(Node *curr, Node *prev)
    {
        // base case
        if (curr == NULL)
        {
            return prev;
        }

        Node *front = curr->next;
        curr->next = prev;

        return Reverse(front, curr);
    }

    Node *addTwoLists(Node *num1, Node *num2)
    {
        num1 = Reverse(num1, NULL);
        num2 = Reverse(num2, NULL);

        Node *curr1 = num1, *curr2 = num2;
        Node *head = new Node(0);
        Node *tail = head;
        int carry = 0;
        int sum;

        while (curr1 && curr2)
        {
            // addition
            sum = curr1->data + curr2->data + carry;
            tail->next = new Node(sum % 10);
            tail = tail->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
            carry = sum / 10;
        }

        // curr1 exist to nahi karta
        while (curr1)
        {
            sum = curr1->data + carry;
            tail->next = new Node(sum % 10);
            tail = tail->next;
            curr1 = curr1->next;
            carry = sum / 10;
        }

        // curr2 exist to nahi karta
        while (curr2)
        {
            sum = curr2->data + carry;
            tail->next = new Node(sum % 10);
            tail = tail->next;
            curr2 = curr2->next;
            carry = sum / 10;
        }

        // carry remaining ho
        while (carry)
        {
            tail->next = new Node(carry % 10);
            tail = tail->next;
            carry /= 10;
        }

        head = Reverse(head->next, NULL);

        while (head->next && head->data == 0)
        {
            Node *nextNode = head->next;
            delete head;
            head = nextNode;
        }

        return head;
    }
};