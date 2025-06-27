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

Node *CreateDLL(int arr[], int index, int size, Node *back)
{
    // base condition
    if (index == size)
    {
        return NULL;
    }

    Node *temp = new Node(arr[index]);
    temp->prev = back;
    temp->next = CreateDLL(arr, index + 1, size, temp);
    return temp;
};

int main()
{
    Node *head = NULL;

    // Create doubly linked list using recursion
    int arr[] = {1, 2, 3, 4, 5};
    head = CreateDLL(arr, 0, 5, NULL);

    // Insert at any given position
    int pos = 2; // given
    // insert at start
    if (pos == 0)
    {
        // Linked List does not exist
        if (head == NULL)
        {
            head = new Node(10);
        }

        // Linked List exist
        else
        {
            Node *temp = new Node(10);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    else
    {
        Node *curr = head;
        // go to the node after which I have to insert
        while (--pos)
        {
            curr = curr->next;
        }

        // insert at end
        if (curr->next == NULL) // Last Node
        {
            Node *temp = new Node(10);
            temp->prev = curr;
            curr->next = temp;
        }

        // Insert at middle
        else
        {
            Node *temp = new Node(10);
            temp->next = curr->next;
            temp->prev = curr;
            curr->next = temp;
            temp->next->prev = temp;
        }
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