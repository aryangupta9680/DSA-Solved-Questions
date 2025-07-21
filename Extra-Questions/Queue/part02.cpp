#include <iostream>
using namespace std;

// Implement Queue using Circular Array (Circular Queue)
class Queue
{
    int *arr;
    int front, rear;
    int size;

public:
    // Constructor
    Queue(int n)
    {
        arr = new int[n];
        front = rear = -1;
        size = n;
    }

    // If Queue is empty or not
    bool IsEmpty()
    {
        return front == -1;
    }

    // If Queue is full or not
    bool IsFull()
    {
        return (rear + 1) % size == front;
    }

    // Push element into Queue
    void push(int x)
    {
        // Empty
        if (IsEmpty())
        {
            cout << "Pushed " << x << " into the Queue." << endl;
            front = rear = 0;
            arr[0] = x;
            return;
        }

        // Full
        else if (IsFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }

        // Insert
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = x;
            cout << "Pushed " << x << " into the Queue." << endl;
        }
    }

    // Pop element from Queue
    void pop()
    {
        // Empty
        if (IsEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }

        // pop
        else
        {
            if (front == rear)
            {
                cout << "Popped " << arr[front] << " from the Queue." << endl;
                front = rear = -1;
            }
            else
            {
                cout << "Popped " << arr[front] << " from the Queue." << endl;
                front = (front + 1) % size;
            }
        }
    }

    // starting mein konsa element rakha hai
    int start()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
};

int main()
{
    Queue q(5);
    q.push(5);
    q.push(2);
    q.push(98);
    q.push(29);
    q.pop();
    q.push(47);
    q.push(27);
    q.pop();

    return 0;
}