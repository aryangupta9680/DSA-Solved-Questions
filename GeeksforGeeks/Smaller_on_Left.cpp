class Solution
{
public:
    vector<int> leftSmaller(vector<int> arr)
    {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n, -1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                ans[st.top()] = arr[i];
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};