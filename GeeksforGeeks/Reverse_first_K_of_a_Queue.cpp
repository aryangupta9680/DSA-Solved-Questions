class Solution
{
public:
    queue<int> reverseFirstK(queue<int> q, int k)
    {
        if (q.size() < k)
        {
            return q;
        }

        stack<int> st;

        // push first k elements of queue into stack
        for (int i = 0; i < k; i++)
        {
            st.push(q.front());
            q.pop();
        }

        // store the size of queue
        int n = q.size();

        // push all elements of stack into queue
        while (!st.empty())
        {
            q.push(st.top());
            st.pop();
        }

        // push first n elements of queue at last
        while (n--)
        {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};