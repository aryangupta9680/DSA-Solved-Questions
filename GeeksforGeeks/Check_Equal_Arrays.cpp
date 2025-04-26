class Solution
{
public:
    // Function to check if two arrays are equal or not.
    // Two arrays are said to be equal if both contain the same set of elements, arrangements (or permutations) of elements may be different though.

    bool checkEqual(vector<int> &a, vector<int> &b)
    {
        int sum1 = 0;
        int sum2 = 0;

        for (int i = 0; i < a.size(); i++)
        {
            sum1 += a[i];
        }

        for (int i = 0; i < b.size(); i++)
        {
            sum2 += b[i];
        }

        if (sum1 == sum2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};