class Solution
{
public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2)
    {
        // Max heap
        priority_queue<long long> p1;
        priority_queue<long long> p2;

        // insert K1 elements into p1
        for (long long i = 0; i < K1; i++)
        {
            p1.push(A[i]);
        }

        // insert K2-1 elements into p2
        for (long long i = 0; i < K2 - 1; i++)
        {
            p2.push(A[i]);
        }

        // find K1 smallest element in an array
        for (long long i = K1; i < N; i++)
        {
            if (A[i] < p1.top())
            {
                p1.pop();
                p1.push(A[i]);
            }
        }

        // find K2-1 smallest element in an array
        for (long long i = K2 - 1; i < N; i++)
        {
            if (A[i] < p2.top())
            {
                p2.pop();
                p2.push(A[i]);
            }
        }

        // sum of first max heap
        long long sum1 = 0;
        while (!p1.empty())
        {
            sum1 += p1.top();
            p1.pop();
        }

        // sum of second max heap
        long long sum2 = 0;
        while (!p2.empty())
        {
            sum2 += p2.top();
            p2.pop();
        }

        return sum2 - sum1;
    }
};