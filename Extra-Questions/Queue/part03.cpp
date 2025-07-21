#include <iostream>
using namespace std;

// Implement Queue using Linked Lists
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

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    // if Queue is empty or not
    bool IsEmpty()
    {
        return front == NULL;
    }

    // Pushed element into Queue
    void push(int x)
    {
        if (IsEmpty())
        {
            cout << "Pushed " << x << " into the Queue." << endl;
            front = new Node(x);
            rear = front;
            return;
        }

        else
        {
            rear->next = new Node(x);
            if (rear->next == NULL)
            {
                cout << "Queue Overflow" << endl;
                return;
            }

            cout << "Pushed " << x << " into the Queue." << endl;
            rear = rear->next;
        }
    }

    // Popped element from Queue
    void pop()
    {
        if (IsEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }

        else
        {
            cout << "Popped " << front->data << " from the Queue." << endl;
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    int start()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        else
        {
            return front->data;
        }
    }
};

int main()
{
    Queue q;
    q.push(5);
    q.push(48);
    q.push(92);
    q.push(34);
    q.pop();
    q.pop();
    cout << q.start() << endl;

    return 0;
}