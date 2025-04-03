int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    int start = 0, end = 0, mid, ans;
    for (int i = 0; i < n; i++)
    {
        start = max(start, boards[i]);
        end += boards[i];
    }

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        int pages = 0, count = 1;
        for (int i = 0; i < n; i++)
        {
            pages += boards[i];
            if (pages > mid)
            {
                count++;
                pages = boards[i];
            }
        }

        if (count <= k)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}