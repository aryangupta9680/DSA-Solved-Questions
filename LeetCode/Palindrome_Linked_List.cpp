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
    bool isPalindrome(ListNode *head)
    {
        if (head->next == NULL)
        {
            return true;
        }

        // count total number of nodes
        ListNode *temp = head;
        int count = 0;
        while (temp)
        {
            count++;
            temp = temp->next;
        }

        count /= 2;
        ListNode *curr = head, *prev = NULL;
        // skip number of nodes
        while (count--)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;

        // Reverse the second linked list and curr is pointing it
        ListNode *front = NULL;
        prev = NULL;

        while (curr)
        {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        // prev is pointing to second linked list
        // head is pointing to first linked list

        ListNode *head1 = head, *head2 = prev;

        // check palindrome
        while (head1)
        {
            if (head1->val != head2->val)
            {
                return false;
            }

            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
    }
};