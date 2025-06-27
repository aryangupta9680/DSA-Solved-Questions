// doubly linked list

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

int main()
{
    Node *head = NULL;

    // Insert at start
    // Linked List doesn't exist
    if (head == NULL)
    {
        head = new Node(5);
    }

    // Linked List exist
    else
    {
        Node *temp = new Node(5);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    // print the value
    Node *trav = head;
    while (trav)
    {
        cout << trav->data << endl;
        trav = trav->next;
    }

    return 0;
}