// Method 1
// User function Template for C++
class Solution
{
public:
    void BST(int arr[], int &index, int lower, int upper, int N)
    {
        if (index == N || arr[index] < lower || arr[index] > upper)
        {
            return;
        }

        int value = arr[index++];
        // left
        BST(arr, index, lower, value, N);
        // Right
        BST(arr, index, value, upper, N);
    }

    int canRepresentBST(int arr[], int N)
    {
        int index = 0;
        BST(arr, index, INT_MIN, INT_MAX, N);
        return index == N;
    }
};




// Method 2
// User function Template for C++
class Solution
{
public:
    int canRepresentBST(int arr[], int N)
    {
        stack<int> lower;
        stack<int> upper;
        lower.push(INT_MIN);
        upper.push(INT_MAX);
        int LowerBound, UpperBound;

        for (int i = 0; i < N; i++)
        {
            if (arr[i] < lower.top())
            {
                return 0;
            }

            while (arr[i] > upper.top())
            {
                upper.pop();
                lower.pop();
            }

            LowerBound = lower.top();
            UpperBound = upper.top();
            upper.pop();
            lower.pop();

            // Right side
            lower.push(arr[i]);
            upper.push(UpperBound);

            // Left side
            lower.push(LowerBound);
            upper.push(arr[i]);
        }

        return 1;
    }
};