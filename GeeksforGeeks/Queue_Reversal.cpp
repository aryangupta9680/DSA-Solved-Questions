// function Template for C++

class Solution
{
public:
    queue<int> reverseQueue(queue<int> &q)
    {
        stack<int> st;

        // Empty the queue
        while (!q.empty())
        {
            st.push(q.front());
            q.pop();
        }

        // Empty the stack
        while (!st.empty())
        {
            q.push(st.top());
            st.pop();
        }

        return q;
    }
};