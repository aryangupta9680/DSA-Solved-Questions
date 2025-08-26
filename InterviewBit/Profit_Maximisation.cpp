int Solution::solve(vector<int> &A, int B)
{
    int sum = 0;
    priority_queue<int> p; // max heap
    for (int i = 0; i < A.size(); i++)
    {
        p.push(A[i]);
    }

    //  sell the ticket to B people
    while (B && !p.empty())
    {
        sum += p.top();

        if (p.top() - 1)
        {
            p.push(p.top() - 1);
        }

        p.pop();
        B--;
    }

    return sum;
}
