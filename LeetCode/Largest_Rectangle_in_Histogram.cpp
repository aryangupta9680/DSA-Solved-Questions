// Method 1:
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        // next smallest right
        vector<int> right(n);
        // next smallest left
        vector<int> left(n);

        // find next smallest right
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                right[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        // stack ko empty karo
        while (!st.empty())
        {
            right[st.top()] = n;
            st.pop();
        }

        // find next smallest left
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                left[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        // stack ko empty karo
        while (!st.empty())
        {
            left[st.top()] = -1;
            st.pop();
        }

        // calculate area
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }

        return ans;
    }
};





// Method 2:
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
};