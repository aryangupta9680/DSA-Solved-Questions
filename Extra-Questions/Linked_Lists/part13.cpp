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

    // Delete at start
    if (head != NULL)
    {
        // if only one node exist
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }

        // if more than one node exist
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            head->prev = NULL;
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