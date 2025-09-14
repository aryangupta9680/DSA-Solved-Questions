class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj)
    {
        int v = adj.size(); // number of vertices
        queue<int> q;
        vector<bool> visited(v, 0);
        q.push(0);
        visited[0] = 1;
        vector<int> ans;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int j = 0; j < adj[node].size(); j++)
            {
                if (!visited[adj[node][j]])
                {
                    visited[adj[node][j]] = 1;
                    q.push(adj[node][j]);
                }
            }
        }

        return ans;
    }
};