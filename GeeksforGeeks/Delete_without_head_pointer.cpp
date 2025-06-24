/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/

class Solution
{
public:
    // Function to delete a node without any reference to the head pointer.
    void deleteNode(Node *curr)
    {
        Node *temp = curr->next;
        curr->data = temp->data;
        curr->next = temp->next;
        delete temp;
    }
};