#include <stack>

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int ans = 0;
    int index;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            index = st.top();
            st.pop();
            if (!st.empty())
            {
                ans = max(ans, heights[index] * (i - st.top() - 1));
            }
            else
            {
                ans = max(ans, heights[index] * i);
            }
        }

        st.push(i);
    }

    while (!st.empty())
    {
        index = st.top();
        st.pop();
        if (!st.empty())
        {
            ans = max(ans, heights[index] * (n - st.top() - 1));
        }
        else
        {
            ans = max(ans, heights[index] * n);
        }
    }

    return ans;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix, int n, int m)
{
    int ans = 0;
    n = matrix.size();
    m = matrix[0].size();
    vector<int> heights(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                heights[j] = 0;
            }
            else
            {
                heights[j]++;
            }
        }

        ans = max(ans, largestRectangleArea(heights));
    }

    return ans;
}