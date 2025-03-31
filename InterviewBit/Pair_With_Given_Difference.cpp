int Solution::solve(vector<int> &A, int B)
{
    int n = A.size();
    sort(A.begin(), A.end());
    int start = 0, end = 1;

    if (B < 0)
    {
        B = B * -1;
    }

    while (end < n)
    {
        // Subtraction is equal to B
        if (A[end] - A[start] == B)
        {
            return 1;
        }

        // Subtraction is less than B
        else if (A[end] - A[start] < B)
        {
            end++;
        }

        // Subtraction is greater than B
        else
        {
            start++;
        }

        if (start == end)
        {
            end++;
        }
    }

    return 0;
}
