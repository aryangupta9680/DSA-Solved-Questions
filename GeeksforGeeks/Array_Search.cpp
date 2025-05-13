// First Method:
class Solution
{
public:
    // Function to search x in arr
    // arr: input array
    // X: element to be searched for
    int search(vector<int> &arr, int x)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == x)
            {
                return i;
            }
        }

        return -1;
    }
};

// Second Method:
class Solution
{
public:
    // Function to search x in arr
    // arr: input array
    // X: element to be searched for
    int linearsearch(vector<int> &arr, int X, int index, int N)
    {
        // base condition
        if (index == N)
        {
            return -1;
        }

        if (arr[index] == X)
        {
            return index;
        }

        return linearsearch(arr, X, index + 1, N);
    }

    int search(vector<int> &arr, int X)
    {
        int N = arr.size();
        return linearsearch(arr, X, 0, N);
    }
};