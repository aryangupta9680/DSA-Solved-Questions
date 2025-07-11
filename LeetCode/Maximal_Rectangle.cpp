class Solution
{
public:
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

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int ans = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> heights(col, 0);

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == '0')
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
};