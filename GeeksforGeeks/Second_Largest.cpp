// User function template for C++
class Solution
{
public:
    // Function returns the second
    // Largest element
    int getSecondLargest(vector<int> &arr)
    {
        int ans = -1;
        // Largest element
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > ans)
            {
                ans = arr[i];
            }
        }

        // Second Largest element
        int second = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] != ans)
            {
                second = max(arr[i], second);
            }
        }

        return second;
    }
};