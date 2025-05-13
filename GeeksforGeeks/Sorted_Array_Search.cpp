class Solution
{
public:
    // Function to find element in sorted array
    // arr: input array
    // k: element to be searched
    bool BinarySearch(vector<int> &arr, int start, int end, int X)
    {
        if (start > end)
        {
            return false;
        }

        int mid = start + (end - start) / 2;

        if (arr[mid] == X)
        {
            return true;
        }

        else if (arr[mid] > X)
        {
            return BinarySearch(arr, start, mid - 1, X);
        }

        else
        {
            return BinarySearch(arr, mid + 1, end, X);
        }
    }

    bool searchInSorted(vector<int> &arr, int k)
    {
        int N = arr.size();
        return BinarySearch(arr, 0, N - 1, k);
    }
};