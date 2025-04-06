class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int N = matrix.size(), M = matrix[0].size();
        int mid, row_index, col_index, start = 0, end = N * M - 1;

        while (start <= end)
        {
            mid = start + (end - start) / 2;

            row_index = mid / M;
            col_index = mid % M;

            if (matrix[row_index][col_index] == target)
            {
                return true;
            }
            else if (matrix[row_index][col_index] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return false;
    }
};