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

Node *CreateLinkedList(int arr[], int index, int size)
{
    // Base Case
    if (index == size)
    {
        return NULL;
    }

    Node *temp;
    temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr, index + 1, size);
    return temp;
}

int main()
{
    Node *Head = NULL;
    int arr[] = {2, 4, 6, 8, 10};

    // Insert value at the end of linked list using Recursion
    Head = CreateLinkedList(arr, 0, 5);

    // Print the value
    Node *temp;
    temp = Head;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    return 0;
}