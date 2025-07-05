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

class Stack
{
    Node *top;
    int size; // actual size of stack

public:
    bool flag;

    Stack()
    {
        top = NULL;
        size = 0;
        flag = 1;
    }

    // push
    void push(int value)
    {
        Node *temp = new Node(value);
        if (temp == NULL)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        else
        {
            temp->next = top;
            top = temp;
            size++;
            cout << "Pushed " << value << " into the stack" << endl;
            flag = 0;
        }
    }

    // pop
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        else
        {
            Node *temp = top;
            cout << "Popped " << top->data << " from the stack" << endl;
            top = top->next;
            delete temp;
            size--;
            if (top == NULL)
            {
                flag = 1;
            }
        }
    }

    // peek
    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        else
        {
            return top->data;
        }
    }

    // IsEmpty
    bool IsEmpty()
    {
        return top == NULL;
    }

    // IsSize
    int IsSize()
    {
        return size;
    }
};

int main()
{
    Stack S;
    // S.push(8);
    // S.push(7);
    // S.push(5);
    // S.pop();
    S.push(-1);

    // cout << S.IsSize() << endl;

    int value = S.peek();
    if (S.flag == 0)
    {
        cout << value << endl;
    }

    // cout << S.IsEmpty() << endl;

    return 0;
}