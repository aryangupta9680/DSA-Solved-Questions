/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

// Function to push an element into the queue.
void MyQueue::push(int x)
{
    if (front == NULL)
    {
        front = new QueueNode(x);
        rear = front;
        return;
    }

    else
    {
        rear->next = new QueueNode(x);
        if (rear->next == NULL)
        {
            return;
        }

        rear = rear->next;
    }
}

// Function to pop front element from the queue.
int MyQueue ::pop()
{
    if (front == NULL)
    {
        return -1;
    }

    else
    {
        int element = front->data;
        QueueNode *temp = front;
        front = front->next;
        delete temp;
        return element;
    }
}
