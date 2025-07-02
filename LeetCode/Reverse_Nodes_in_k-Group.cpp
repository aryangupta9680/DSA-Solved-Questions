/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // create dummy node
        ListNode *first = new ListNode(0);
        first->next = head;
        head = first;
        int x;
        ListNode *second, *prev, *curr, *front;

        while (first->next)
        {
            ListNode *temp = first;
            x = k;
            while (x && temp->next)
            {
                temp = temp->next;
                x--;
            }
            if (x)
            {
                break; // not enough nodes to reverse
            }

            x = k;
            second = first->next;
            prev = first;
            curr = first->next;

            while (x && curr)
            {
                front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
                x--;
            }

            first->next = prev;
            second->next = curr;
            first = second;
        }

        first = head;
        head = head->next;
        delete first;
        return head;
    }
};