// Method 1: Using DFS
class Solution
{
public:
    bool DetectCycle(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[node] = 1;

        for (int j = 0; j < adj[node].size(); j++)
        {
            if (parent == adj[node][j])
            {
                continue;
            }

            if (visited[adj[node][j]])
            {
                return true;
            }

            if (DetectCycle(adj[node][j], node, adj, visited))
            {
                return true;
            }
        }

        return 0;
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<bool> visited(V, 0);
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // visit the all unvisited node
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (DetectCycle(i, -1, adj, visited))
                {
                    return true;
                }
            }
        }

        return false;
    }
};





// Method 2: Using BFS
class Solution
{
public:
    bool BFS(int vertex, vector<vector<int>> &adj, vector<bool> &visited)
    {
        queue<pair<int, int>> q;
        visited[vertex] = 1;
        q.push(make_pair(vertex, -1)); // node, parent

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int j = 0; j < adj[node].size(); j++)
            {
                if (parent == adj[node][j])
                {
                    continue;
                }

                if (visited[adj[node][j]])
                {
                    return true;
                }

                visited[adj[node][j]] = 1;
                q.push(make_pair(adj[node][j], node));
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // Method 2: Using BFS
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && BFS(i, adj, visited))
            {
                return true;
            }
        }

        return false;
    }
};
