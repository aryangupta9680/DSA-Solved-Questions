#include <iostream>
using namespace std;

// Implement Queue using Array
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
        return rear == size - 1;
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
            rear = rear + 1;
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
                front = front + 1;
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
    q.push(47);
    q.push(39);
    q.pop();
    q.pop();
    q.pop();
    // cout << q.start() << endl;
    int a = q.start();
    if (!q.IsEmpty())
    {
        cout << a << endl;
    }

    return 0;
}