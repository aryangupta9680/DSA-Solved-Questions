int missingK(vector<int> vec, int n, int k)
{
    int start = 0, end = n - 1, mid, ans = vec.size();

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (vec[mid] - mid - 1 >= k)
        {
            ans = mid;
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }

    return ans + k;
}
