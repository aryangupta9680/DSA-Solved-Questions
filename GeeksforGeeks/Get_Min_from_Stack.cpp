// Method 1:
class Solution
{
public:
    stack<int> st1; // Original
    stack<int> st2; // Minimum

    Solution() {}

    // Add an element to the top of Stack
    void push(int x)
    {
        if (st1.empty())
        {
            st1.push(x);
            st2.push(x);
        }
        else
        {
            st1.push(x);
            st2.push(min(x, st2.top()));
        }
    }

    // Remove the top element from the Stack
    void pop()
    {
        if (st1.empty())
        {
            return;
        }
        else
        {
            st1.pop();
            st2.pop();
        }
    }

    // Returns top element of the Stack
    int peek()
    {
        if (st1.empty())
        {
            return -1;
        }
        else
        {
            return st1.top();
        }
    }

    // Finds minimum element of Stack
    int getMin()
    {
        if (st2.empty())
        {
            return -1;
        }
        else
        {
            return st2.top();
        }
    }
};