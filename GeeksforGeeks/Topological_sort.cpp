// Method 1: Using DFS
class Solution
{
public:
    void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s)
    {
        visited[node] = 1;

        // look at its neighbour one by one
        for (int j = 0; j < adj[node].size(); j++)
        {
            if (!visited[adj[node][j]])
            {
                DFS(adj[node][j], adj, visited, s);
            }
        }

        s.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // using DFS
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        vector<bool> visited(V, 0);
        stack<int> s;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                DFS(i, adj, visited, s);
            }
        }

        vector<int> ans;
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};