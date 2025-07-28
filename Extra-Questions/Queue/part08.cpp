#include <iostream>
using namespace std;

class Dequeue
{
    int front, rear, size;
    int *arr;

public:
    Dequeue(int n)
    {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    bool IsEmpty()
    {
        return front == -1;
    }

    bool IsFull()
    {
        return (rear + 1) % size == front;
    }

    void push_front(int x)
    {
        if (IsEmpty())
        {
            front = rear = 0;
            cout << "Pushed " << x << " in front" << endl;
            arr[0] = x;
            return;
        }

        else if (IsFull())
        {
            cout << "Dequeue Overflow" << endl;
            return;
        }

        else
        {
            front = (front - 1 + size) % size;
            arr[front] = x;
            cout << "Pushed " << x << " in front" << endl;
            return;
        }
    }

    void push_back(int x)
    {
        if (IsEmpty())
        {
            front = rear = 0;
            cout << "Pushed " << x << " in back" << endl;
            arr[0] = x;
            return;
        }

        else if (IsFull())
        {
            cout << "Dequeue Overflow" << endl;
            return;
        }

        else
        {
            rear = (rear + 1) % size;
            arr[rear] = x;
            cout << "Pushed " << x << " in back" << endl;
            return;
        }
    }

    void pop_front()
    {
        if (IsEmpty())
        {
            cout << "Dequeue Underflow" << endl;
            return;
        }

        else
        {
            cout << "Popped " << arr[front] << " from dequeue" << endl;
            // single element
            if (front == rear)
            {
                front = rear = -1;
            }

            // greater than 1 element
            else
            {
                front = (front + 1) % size;
            }
        }
    }

    void pop_back()
    {
        if (IsEmpty())
        {
            cout << "Dequeue Underflow" << endl;
            return;
        }

        else
        {
            cout << "Popped " << arr[rear] << " from dequeue" << endl;
            // single element
            if (front == rear)
            {
                front = rear = -1;
            }

            // greater than 1 element
            else
            {
                rear = (rear - 1 + size) % size;
            }
        }
    }

    int start()
    {
        if (IsEmpty())
        {
            return -1;
        }

        else
        {
            return arr[front];
        }
    }

    int end()
    {
        if (IsEmpty())
        {
            return -1;
        }

        else
        {
            return arr[rear];
        }
    }
};

int main()
{
    Dequeue d(5);
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(40);
    d.pop_back();
    d.pop_front();
    cout << d.start() << endl;
    cout << d.end() << endl;

    return 0;
}