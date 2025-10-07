class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        // data(value), row, col
        vector<pair<int, pair<int, int>>> temp;
        for (int i = 0; i < n; i++)
        {
            temp.push_back(make_pair(matrix[i][0], make_pair(i, 0)));
        }

        // create min heap
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p(temp.begin(), temp.end());

        int ans;
        pair<int, pair<int, int>> element;
        int i, j;

        while (k--)
        {
            element = p.top();
            p.pop();
            ans = element.first;       // value
            i = element.second.first;  // row number
            j = element.second.second; // column number
            if (j + 1 < n)
            {
                p.push(make_pair(matrix[i][j + 1], make_pair(i, j + 1)));
            }
        }

        return ans;
    }
};