// First Method
/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
public:
    // Function to check if the linked list has a loop.

    bool check(vector<Node *> &visited, Node *curr)
    {
        for (int i = 0; i < visited.size(); i++)
        {
            if (visited[i] == curr)
            {
                return 1;
            }
        }

        return 0;
    }

    bool detectLoop(Node *head)
    {
        Node *curr = head;
        vector<Node *> visited;

        // Traverse the node
        while (curr != NULL)
        {
            // check node is already visited or not
            if (check(visited, curr))
            {
                return 1; // loop exist
            }

            visited.push_back(curr);
            curr = curr->next;
        }

        return 0; // loop doesn't exist
    }
};



// Second Method: using unordered map
/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node *head)
    {
        Node *curr = head;
        unordered_map<Node *, bool> visited;

        // Traverse the node
        while (curr != NULL)
        {
            // check node is already visited or not
            if (visited[curr] == 1)
            {
                return 1; // loop exist
            }

            visited[curr] = 1;
            curr = curr->next;
        }

        return 0; // loop doesn't exist
    }
};



// Method 3: using slow and fast pointer concept
/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node *head)
    {
        Node *slow = head, *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
            {
                return 1; // loop exist
            }
        }

        return 0; // loop doesn't exist
    }
};
