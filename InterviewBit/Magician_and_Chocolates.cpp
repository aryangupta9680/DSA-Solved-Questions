int Solution::nchoc(int A, vector<int> &B)
{
    // max heap
    priority_queue<int> p;
    for (int i = 0; i < B.size(); i++)
    {
        p.push(B[i]);
    }

    long long MaxChocolate = 0;
    while (A && (!p.empty()))
    {
        MaxChocolate += p.top();

        if (p.top() / 2)
        {
            p.push(p.top() / 2);
        }

        p.pop();
        A--;
    }

    return MaxChocolate % 1000000007;
}
