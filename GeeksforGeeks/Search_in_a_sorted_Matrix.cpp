class Solution
{
public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x)
    {
        int N = mat.size(), M = mat[0].size();
        int row = 0, col = M - 1;
        while (row < N && col >= 0)
        {
            if (mat[row][col] == x)
            {
                return true;
            }
            else if (mat[row][col] < x)
            {
                row++;
            }
            else
            {
                col--;
            }
        }

        return false;
    }
};