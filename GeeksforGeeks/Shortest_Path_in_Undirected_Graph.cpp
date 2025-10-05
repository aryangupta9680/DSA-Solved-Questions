class Solution
{
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>> &adj, int src)
    {
        int N = adj.size();

        // create distance and visited array
        vector<int> dist(N, -1);
        vector<bool> visited(N, 0);

        queue<int> q;
        q.push(src);
        dist[src] = 0;
        visited[src] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // look at all the neighbours
            for (int j = 0; j < adj[node].size(); j++)
            {
                if (visited[adj[node][j]])
                {
                    continue;
                }

                visited[adj[node][j]] = 1;
                q.push(adj[node][j]);
                dist[adj[node][j]] = dist[node] + 1;
            }
        }

        return dist;
    }
};