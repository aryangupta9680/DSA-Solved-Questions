class Geeks
{
public:
    // Function to insert element to stack
    void insert(stack<int> &st, int x)
    {
        st.push(x);
    }

    // Function to pop element from stack
    void remove(stack<int> &st)
    {
        if (!st.empty())
        {
            st.pop();
        }
    }

    void headOf_Stack(stack<int> &st)
    {
        if (!st.empty())
        {
            cout << st.top() << endl;
        }
    }

    // Function to find the element in stack, print Yes,if found, else print No.

    void find(stack<int> &st, int val)
    {
        stack<int> temp = st;
        while (!temp.empty())
        {
            if (temp.top() == val)
            {
                cout << "Yes" << endl;
                return;
            }

            temp.pop();
        }

        cout << "No" << endl;
    }
};