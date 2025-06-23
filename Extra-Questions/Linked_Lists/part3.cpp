#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

int main()
{
    Node *Head = NULL;
    Node *Tail = NULL;
    int arr[] = {2, 4, 6, 8, 10};

    // Insert value at the end of linked list
    for (int i = 0; i < 5; i++)
    {
        // Linked List is empty
        if (Head == NULL)
        {
            Head = new Node(arr[i]);
            Tail = Head;
        }
        // Linked List exist
        else
        {
            Tail->next = new Node(arr[i]);
            Tail = Tail->next;
        }
    }

    Node *temp;
    temp = Head;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    return 0;
}