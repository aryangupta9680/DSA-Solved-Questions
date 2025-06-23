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
    Node *Head;
    Head = NULL;
    int arr[] = {2, 4, 6, 8, 10};

    // Insert node at the beginning

    for (int i = 0; i < 5; i++)
    {
        // Linked list does not exist
        if (Head == NULL)
        {
            Head = new Node(arr[i]);
        }
        // Linked list exist
        else
        {
            Node *temp;
            temp = new Node(arr[i]);
            temp->next = Head;
            Head = temp;
        }
    }

    // First method to print the value
    // Node *temp = Head;
    // while (temp != NULL)
    // {
    //     cout << temp->data << endl;
    //     temp = temp->next;
    // }

    // Second method to print the value
    Node *temp = Head;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    return 0;
}