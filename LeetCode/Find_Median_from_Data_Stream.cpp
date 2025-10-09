class MedianFinder
{
public:
    priority_queue<int> LeftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> RightMinHeap;

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

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        InsertHeap(num);
    }

    double findMedian()
    {
        // Left > Right
        if (LeftMaxHeap.size() > RightMinHeap.size())
        {
            return LeftMaxHeap.top();
        }

        else
        {
            double ans = LeftMaxHeap.top() + RightMinHeap.top();
            ans /= 2;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */