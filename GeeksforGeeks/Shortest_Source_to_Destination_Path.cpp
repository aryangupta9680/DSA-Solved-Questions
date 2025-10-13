// Method 1: Using BFS
// User function Template for C++
class Solution
{
public:
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j, int n, int m)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        if (X == 0 && Y == 0)
        {
            return 0;
        }

        if (!A[0][0])
        {
            return -1;
        }

        // row, col, steps
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        vector<vector<bool>> visited(N, vector<bool>(M, 0));
        visited[0][0] = 1;

        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second.first;
            int step = q.front().second.second;
            q.pop();

            // up down left right
            for (int k = 0; k < 4; k++)
            {
                int new_i = i + row[k];
                int new_j = j + col[k];
                if (valid(new_i, new_j, N, M) && A[new_i][new_j] && !visited[new_i][new_j])
                {
                    if (new_i == X && new_j == Y) // check for the destination
                    {
                        return step + 1;
                    }

                    visited[new_i][new_j] = 1;
                    q.push({new_i, {new_j, step + 1}});
                }
            }
        }

        return -1;
    }
};





// Method 2
// User function Template for C++
class Solution
{
public:
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j, int n, int m)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        if (X == 0 && Y == 0)
        {
            return 0;
        }

        if (!A[0][0])
        {
            return -1;
        }

        // row, col, steps
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        A[0][0] = 0;

        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second.first;
            int step = q.front().second.second;
            q.pop();

            // up down left right
            for (int k = 0; k < 4; k++)
            {
                int new_i = i + row[k];
                int new_j = j + col[k];
                if (valid(new_i, new_j, N, M) && A[new_i][new_j])
                {
                    if (new_i == X && new_j == Y) // check for the destination
                    {
                        return step + 1;
                    }

                    A[new_i][new_j] = 0;
                    q.push({new_i, {new_j, step + 1}});
                }
            }
        }

        return -1;
    }
};





// Method 3
// User function Template for C++
class Solution
{
public:
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j, int n, int m)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        if (X == 0 && Y == 0)
        {
            return 0;
        }

        if (!A[0][0])
        {
            return -1;
        }

        // row, col
        queue<pair<int, int>> q;
        q.push({0, 0});
        A[0][0] = 0;
        int step = 0;

        while (!q.empty())
        {
            int count = q.size();
            while (count--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                // up down left right
                for (int k = 0; k < 4; k++)
                {
                    int new_i = i + row[k];
                    int new_j = j + col[k];
                    if (valid(new_i, new_j, N, M) && A[new_i][new_j])
                    {
                        if (new_i == X && new_j == Y) // check for the destination
                        {
                            return step + 1;
                        }

                        A[new_i][new_j] = 0;
                        q.push({new_i, new_j});
                    }
                }
            }

            step++;
        }

        return -1;
    }
};