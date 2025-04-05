// Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space.

class Solution
{
public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>> &mat)
    {
        int n = mat.size();

        // Transpose
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // Column wise reverse
        for (int j = 0; j < n; j++)
        {
            int start = 0, end = n - 1;
            while (start < end)
            {
                swap(mat[start][j], mat[end][j]);
                start++;
                end--;
            }
        }
    }
};