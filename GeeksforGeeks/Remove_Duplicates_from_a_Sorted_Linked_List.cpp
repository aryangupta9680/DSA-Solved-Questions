// First Method:
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution
{
public:
    // Function to remove duplicates from sorted linked list.
    Node *removeDuplicates(Node *head)
    {
        // First Method:
        vector<int> ans;
        ans.push_back(head->data);
        Node *curr = head->next;
        while (curr)
        {
            if (ans[ans.size() - 1] != curr->data)
            {
                ans.push_back(curr->data);
            }

            curr = curr->next;
        }

        curr = head;
        int index = 0;
        Node *prev = NULL;
        while (index < ans.size())
        {
            curr->data = ans[index];
            index++;
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;
        return head;
    }
};



// Second Method:
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution
{
public:
    // Function to remove duplicates from sorted linked list.
    Node *removeDuplicates(Node *head)
    {
        // Second Method:
        Node *curr = head->next, *prev = head;
        while (curr)
        {
            if (curr->data == prev->data)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else
            {
                prev = prev->next;
                curr = curr->next;
            }
        }

        return head;
    }
};
