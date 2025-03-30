vector<int> searchRange(vector<int> &arr, int x)
{
    int start = 0, end = arr.size() - 1, first = -1, last = -1, mid;

    // Find first occurrence
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] == x)
        {
            first = mid;
            end = mid - 1;
        }

        else if (arr[mid] < x)
        {
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }
    }

    // Find second occurrence
    start = 0, end = arr.size() - 1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] == x)
        {
            last = mid;
            start = mid + 1;
        }

        else if (arr[mid] < x)
        {
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }
    }

    vector<int> a(2);
    a[0] = first;
    a[1] = last;

    return a;
}
