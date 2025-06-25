// First Method:
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
    ListNode *reverseList(ListNode *head)
    {
        vector<int> ans;
        ListNode *temp = head;
        while (temp != NULL)
        {
            ans.push_back(temp->val);
            temp = temp->next;
        }

        int i = ans.size() - 1;
        temp = head;
        while (temp != NULL)
        {
            temp->val = ans[i];
            i--;
            temp = temp->next;
        }

        return head;
    }
};



// Second Method:
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head, *prev = NULL, *fut = NULL;
        while (curr)
        {
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        head = prev;
        return head;
    }
};



// Third Method:
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
    ListNode *Reverse(ListNode *curr, ListNode *prev)
    {
        // base case
        if (curr == NULL)
        {
            return prev;
        }

        ListNode *fut = curr->next;
        curr->next = prev;
        return Reverse(fut, curr);
    }

    ListNode *reverseList(ListNode *head)
    {
        return Reverse(head, NULL);
    }
};
