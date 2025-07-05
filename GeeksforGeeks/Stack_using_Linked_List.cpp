class MyStack
{
private:
    StackNode *top;

public:
    void push(int x)
    {
        StackNode *temp = new StackNode(x);
        if (temp == NULL)
        {
            return;
        }
        else
        {
            temp->next = top;
            top = temp;
        }
    }

    int pop()
    {
        if (top == NULL)
        {
            return -1;
        }
        else
        {
            int value = top->data;
            StackNode *temp = top;
            top = top->next;
            delete temp;
            return value;
        }
    }

    MyStack() { top = NULL; }
};