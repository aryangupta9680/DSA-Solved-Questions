#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class Dequeue
{
    Node *front, *rear;

public:
    Dequeue()
    {
        front = rear = NULL;
    }

    void push_front(int x)
    {
        if (front == NULL)
        {
            front = rear = new Node(x);
            cout << "Pushed " << x << " in front of dequeue" << endl;
            return;
        }
        else
        {
            Node *temp = new Node(x);
            temp->next = front;
            front->prev = temp;
            front = temp;
            cout << "Pushed " << x << " in front of dequeue" << endl;
            return;
        }
    }

    void push_back(int x)
    {
        if (front == NULL)
        {
            front = rear = new Node(x);
            cout << "Pushed " << x << " in back of dequeue" << endl;
            return;
        }
        else
        {
            Node *temp = new Node(x);
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
            cout << "Pushed " << x << " in back of dequeue" << endl;
            return;
        }
    }

    void pop_front()
    {
        if (front == NULL)
        {
            cout << "Dequeue Underflow" << endl;
            return;
        }

        else
        {
            Node *temp = front;
            cout << "Popped " << temp->data << " from front" << endl;
            front = front->next;
            delete temp;
            if (front)
            {
                front->prev = NULL;
            }
            else
            {
                rear = NULL;
            }
        }
    }

    void pop_back()
    {
        if (front == NULL)
        {
            cout << "Dequeue Underflow" << endl;
            return;
        }

        else
        {
            Node *temp = rear;
            cout << "Popped " << temp->data << " from back" << endl;
            rear = rear->prev;
            delete temp;
            if (rear)
            {
                rear->next = NULL;
            }
            else
            {
                front = NULL;
            }
        }
    }

    int start()
    {
        if (front == NULL)
        {
            return -1;
        }

        else
        {
            return front->data;
        }
    }

    int end()
    {
        if (front == NULL)
        {
            return -1;
        }

        else
        {
            return rear->data;
        }
    }
};

int main()
{
    Dequeue d;
    d.push_back(7);
    d.push_front(3);
    cout << d.end() << endl;
    d.pop_back();
    d.pop_back();
    d.pop_back();

    return 0;
}