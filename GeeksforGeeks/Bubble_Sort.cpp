class Solution
{
public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = n - 2; i >= 0; i--)
        {
            bool swapped = 0;
            for (int j = 0; j <= i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    swapped = 1;
                }
            }

            if (swapped == 0)
            {
                break;
            }
        }
    }
};