int search(int *arr, int n, int key)
{
    int start = 0, end = n - 1, mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        // Find target
        if (arr[mid] == key)
        {
            return mid;
        }

        // Left side sorted array
        else if (arr[mid] >= arr[0])
        {
            if ((arr[start] <= key) && (arr[mid] > key))
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        // Right side sorted array
        else
        {
            if ((arr[mid] < key) && (arr[end] >= key))
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}