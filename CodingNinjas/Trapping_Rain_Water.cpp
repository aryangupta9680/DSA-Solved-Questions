long long getTrappedWater(long long *arr, int n)
{
    long long leftmax = 0, rightmax = 0, water = 0, index = 0, maxarr = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxarr)
        {
            maxarr = arr[i];
            index = i;
        }
    }

    // Left part
    for (int i = 0; i < index; i++)
    {
        if (leftmax > arr[i])
        {
            water += leftmax - arr[i];
        }
        else
        {
            leftmax = arr[i];
        }
    }

    // Right part
    for (int i = n - 1; i > index; i--)
    {
        if (rightmax > arr[i])
        {
            water += rightmax - arr[i];
        }
        else
        {
            rightmax = arr[i];
        }
    }

    return water;
}