// Method 1: Using DFS
class Solution
{
public:
    bool DetectCycle(int node, vector<vector<int>> &adj, vector<bool> &path, vector<bool> &visited)
    {
        visited[node] = 1;
        path[node] = 1;

        // look at adjacent node
        for (int j = 0; j < adj[node].size(); j++)
        {
            // if neighbour node is already present in my path then cycle is present
            if (path[adj[node][j]])
            {
                return 1;
            }

            if (!visited[adj[node][j]] && DetectCycle(adj[node][j], adj, path, visited))
            {
                return 1;
            }
        }

        path[node] = 0;
        return 0;
    }

    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        vector<bool> path(V, 0);
        vector<bool> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && DetectCycle(i, adj, path, visited))
            {
                return 1;
            }
        }

        return 0;
    }
};





// Method 2: Using BFS (Kahn's Algorithm)
class Solution
{
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        vector<int> InDegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                InDegree[adj[i][j]]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (!InDegree[i])
            {
                q.push(i);
            }
        }

        int count = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            for (int j = 0; j < adj[node].size(); j++)
            {
                InDegree[adj[node][j]]--;
                if (!InDegree[adj[node][j]])
                {
                    q.push(adj[node][j]);
                }
            }
        }

        return count != V;
    }
};