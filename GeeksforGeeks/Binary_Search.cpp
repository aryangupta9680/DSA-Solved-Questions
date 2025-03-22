class Solution
{
public:
    int binarysearch(vector<int> &arr, int k)
    {
        int n = arr.size();
        int mid, start = 0, end = n - 1, ans = -1;
        while (start <= end)
        {
            // find mid
            mid = start + (end - start) / 2;

            // arr[mid]==k
            if (arr[mid] == k)
            {
                ans = mid;
                end = mid - 1;
            }

            // arr[mid]<k
            else if (arr[mid] < k)
            {
                start = mid + 1;
            }

            // arr[mid]>k
            else
            {
                end = mid - 1;
            }
        }

        return ans;
    }
};