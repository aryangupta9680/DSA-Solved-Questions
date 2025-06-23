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
    // Node A1(4);

    Node *Head;
    Head = new Node(4);
    cout << Head->data << endl;
    cout << Head->next << endl;
    return 0;
}