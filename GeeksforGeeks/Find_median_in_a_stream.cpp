class Solution
{
public:
    priority_queue<int> LeftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> RightMinHeap;

    void InsertHeap(int &x)
    {
        if (LeftMaxHeap.empty())
        {
            LeftMaxHeap.push(x);
            return;
        }

        if (x > LeftMaxHeap.top())
        {
            RightMinHeap.push(x);
        }
        else
        {
            LeftMaxHeap.push(x);
        }

        balanceHeaps();
    }

    void balanceHeaps()
    {
        // Min heap (Right side) size should not be greater than Max heap (left side)
        if (RightMinHeap.size() > LeftMaxHeap.size())
        {
            LeftMaxHeap.push(RightMinHeap.top());
            RightMinHeap.pop();
        }
        else
        {
            // difference between left - right should not be greater than one
            if (RightMinHeap.size() < LeftMaxHeap.size() - 1)
            {
                RightMinHeap.push(LeftMaxHeap.top());
                LeftMaxHeap.pop();
            }
        }
    }

    void getMedian(vector<double> &temp)
    {
        // Left > Right
        if (LeftMaxHeap.size() > RightMinHeap.size())
        {
            temp.push_back(LeftMaxHeap.top());
        }

        else
        {
            double val = LeftMaxHeap.top() + RightMinHeap.top();
            val /= 2;
            temp.push_back(val);
        }
    }

    vector<double> getMedian(vector<int> &arr)
    {
        vector<double> ans;

        for (int i = 0; i < arr.size(); i++)
        {
            InsertHeap(arr[i]);
            getMedian(ans);
        }

        return ans;
    }
};
